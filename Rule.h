// #ifndef Rule_h
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Predicate.h"


class Rule {
private:
    Predicate predicate;
    std::vector<Predicate> predicateVect;

public:
    Rule();
    Rule(Predicate predicate);
    void addPredicate(Predicate predicate);
    void addPredicateVect(std::vector<Predicate> predicateVect);
    std::string toString();
};

// #endif /* Rule_h */