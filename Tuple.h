#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Tuple : public std::vector<std::string> {
    // WARNING: DO NOT USE POLYMORPHISM ON THIS CLASS

    // std::vector<std::string> stringVector;


public:

    std::string toString()const;

    // bool operator<(const Tuple& tuple)const;



};