#include <iostream>
#include <map>
#include "Relation.h"

class Database {

// store relation

// map string to relation
std::map<std::string, Relation> relationMap;

std::string name;


public:

void setName(std::string name);
void addRelation(Relation relation);
Relation findRelation(std::string predId);
std::string toString();


};