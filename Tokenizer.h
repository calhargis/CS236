#ifndef Tokenizer_h
#define Tokenizer_h
#include <stdio.h>
#include <string>
#include "Token.h"

class Tokenizer {

    std::string input;
    tokenType typeToken;

public:

    Tokenizer(const std::string &input);
    std::string tokenToString(char tokenString);
    Token tokenCreator(size_t tokenIndex);
    void getNextToken();
};

#endif /* Tokenizer_h */
