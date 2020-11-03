#include "DatalogProgram.h"

DatalogProgram::DatalogProgram() {

}

std::string DatalogProgram::toString() {
    std::stringstream oss;

    oss << "Schemes(" << schemeVector.size() << "):" << std::endl;
    for (size_t i = 0; i < schemeVector.size(); i++) {
        oss << "  " << schemeVector[i].toString() << std::endl;
    }

    oss << "Facts(" << factVector.size() << "):" << std::endl;
    for (size_t i = 0; i < factVector.size(); i++) {
        oss << "  " << factVector[i].toString() << "." << std::endl;
    }

    oss << "Rules(" << ruleVector.size() << "):" << std::endl;
    for (size_t i = 0; i < ruleVector.size(); i++) {
        oss << "  " << ruleVector[i].toString() << "." << std::endl;
    }

    oss << "Queries(" << queryVector.size() << "):" << std::endl;
    for (size_t i = 0; i < queryVector.size(); i++) {
        oss << "  " << queryVector[i].toString() << "?" << std::endl;
    }

    oss << "Domain(" << domain.size() << "):" << std::endl;
    for (std::set<std::string>::iterator it = domain.begin(); it != domain.end(); ++it) {
        oss << "  " << *it << std::endl;
    }
    
    return oss.str();
}

void DatalogProgram::addScheme(Predicate scheme) {
    schemeVector.push_back(scheme);
}

void DatalogProgram::addFact(Predicate fact) {
    factVector.push_back(fact);
}

void DatalogProgram::addRule(Rule rule) {
    ruleVector.push_back(rule);
}

void DatalogProgram::addQuery(Predicate query) {
    queryVector.push_back(query);
}

void DatalogProgram::addDomain(std::string domainString) {
    domain.insert(domainString);
}

void DatalogProgram::printContents() {
    std::cout << "Schemes: " << schemeVector.size() << std::endl;
    std::cout << "Fatcs: " << factVector.size() << std::endl;
    std::cout << "Rules: " << ruleVector.size() << std::endl;
    std::cout << "Queries: " << queryVector.size() << std::endl;
}

std::vector<Predicate> DatalogProgram::getSchemes() {
    return schemeVector;
}

std::vector<Predicate> DatalogProgram::getFacts() {
    return factVector;
}

std::vector<Predicate> DatalogProgram::getQueries() {
    return queryVector;
}

std::vector<Rule> DatalogProgram::getRules() {
    return ruleVector;
}