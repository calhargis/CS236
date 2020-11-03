#include "Parser.h"

Parser::Parser(std::vector<Token> tokenVector) {
    this->tokenVector = tokenVector;
    this->index = 0;
}

void Parser::parse() {
    try {
        parseDatalogProgram();
    }
    catch(Token exception) {
        exception = tokenVector[index];
        std::cout << "Failure!" << std::endl;
        std::cout << "  " << exception.toString() << std::endl;
    }    
}

void Parser::parseDatalogProgram() {
    Token exception;
    if (tokenVector[index].getTokenType() == "SCHEMES") {
        ++index;
    }
    else {
        throw exception;
    }
    if (tokenVector[index].getTokenType() == "COLON") {
        ++index;
    }
    else {
        throw exception;
    }
    datalogprogram.addScheme(parseScheme());
    parseSchemeList();

    if (tokenVector[index].getTokenType() == "FACTS") {
        ++index;
    }
    else {
        throw exception;
    }
    if (tokenVector[index].getTokenType() == "COLON") {
        ++index;
    }
    else {
        throw exception;
    }

    parseFactList();

    if (tokenVector[index].getTokenType() == "RULES") {
        ++index;
    }
    else {
        throw exception;
    }

    if (tokenVector[index].getTokenType() == "COLON") {
        ++index;
    }
    else {
        throw exception;
    }

    parseRuleList();

    if (tokenVector[index].getTokenType() == "QUERIES") {
        ++index;
    }
    else {
        throw exception;
    }

    if (tokenVector[index].getTokenType() == "COLON") {
        ++index;
    }
    else {
        throw exception;
    }

    datalogprogram.addQuery(parseQuery());
    parseQueryList();

    if (tokenVector[index].getTokenType() == "EOF") {
        ++index;
    }
    else {
        throw exception;
    }
    std::cout << "Success!" << std::endl;
    // std::cout << datalogprogram.toString();
}

void Parser::parseSchemeList() {
    if (tokenVector[index].getTokenType() == "FACTS" ) {
        return;
    }

    datalogprogram.addScheme(parseScheme());
    parseSchemeList();
}

void Parser::parseFactList() {
    if (tokenVector[index].getTokenType() == "RULES") {
        return;
    }
    datalogprogram.addFact(parseFact());
    parseFactList();
}

void Parser::parseRuleList() {
    if (tokenVector[index].getTokenType() == "QUERIES") {
        return;
    }
    datalogprogram.addRule(parseRule());
    parseRuleList();

}

void Parser::parseQueryList() {
if (tokenVector[index].getTokenType() == "EOF") {
        return;
}
    datalogprogram.addQuery(parseQuery());
    parseQueryList();

}

Predicate Parser::parseScheme() {
    Predicate scheme;
    Token exception;

    if (tokenVector[index].getTokenType() == "ID") {
        scheme.setID(tokenVector[index].getTokenVal());
        ++index;
    }
    else {
        throw exception;
    }

    if (tokenVector[index].getTokenType() == "LEFT_PAREN") {
        ++index;
    }
    else {
        throw exception;
    }

    if (tokenVector[index].getTokenType() == "ID") {
        Parameter parameter(tokenVector[index].getTokenVal());
        scheme.addParameter(parameter);
        ++index;
    }
    else {
        throw exception;
    }

    {   
        std::vector<Parameter> parameterVect;
        std::vector<Parameter> tempVect;
        tempVect = parseIDList();
        parameterVect.insert(parameterVect.end(), tempVect.begin(), tempVect.end());
        scheme.addParameterVect(parameterVect);
    }

    if (tokenVector[index].getTokenType() == "RIGHT_PAREN") {
        ++index;
    }
    else {
        throw exception;
    }
    
    return scheme;
}

