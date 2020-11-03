#include <iostream>
#include "DatalogProgram.h"
#include "Database.h"

class Interpreter {

    Database database;
    DatalogProgram datalogprogram;
    // store database

public:

    Interpreter(DatalogProgram datalogprogram);

    void run();

};