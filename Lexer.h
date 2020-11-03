#ifndef Lexer_h
#define Lexer_h
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "Token.h"

using namespace std;

class Lexer {
private:


std::string input;
std::vector<Token> tokenVector;

public:
    Lexer(const std::string &input);

    void addToken(Token token);

    int vectorSize();

    std::string toString();

    std::vector<Token> getTokenVector();

};






#endif /* Lexer_h */