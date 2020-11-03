#ifndef Parser_h
#include <iostream>
#include <vector>
#include <string>
#include "Token.h"
#include "Rule.h"
#include "DatalogProgram.h"

class Parser {
private:

std::vector<Token> tokenVector;

DatalogProgram datalogprogram;

int index;


public:
    Parser(std::vector<Token> parseVector);

    void parse();
    void parseDatalogProgram();
    void parseSchemeList();
    void parseFactList();
    void parseRuleList();
    void parseQueryList();
    Predicate parseScheme();
    Predicate parseFact();
    Rule parseRule();
    Predicate parseQuery();
    Predicate parseHeadPredicate();
    Predicate parsePredicate();
    std::vector<Predicate> parsePredicateList();
    std::vector<Parameter> parseParameterList();
    std::vector<Parameter> parseStringList();
    std::vector<Parameter> parseIDList();
    Parameter parseParameter();
    std::string parseExpression();
    std::string parseOperator();
    DatalogProgram returnDatalogProgram();
};

#endif /* Parser_h */