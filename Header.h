#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Header {

std::vector<std::string> headerVector;

public:

    void addHeader(std::string addString);
    std::vector<std::string> returnVector();
    std::string toString()const;


};