//
// Created by brend on 12/4/2021.
//

#include "Parser.h"

 Parser::Parser(vector<Token*> tokens) {
    this->tokens = tokens;
    index = 0;
}

Parser::~Parser() {
    for (unsigned int i = 0; i < tempParameters.size(); i++) {
        delete tempParameters[i];
    }
    for (unsigned int i = 0; i < tempPredicates.size(); i++) {
        delete tempPredicates[i];
    }
}

// datalogProgram -> /SCHEMES /COLON /scheme /schemeList /FACTS /COLON
// /factList /RULES /COLON /ruleList /QUERIES /COLON /query /queryList /EOF
Token* Parser::Parse() {
    index = 0;
    try {
        if (tokens[index]->GetTokenType() == TokenType::SCHEMES) {
            index++;
        }
        else {
            throw tokens[index];
        }

        if (tokens[index]->GetTokenType() == TokenType::COLON) {
            index++;
            ParseScheme();
            ParseSchemeList();
            /* parsedProgram.schemes = tempPredicates;
            tempPredicates.clear(); */
        }
        else {
            throw tokens[index];
        }

        if (tokens[index]->GetTokenType() == TokenType::FACTS) {
            index++;
        }
        else {
            throw tokens[index];
        }

        if (tokens[index]->GetTokenType() == TokenType::COLON) {
            index++;
            ParseFactList();
            /* parsedProgram.facts = tempPredicates;
            tempPredicates.clear(); */
        }
        else {
            throw tokens[index];
        }

        if (tokens[index]->GetTokenType() == TokenType::RULES) {
            index++;
        }
        else {
            throw tokens[index];
        }

        if (tokens[index]->GetTokenType() == TokenType::COLON) {
            index++;
            ParseRuleList();
        }
        else {
            throw tokens[index];
        }

        if (tokens[index]->GetTokenType() == TokenType::QUERIES) {
            index++;
        }
        else {
            throw tokens[index];
        }

        if (tokens[index]->GetTokenType() == TokenType::COLON) {
            index++;
            ParseQuery();
            ParseQueryList();
            /* parsedProgram.queries = tempPredicates;
            tempPredicates.clear(); */
        }
        else {
            throw tokens[index];
        }

        if (tokens[index]->GetTokenType() != TokenType::EOF_TYPE) {
            throw tokens[index];
        }
    } catch (Token* error) {
        return error; // returns pointer to erroneous token if syntax error is found
    }
    return nullptr; // otherwise, returns nullptr
}

DatalogProgram* Parser::GetDatalogProgram() {
    return &parsedProgram;
}

// schemeList -> scheme schemeList | lambda
void Parser::ParseSchemeList() {
    if (tokens[index]->GetTokenType() == TokenType::ID) {
        ParseScheme();
        ParseSchemeList();
    }
}

// factList -> fact factList | lambda
void Parser::ParseFactList() {
    if (tokens[index]->GetTokenType() == TokenType::ID) {
        ParseFact();
        ParseFactList();
    }
}

// ruleList -> rule ruleList | lambda
void Parser::ParseRuleList() {
    if (tokens[index]->GetTokenType() == TokenType::ID) {
        ParseRule();
        ParseRuleList();
    }
}

// queryList -> query queryList | lambda
void Parser::ParseQueryList() {
    if (tokens[index]->GetTokenType() == TokenType::ID) {
        ParseQuery();
        ParseQueryList();
    }
}

// scheme -> ID LEFT_PAREN ID idList RIGHT_PAREN
void Parser::ParseScheme() {
    Predicate* tempPredicate = new Predicate;
    if (tokens[index]->GetTokenType() == TokenType::ID) {
        tempPredicate->id = tokens[index]->GetData();
        index++;
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }

    if (tokens[index]->GetTokenType() == TokenType::LEFT_PAREN) {
        index++;
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }

    if (tokens[index]->GetTokenType() == TokenType::ID) {
        tempParameters.push_back(new Parameter(tokens[index]->GetData()));
        index++;
        ParseIdList();
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }

    if (tokens[index]->GetTokenType() == TokenType::RIGHT_PAREN) {
        tempPredicate->parameters = tempParameters;
        tempParameters.clear();
        parsedProgram.schemes.push_back(tempPredicate);
        index++;
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }
}

// fact -> ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
void Parser::ParseFact() {
    Predicate* tempPredicate = new Predicate;
    if (tokens[index]->GetTokenType() == TokenType::ID) {
        tempPredicate->id = tokens[index]->GetData();
        index++;
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }

    if (tokens[index]->GetTokenType() == TokenType::LEFT_PAREN) {
        index++;
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }

    if (tokens[index]->GetTokenType() == TokenType::STRING) {
        tempParameters.push_back(new Parameter(tokens[index]->GetData()));
        index++;
        ParseStringList();
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }

    if (tokens[index]->GetTokenType() == TokenType::RIGHT_PAREN) {
        index++;
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }

    if (tokens[index]->GetTokenType() == TokenType::PERIOD) {
        tempPredicate->parameters = tempParameters;
        tempParameters.clear();
        parsedProgram.facts.push_back(tempPredicate);
        index++;
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }
}

