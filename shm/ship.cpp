#include "ship.hpp"

Ship &Ship::operator-=(size_t num)
{
    if(crew_ < num){
        crew_ = 0;
    }
    else{
        crew_ -= num;
    }
    return *this;
}

Ship &Ship::operator+=(size_t num)
{
    crew_ += num;
    return *this;
}

void Ship::addCargo(Cargo* item) {
    shipCargo.emplace_back(item);
}
Cargo* Ship::findMatchCargo(Cargo* cargo) {
    for (auto& el : shipCargo) {
        if(*el == *cargo) {
            return el.get();
        }
    }
    return nullptr;
}