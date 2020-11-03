// #ifndef DatalogProgram_h
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include "Predicate.h"
#include "Rule.h"

class DatalogProgram {
private:

std::vector<Predicate> schemeVector;
std::vector<Predicate> factVector;
std::vector<Predicate> queryVector;
std::vector<Rule> ruleVector;

std::set<std::string> domain;


public:

DatalogProgram();

void addScheme(Predicate scheme);
void addFact(Predicate fact);
void addQuery(Predicate query);
void addRule(Rule rule);
std::string toString();
void addDomain(std::string domainString);

std::vector<Predicate> getSchemes();
std::vector<Predicate> getFacts();
std::vector<Predicate> getQueries();
std::vector<Rule> getRules();

void printContents();


    

};

// #endif /* DatalogProgram_h */