#include "fruit.hpp"

#include <iostream>

Fruit& Fruit::operator--() {
    if (timeToExpire_ == 0) {
        std::cerr << "Fruit rotten\n";
        return *this;
    }
    --timeToExpire_;
    return *this;
}
