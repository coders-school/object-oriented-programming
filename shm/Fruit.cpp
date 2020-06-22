#include "Fruit.hpp"

Fruit& Fruit::operator--() {
    daysToRot_ == 0 ? /*do nothing*/ : --daysToRot_;
    return *this;
}
