#include "Relation.h"

Relation::Relation () {};

// Relation::Relation(std::string name, Header header) {
//     this->name = name;
//     this->header = header;
// }

Relation::Relation(std::string name) {
    this->name = name;
}

// Relation::Relation(std::string name, Predicate predicate) {
//     Tuple tuple;
//     tuple.push_back(predicate.returnString());
//     tupleSet.insert(tuple);
//     this->name = name;
// }

void Relation::addHeader(Predicate pred) {
    this->header.addHeader(pred.returnString());
}

void Relation::addTuple(Tuple tuple) {
    tupleSet.insert(tuple);
}

void Relation::addPredAsTuple(Predicate pred) {
    Tuple tup;
    tup.push_back(pred.returnString());
    tupleSet.insert(tup);
}

std::string Relation::getName() {
    return this->name;
}

void Relation::addName(std::string name) {
    this->name = name;
}

std::string Relation::toString() const{
    std::stringstream oss;

    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Header" << this->header.toString();
    std::cout << "Tuples: " << std::endl;
    for (std::set<Tuple>::iterator it = tupleSet.begin(); it != tupleSet.end(); ++it) {
        std::vector<std::string> tuple = *it;
        for (unsigned int i = 0; i < tuple.size(); i++) {
            oss << " " << tuple[i];
        }
        oss << std::endl;
    }

    return oss.str();
}

// Relation* Relation::select() {
//     Relation* rel = ;

//     return rel;
// }