Predicate Parser::parseFact() {
    Token exception;
    Predicate fact;

    if (tokenVector[index].getTokenType() == "ID") {
        fact.setID(tokenVector[index].getTokenVal());
        ++index;
    }
    else {
        throw exception;
    }
    if (tokenVector[index].getTokenType() == "LEFT_PAREN") {
        ++index;
    }
    else {
        throw exception;
    }
    if (tokenVector[index].getTokenType() == "STRING") {
        datalogprogram.addDomain(tokenVector[index].getTokenVal());
        Parameter parameter(tokenVector[index].getTokenVal());
        fact.addParameter(parameter);
        ++index;
    }
    else {
        throw exception;
    }

    {   
        std::vector<Parameter> parameterVect;
        std::vector<Parameter> tempVect;
        tempVect = parseStringList();
        parameterVect.insert(parameterVect.end(), tempVect.begin(), tempVect.end());
        fact.addParameterVect(parameterVect);
    }

    if (tokenVector[index].getTokenType() == "RIGHT_PAREN") {
        ++index;
    }
    else {
        throw exception;
    }
    if (tokenVector[index].getTokenType() == "PERIOD") {
        ++index;
    }
    else {
        throw exception;
    }
    return fact;
}

Rule Parser::parseRule() {
    Token exception;
    Rule rule(parseHeadPredicate());

    if (tokenVector[index].getTokenType() == "COLON_DASH") {
        ++index;
    }
    else {
        throw exception;
    }
    rule.addPredicate(parsePredicate());
    rule.addPredicateVect(parsePredicateList());

    if (tokenVector[index].getTokenType() == "PERIOD") {
        ++index;
    }
    else {
        throw exception;
    }
    return rule;
}

Predicate Parser::parseQuery() {
    Token exception;
    Predicate query;

    query = parsePredicate();

    if (tokenVector[index].getTokenType() == "Q_MARK") {
        ++index;
    }
    else {
        throw exception;
    }
    return query;
}

Predicate Parser::parseHeadPredicate() {
    Token exception;
    Predicate predicate;

    if (tokenVector[index].getTokenType() == "ID") {
        predicate.setID(tokenVector[index].getTokenVal());
        ++index;
    }
    else {
        throw exception;
    }

    if (tokenVector[index].getTokenType() == "LEFT_PAREN") {
        ++index;
    }
    else {
        throw exception;
    }

    if (tokenVector[index].getTokenType() == "ID") {
        Parameter parameter(tokenVector[index].getTokenVal());
        predicate.addParameter(parameter);
        ++index;
    }
    else {
        throw exception;
    }
    {   
        std::vector<Parameter> parameterVect;
        std::vector<Parameter> tempVect;
        tempVect = parseIDList();
        parameterVect.insert(parameterVect.end(), tempVect.begin(), tempVect.end());
        predicate.addParameterVect(parameterVect);
    }

    if (tokenVector[index].getTokenType() == "RIGHT_PAREN") {
        ++index;
    }
    else {
        throw exception;
    }
    return predicate;
}

Predicate Parser::parsePredicate() {
    Predicate predicate;
    Token exception;

    if (tokenVector[index].getTokenType() == "ID") {
        predicate.setID(tokenVector[index].getTokenVal());
        ++index;
    }
    else {
        throw exception;
    }
    if (tokenVector[index].getTokenType() == "LEFT_PAREN") {
        ++index;
    }
    else {
        throw exception;
    }

    predicate.addParameter(parseParameter());
    predicate.addParameterVect(parseParameterList());

    if (tokenVector[index].getTokenType() == "RIGHT_PAREN") {
        ++index;
    }
    else {
        throw exception;
    }
    return predicate;
}

std::vector<Predicate> Parser::parsePredicateList() {
    Token exception;
    std::vector<Predicate> predicateVect;
    Predicate predicate;

    if (tokenVector[index].getTokenType() == "PERIOD") {
        return predicateVect;
    }

    if (tokenVector[index].getTokenType() == "COMMA") {
        ++index;
    }
    predicate = parsePredicate();
    predicateVect.push_back(predicate);

    std::vector<Predicate> tempVect;
    tempVect = parsePredicateList();
    predicateVect.insert(predicateVect.end(), tempVect.begin(), tempVect.end());

    return predicateVect;
}

