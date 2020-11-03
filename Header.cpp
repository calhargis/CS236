#include "Header.h"

std::vector<std::string> Header::returnVector() {
    return this->headerVector;
}

void Header::addHeader(std::string addString) {
    this->headerVector.push_back(addString);
}

std::string Header::toString() const{
    std::stringstream oss;
    for (size_t i = 0; i < headerVector.size(); i++) {
        oss << headerVector.at(i) << " ";
    }
    return oss.str();
}