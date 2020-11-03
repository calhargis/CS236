#ifndef Parameter_h
#include <iostream>
#include <string>

class Parameter {
private:
    
    std::string type;
    std::string paramValue;

public:
    Parameter();
    Parameter(std::string value);

    void setType(std::string type);
    void setValue(std::string value);
    std::string getValue();
};

#endif /* Parameter_h */