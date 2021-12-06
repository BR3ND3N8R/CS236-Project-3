#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    EOF_TYPE
};

class Token
{
private:
    TokenType type;
    string value;
    int lineNumber;

public:
    Token(TokenType type, std::string description, int line);

    string TokenTypeToString(TokenType type);
    string ToString();

    TokenType GetTokenType();

    string GetData();

};

#endif // TOKEN_H

