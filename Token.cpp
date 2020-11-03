    #include "Token.h"
    #include <sstream>

    Token::Token(tokenType type, const std::string &tokenVal, int tokenLine) {
        this->tokenVal = tokenVal;
        this->tokenLine = tokenLine;
        this->type = type;
    }
    
    void Token::setTokenType(tokenType type) {
        this->type = type;
    }

    void Token::setTokenLine(int tokenLine) {
        this->tokenLine = tokenLine;
    }

    void Token::setTokenVal(std::string tokenVal) {
        this->tokenVal = tokenVal;
    }

    std::string Token::getTokenVal() {
        return tokenVal;
    }

    std::string Token::getTokenType() {
        return enumToString(type);
    }

    std::string Token::toString() {
        std::stringstream oss;
        oss << "(" << enumToString(type) << ",\"" << tokenVal << "\"," << tokenLine << ")";
        return oss.str();
    }

    std::string Token::enumToString(tokenType T) {
    switch (T) {
        case COMMA:
            return "COMMA";
            break;
        case PERIOD:
            return "PERIOD";
            break;
        case Q_MARK:
            return "Q_MARK";
            break;
        case LEFT_PAREN:
            return "LEFT_PAREN";
            break;
        case RIGHT_PAREN:
            return "RIGHT_PAREN";
            break;
        case COLON:
            return "COLON";
            break;
        case COLON_DASH:
            return "COLON_DASH";
            break;
        case MULTIPLY:
            return "MULTIPLY";
            break;
        case ADD:
            return "ADD";
            break;
        case SCHEMES:
            return "SCHEMES";
            break;
        case FACTS:
            return "FACTS";
            break;
        case RULES:
            return "RULES";
            break;
        case QUERIES:
            return "QUERIES";
            break;
        case ID:
            return "ID";
            break;
        case STRING:
            return "STRING";
            break;
        case COMMENT:
            return "COMMENT";
            break;
        case UNDEFINED:
            return "UNDEFINED";
            break;
        case ENDFILE:
            return "EOF";
            break;
        default:
            return "";
    }
}