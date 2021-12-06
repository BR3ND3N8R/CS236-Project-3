//
// Created by brend on 12/4/2021.
//

#ifndef PROJECT_1_PARSER_H
#define PROJECT_1_PARSER_H

#include "DatalogProgram.h"
#include "Token.h"

class Parser {
private:
    DatalogProgram parsedProgram;
    vector<Token*> tokens;
    int index;

    //Parameter tempParameter;
    vector<Parameter*> tempParameters;
    //Predicate tempPredicate;
    vector<Predicate*> tempPredicates;
    //Rule tempRule;

    void ParseSchemeList();
    void ParseFactList();
    void ParseRuleList();
    void ParseQueryList();
    void ParseScheme();
    void ParseFact();
    void ParseRule();
    void ParseQuery();
    void ParseHeadPredicate();
    void ParsePredicate();
    void ParsePredicateList();
    void ParseParameterList();
    void ParseStringList();
    void ParseIdList();
    void ParseParameter();
public:
    Parser(vector<Token*> tokens);
    ~Parser();

    Token* Parse();

    DatalogProgram* GetDatalogProgram();
};


#endif //PROJECT_1_PARSER_H
