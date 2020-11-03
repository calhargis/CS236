// #ifndef Predicate_h
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Parameter.h"

class Predicate {
private:
    std::string ID;
    std::vector<Parameter> paramVector;

public:

    void addParameter(Parameter parameter);
    void addParameterVect(std::vector<Parameter> parameterVect);
    void setID(std::string value);

    std::string getID();
    std::string toString();
    std::string returnString();
};

// #endif /* Predicate_h */