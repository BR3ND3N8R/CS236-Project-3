#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    this->type = type;
    value = description;
    lineNumber = line;
}

string Token::TokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::COLON:
            return "COLON";
        case TokenType::COLON_DASH:
            return "COLON_DASH";
        case TokenType::COMMA:
            return "COMMA";
        case TokenType::PERIOD:
            return "PERIOD";
        case TokenType::Q_MARK:
            return "Q_MARK";
        case TokenType::LEFT_PAREN:
            return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN:
            return "RIGHT_PAREN";
        case TokenType::MULTIPLY:
            return "MULTIPLY";
        case TokenType::ADD:
            return "ADD";
        case TokenType::SCHEMES:
            return "SCHEMES";
        case TokenType::FACTS:
            return "FACTS";
        case TokenType::RULES:
            return "RULES";
        case TokenType::QUERIES:
            return "QUERIES";
        case TokenType::ID:
            return "ID";
        case TokenType::STRING:
            return "STRING";
        case TokenType::COMMENT:
            return "COMMENT";
        case TokenType::UNDEFINED:
            return "UNDEFINED";
        case TokenType::EOF_TYPE:
            return "EOF";
        default:
            return "Unable to find token type";
    }
}

string Token::ToString() {
    stringstream buffer;
    buffer << "(" << TokenTypeToString(type) << ",\"" << value << "\"," << lineNumber << ")";
    string returnString = buffer.str();
    return returnString;
}

TokenType Token::GetTokenType() {
    return type;
}

string Token::GetData() {
    return value;
}
