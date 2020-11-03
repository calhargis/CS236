#include "Parameter.h"

Parameter::Parameter() {}

Parameter::Parameter(std::string value) {
    this->paramValue = value;
}

void Parameter::setValue(std::string value) {
    this->paramValue = value;
}

void Parameter::setType(std::string type) {
    this->type = type;
}

std::string Parameter::getValue() {
    return paramValue;
}