// rule -> headPredicate COLON_DASH predicate predicateList PERIOD
void Parser::ParseRule() {
    ParseHeadPredicate();
    Rule* tempRule = new Rule;
    tempRule->headPredicate = tempPredicates[0];
    tempPredicates.clear();
    /* Predicate* predicatePtr = new Predicate;
    predicatePtr->parameters = tempPredicate.parameters;
    predicatePtr->id = tempPredicate.id;
    tempRule.headPredicate = predicatePtr;
    tempPredicate.parameters.clear(); */
    if (tokens[index]->GetTokenType() == TokenType::COLON_DASH) {
        index++;
        ParsePredicate();
        ParsePredicateList();
    }
    else {
        delete tempRule;
        throw tokens[index];
    }

    if (tokens[index]->GetTokenType() == TokenType::PERIOD) {
        tempRule->bodyPredicates = tempPredicates;
        tempPredicates.clear();
        parsedProgram.rules.push_back(tempRule);
        index++;
    }
    else {
        delete tempRule;
        throw tokens[index];
    }
}

// query -> predicate Q_MARK---------------------------I AM HERE vv
void Parser::ParseQuery() {
    ParsePredicate();
    if (tokens[index]->GetTokenType() == TokenType::Q_MARK) {
        /* Predicate* predicatePtr = new Predicate;
        predicatePtr->parameters = tempPredicate.parameters;
        predicatePtr->id = tempPredicate.id;
        tempPredicates.push_back(predicatePtr);
        tempPredicate.parameters.clear(); */
        parsedProgram.queries.push_back(tempPredicates[0]);
        tempPredicates.clear();
        index++;
    }
    else {
        throw tokens[index];
    }
}

// headPredicate -> ID LEFT_PAREN ID idList RIGHT_PAREN
void Parser::ParseHeadPredicate() {
    Predicate* tempPredicate = new Predicate;
    if (tokens[index]->GetTokenType() == TokenType::ID) {
        tempPredicate->id = tokens[index]->GetData();
        index++;
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }

    if (tokens[index]->GetTokenType() == TokenType::LEFT_PAREN) {
        index++;
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }

    if (tokens[index]->GetTokenType() == TokenType::ID) {
        tempParameters.push_back(new Parameter(tokens[index]->GetData()));
        index++;
        ParseIdList();
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }

    if (tokens[index]->GetTokenType() == TokenType::RIGHT_PAREN) {
        tempPredicate->parameters = tempParameters;
        tempParameters.clear();
        tempPredicates.push_back(tempPredicate);
        index++;
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }
}

// predicate -> ID LEFT_PAREN parameter parameterList RIGHT_PAREN
void Parser::ParsePredicate() {
    Predicate* tempPredicate = new Predicate;
    if (tokens[index]->GetTokenType() == TokenType::ID) {
        tempPredicate->id = tokens[index]->GetData();
        index++;
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }

    if (tokens[index]->GetTokenType() == TokenType::LEFT_PAREN) {
        index++;
        ParseParameter();
        ParseParameterList();
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }

    if (tokens[index]->GetTokenType() == TokenType::RIGHT_PAREN) {
        tempPredicate->parameters = tempParameters;
        tempParameters.clear();
        tempPredicates.push_back(tempPredicate);
        index++;
    }
    else {
        delete tempPredicate;
        throw tokens[index];
    }
}

// predicateList -> COMMA predicate predicateList | lambda
void Parser::ParsePredicateList() {
    if (tokens[index]->GetTokenType() == TokenType::COMMA) {
        index++;
        ParsePredicate();
        ParsePredicateList();
    }
}

// parameterList -> COMMA parameter parameterList | lambda
void Parser::ParseParameterList() {
    if (tokens[index]->GetTokenType() == TokenType::COMMA) {
        index++;
        ParseParameter();
        ParseParameterList();
    }
}

// stringList -> COMMA STRING stringList | lambda
void Parser::ParseStringList() {
    if (tokens[index]->GetTokenType() == TokenType::COMMA) {
        index++;
    }
    if (tokens[index]->GetTokenType() == TokenType::STRING) {
        tempParameters.push_back(new Parameter(tokens[index]->GetData()));
        index++;
        ParseStringList();
    }
}

// idList -> COMMA ID idList | lambda
void Parser::ParseIdList() {
    if (tokens[index]->GetTokenType() == TokenType::COMMA) {
        index++;
    }
    if (tokens[index]->GetTokenType() == TokenType::ID) {
        tempParameters.push_back(new Parameter(tokens[index]->GetData()));
        index++;
        ParseIdList();
    }
}

// parameter -> STRING | ID
void Parser::ParseParameter() {
    if (tokens[index]->GetTokenType() == TokenType::STRING) {
        tempParameters.push_back(new Parameter(tokens[index]->GetData()));
        index++;
    }
    else if (tokens[index]->GetTokenType() == TokenType::ID) {
        tempParameters.push_back(new Parameter(tokens[index]->GetData()));
        index++;
    }
    else {
        throw tokens[index];
    }
}