std::vector<Parameter> Parser::parseParameterList() {
    Token exception;
    std::vector<Parameter> parameterVect;
    Parameter parameter;

    if (tokenVector[index].getTokenType() == "RIGHT_PAREN") {
        return parameterVect;
    }

    if (tokenVector[index].getTokenType() == "COMMA") {
        ++index;
    }

    parameter = parseParameter();
    parameterVect.push_back(parameter);

    std::vector<Parameter> tempVect;
    tempVect = parseParameterList();
    parameterVect.insert(parameterVect.end(), tempVect.begin(), tempVect.end());

    return parameterVect;

}

std::vector<Parameter> Parser::parseStringList() {
    Token exception;
    std::vector<Parameter> parameterVect;

    if (tokenVector[index].getTokenType() == "RIGHT_PAREN") {
        return parameterVect;
    }

    if (tokenVector[index].getTokenType() == "COMMA") {
        ++index;
    }

    if (tokenVector[index].getTokenType() == "STRING") {
        datalogprogram.addDomain(tokenVector[index].getTokenVal());
        Parameter parameter(tokenVector[index].getTokenVal());
        parameterVect.push_back(parameter);
        ++index;
        std::vector<Parameter> tempVect;
        tempVect = parseStringList();
        parameterVect.insert(parameterVect.end(), tempVect.begin(), tempVect.end());
    }
    else {
        throw exception;
    }
    

    return parameterVect;
}

std::vector<Parameter> Parser::parseIDList() {
    Token exception;
    std::vector<Parameter> parameterVect;

    if (tokenVector[index].getTokenType() == "RIGHT_PAREN") {
        return parameterVect;
    }
    else if (tokenVector[index].getTokenType() == "COMMA") {
        ++index;
    }

    if (tokenVector[index].getTokenType() == "ID") {
        Parameter parameter(tokenVector[index].getTokenVal());
        parameterVect.push_back(parameter);
        ++index;
        std::vector<Parameter> tempVect;
        tempVect = parseIDList();
        parameterVect.insert(parameterVect.end(), tempVect.begin(), tempVect.end());
    }
    return parameterVect;
}

Parameter Parser::parseParameter() {
    Parameter parameter;
    Token exception;

    if (tokenVector[index].getTokenType() == "STRING") {
        parameter.setValue(tokenVector[index].getTokenVal());
        ++index;
    }
    else if (tokenVector[index].getTokenType() == "ID") {
        parameter.setValue(tokenVector[index].getTokenVal());
        ++index;
    }
    else if (tokenVector[index].getTokenType() == "LEFT_PAREN") {
        parameter.setValue(parseExpression());
    }
    else {
        throw exception;
    }

    return parameter;
}

std::string Parser::parseExpression() {
    Token exception;
    std::string exprString = "";

    if (tokenVector[index].getTokenType() == "LEFT_PAREN") {
        exprString += tokenVector[index].getTokenVal();
        ++index;
    }
    else {
        throw exception;
    }

    exprString += parseParameter().getValue();
    exprString += parseOperator();
    exprString += parseParameter().getValue();

    if (tokenVector[index].getTokenType() == "RIGHT_PAREN") {
        exprString += tokenVector[index].getTokenVal();
        ++index;
    }
    else {
        throw exception;
    }

    return exprString;
}

std::string Parser::parseOperator() {
    Token exception;

    if (tokenVector[index].getTokenType() == "ADD") {
        ++index;
        return "+";
    }
    else if (tokenVector[index].getTokenType() == "MULTIPLY") {
        ++index;
        return "*";
    }
    else {
        throw exception;
    }

}

DatalogProgram Parser::returnDatalogProgram() {
    return this->datalogprogram;
}