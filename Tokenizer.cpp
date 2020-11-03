#include "Tokenizer.h"

Tokenizer::Tokenizer(const std::string &input) {
    this->input = input;
}

std::string Tokenizer::tokenToString(char tokenString) {
    return "";
}

Token Tokenizer::tokenCreator(size_t tokenIndex) {
    Token newToken;
    if (input[tokenIndex] == EOF) {
        newToken.setTokenType(ENDFILE);
        newToken.setTokenVal("");
    }
    else if (input[tokenIndex] == '.') {
        newToken.setTokenType(PERIOD);
        newToken.setTokenVal(".");
    }
    else if (input[tokenIndex] == ',') {
        newToken.setTokenType(COMMA);
        newToken.setTokenVal(",");
    }
    else if (input[tokenIndex] == '?') {
        newToken.setTokenType(Q_MARK);
        newToken.setTokenVal("?");
    }
    else if (input[tokenIndex] == '(') {
        newToken.setTokenType(LEFT_PAREN);
        newToken.setTokenVal("(");
    }
    else if (input[tokenIndex] == ')') {
        newToken.setTokenType(RIGHT_PAREN);
        newToken.setTokenVal(")");
    }
    else if (input[tokenIndex] == ':') {
        if (input[tokenIndex + 1] == '-') {
            newToken.setTokenType(COLON_DASH);
            newToken.setTokenVal(":-");
        }
        else {
            newToken.setTokenType(COLON);
            newToken.setTokenVal(":");
        }
    }
    else if (input[tokenIndex] == '*') {
        newToken.setTokenType(MULTIPLY);
        newToken.setTokenVal("*");
    }
    else if (input[tokenIndex] == '+') {
        newToken.setTokenType(ADD);
        newToken.setTokenVal("+");
    }

    
    else if (input[tokenIndex] == '#') {
        size_t endIndex = tokenIndex + 1;
        std::string stringVal = "";

        if (tokenIndex + 1 > input.size() - 1) {
            newToken.setTokenType(UNDEFINED);
            newToken.setTokenVal("#");
            return newToken;
        }
        if (input[tokenIndex + 1] == '|') {
            endIndex = tokenIndex + 2;
            while (1) {
                if(endIndex + 1 > input.size() - 1) {
                    newToken.setTokenType(UNDEFINED);
                    newToken.setTokenVal(input.substr(tokenIndex, (endIndex - tokenIndex) + 1));
                    return newToken;
                }
                if (input[endIndex] == '|' && input[endIndex + 1] == '#') {
                    endIndex += 2;
                    break;
                }
                else {
                    ++endIndex;
                }
            }
        }
        else {
            while (1) {
                if (endIndex > input.size() - 1 || input[endIndex] == '\n') {
                    break;
                }
                ++endIndex;
            }
        }
        stringVal = input.substr(tokenIndex, (endIndex - tokenIndex));
        newToken.setTokenType(COMMENT);
        newToken.setTokenVal(stringVal);
    }

    else if (input[tokenIndex] == '\'') {
        std::string tokenString = "";
        if (tokenIndex + 1 > input.size() - 1) {
            newToken.setTokenType(UNDEFINED);
            newToken.setTokenVal("\'");
        }
        size_t endIndex = tokenIndex + 1;
        while (1) {
            if (endIndex > input.size() - 1) {
                newToken.setTokenType(UNDEFINED);
                newToken.setTokenVal(input.substr(tokenIndex, (endIndex - tokenIndex)));
                return newToken;
            }

            if (input[endIndex] == '\'') {
                if (input[endIndex + 1] == '\'') {
                    endIndex += 2;
                }
                else {
                    ++endIndex;
                    break;
                }
            }
            else {
            ++endIndex;
            }
        }
        
        tokenString = input.substr(tokenIndex, (endIndex - tokenIndex));
        newToken.setTokenType(STRING);
        newToken.setTokenVal(tokenString);
    }

    else if (isalpha(input[tokenIndex])) {
        if (tokenIndex + 1 > input.size() - 1) {
            std::string charString(1, input[tokenIndex]);
            newToken.setTokenType(ID);
            newToken.setTokenVal(charString);
            return newToken;
        }
        size_t endIndex = tokenIndex + 1;
        while (isalnum(input[endIndex])) {
            if (isspace(input[tokenIndex])) {
                break;
            }
            ++endIndex;
        }
        if (input.substr(tokenIndex, (endIndex - tokenIndex)) == "Schemes") {
            newToken.setTokenType(SCHEMES);
            newToken.setTokenVal(input.substr(tokenIndex, (endIndex - tokenIndex)));
            return newToken;
        }
        else if (input.substr(tokenIndex, (endIndex - tokenIndex)) == "Facts") {
            newToken.setTokenType(FACTS);
            newToken.setTokenVal(input.substr(tokenIndex, (endIndex - tokenIndex)));
            return newToken;
        }
        else if (input.substr(tokenIndex, (endIndex - tokenIndex)) == "Rules") {
            newToken.setTokenType(RULES);
            newToken.setTokenVal(input.substr(tokenIndex, (endIndex - tokenIndex)));
            return newToken;
        }
        else if (input.substr(tokenIndex, (endIndex - tokenIndex)) == "Queries") {
            newToken.setTokenType(QUERIES);
            newToken.setTokenVal(input.substr(tokenIndex, (endIndex - tokenIndex)));
            return newToken;
        }
        newToken.setTokenType(ID);
        newToken.setTokenVal(input.substr(tokenIndex, (endIndex - tokenIndex)));
    }

    else {
        newToken.setTokenType(UNDEFINED);
        std::string charToString(1, input[tokenIndex]);
        newToken.setTokenVal(charToString);
    }
    return newToken;

}