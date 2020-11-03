#include "Database.h"

void Database::setName(std::string name) {
    this->name = name;
}

void Database::addRelation(Relation relation) {
    relationMap[relation.getName()] = relation;
}

Relation Database::findRelation(std::string predId) {
    return relationMap[predId];
}

std::string Database::toString() {
    std::stringstream oss;
    for (std::map<std::string, Relation>::const_iterator it = relationMap.begin(); it != relationMap.end(); ++it) {
        oss << it->first << " " << it->second.toString();
    }
    return oss.str();
}