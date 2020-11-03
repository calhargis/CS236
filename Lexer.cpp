#include "Lexer.h"
#include <string>

using namespace std;

Lexer::Lexer(const std::string &input) {
        this->input = input;
}

void Lexer::addToken(Token token) {
        if (token.getTokenType() != "COMMENT") {
                tokenVector.push_back(token);
        }
}

int Lexer::vectorSize() {
        return tokenVector.size();
}

std::string Lexer::toString() {
        stringstream oss;
        for (size_t i = 0; i < tokenVector.size(); i++) {
                oss << tokenVector[i].toString() << endl;
        }
        return oss.str();
}

std::vector<Token> Lexer::getTokenVector() {
        return tokenVector;
}
