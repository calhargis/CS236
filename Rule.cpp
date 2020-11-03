#include "Rule.h"
#include <sstream>

Rule::Rule() {}

Rule::Rule(Predicate predicate) {
    this->predicate = predicate;
}

void Rule::addPredicate(Predicate predicate) {
    predicateVect.push_back(predicate);
}

void Rule::addPredicateVect(std::vector<Predicate> predVect) {
    predicateVect.insert(predicateVect.end(), predVect.begin(), predVect.end());
}

std::string Rule::toString() {
    std::stringstream oss;

    oss << predicate.toString() << " :- ";

    for (size_t i = 0; i < predicateVect.size(); i++) {
        oss << predicateVect[i].toString();
        if (i != predicateVect.size() - 1) {
            oss << ",";
        }
    }
    return oss.str();
}