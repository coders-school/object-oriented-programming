#include "ship.hpp"

Ship &Ship::operator-=(size_t num)
{
    crew_ -= num;
    return *this;
}

Ship &Ship::operator+=(size_t num)
{
    crew_ += num;
    return *this;
}

void Ship::addCargo(Cargo* item) {
    shipCargo.push_back(item);
}