#include "Fruit.hpp"

Fruit& Fruit::operator--() {
    if (daysToRot_ == 0) {
        return *this;
    }
    --daysToRot_;
    return *this;
}
