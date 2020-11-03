#include "Interpreter.h"

Interpreter::Interpreter(DatalogProgram datalogprogram) {
    this->datalogprogram = datalogprogram;
}

void Interpreter::run() {

// Schemes
// std::cout << "Schemes:" << std::endl;
    for (unsigned int i = 0; i < datalogprogram.getSchemes().size(); i++) {
        std::string relName = datalogprogram.getSchemes()[i].getID();
        Relation newRelation(relName);
        newRelation.addHeader(datalogprogram.getSchemes()[i]);
        database.addRelation(newRelation);
        // std::cout << newRelation.toString() << "," << std::endl;
        // id become relation name
        // scheme parameter vector becomes header
        // set of tuples is empty for schemes
    }
// Facts
// std::cout << "Facts:" << std::endl;
    for (size_t i = 0; i < datalogprogram.getFacts().size(); i++) {
        Tuple tup;
        Relation rel = database.findRelation(datalogprogram.getFacts()[i].getID());
        rel.addPredAsTuple(datalogprogram.getFacts()[i]);
        database.findRelation(datalogprogram.getFacts()[i].getID()) = rel;

        // database find relation
        // add tuple to relation
        // add tuples to relation based off of id
    }

    std::cout << database.toString();


    // fact uses  tuples but not header

    // query uses everything

// Queries
    for (size_t i = 0; i < datalogprogram.getQueries().size(); i++) {
        Relation rel = database.findRelation(datalogprogram.getQueries()[i].getID());
        // check tuples for ids (anonymous values) against string(values starting and ending with quotes)
        // check query
        datalogprogram.getQueries()[i].toString();

    }
    
    

}