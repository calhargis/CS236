#include "Tuple.h"

std::string Tuple::toString() const{
    std::stringstream oss;
    for (size_t i = 0; i < this->size(); i++) {
        oss << this->at(i) << " ";
    }
    return oss.str();
}

// bool Tuple::operator< (const Tuple& tuple) const{
//     return true;
// }