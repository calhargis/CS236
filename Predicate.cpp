#include "Predicate.h"
#include <sstream>

void Predicate::addParameter(Parameter parameter) {
    this->paramVector.push_back(parameter);
}

void Predicate::addParameterVect(std::vector<Parameter> parameterVect) {
    this->paramVector.insert(paramVector.end(), parameterVect.begin(), parameterVect.end());
}

void Predicate::setID(std::string value) {
    this->ID = value;
}

std::string Predicate::getID() {
    return this->ID;
}

std::string Predicate::toString() {
    std::stringstream oss;

    oss << this->ID << "(";

    for (size_t i = 0; i < paramVector.size(); i++) {
        oss << paramVector[i].getValue();
        if (i != paramVector.size() - 1) {
            oss << ",";
        }
    }
    oss << ")";
    

    return oss.str();
}

std::string Predicate::returnString() {
    std::string returnString;
    for (size_t i = 0; i < paramVector.size(); i++) {
        returnString += paramVector[i].getValue();
    }
    return returnString;
}