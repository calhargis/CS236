#ifndef Token_h
#define Token_h
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

enum tokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, UNDEFINED, ENDFILE};

class Token {
    std::string tokenVal;
    int tokenLine;
    tokenType type;


public:

    Token(tokenType type = UNDEFINED, const std::string &tokenVal = "", int tokenLine = 0);

    std::string tokenToString(tokenType T);
            
    std::string enumToString(tokenType T);

    std::string toString();

    void setTokenType(tokenType type);

    void setTokenLine(int tokenLine);

    void setTokenVal(std::string tokenVal);

    std::string getTokenVal();

    std::string getTokenType();

};

#endif /* Token_h */
