#include "../inc/Ship.hpp"

Ship::Ship(int8_t id, std::string name, uint8_t speed, uint8_t maxCrew, uint8_t capacity)
    : id_(id)
    , name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , capacity_(capacity)
{}

Ship::Ship(int8_t id, uint8_t speed, uint8_t maxCrew) 
    : Ship(id, "Ship", speed, maxCrew, 100)
{}

Ship& Ship::operator+=(const uint16_t value){
    crew_ += value;
    return *this;
}

Ship& Ship::operator-=(const uint16_t value){
    crew_ -= value;
    return *this;
}

void Ship::setName(const std::string& name){
    name_ = name;
}