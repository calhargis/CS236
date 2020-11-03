#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include "Header.h"
#include "Tuple.h"
#include "Predicate.h"

class Relation {
    std::string name;
    Header header;
    std::set<Tuple> tupleSet;

public:

    Relation();
    Relation(std::string name);
    // Relation(std::string name, Header header);
    // Relation(std::string name, Predicate predicate);

    void addHeader(Predicate pred);
    void addTuple(Tuple tuple);
    void addPredAsTuple(Predicate pred);
    void addName(std::string name);
    std::string getName();
    // select relation classes all
    // select
    // project
    // rename
    // Relation* select();

    std::string toString()const;


};