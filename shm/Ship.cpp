#include "Cargo.hpp"
#include "Ship.hpp"

Ship::Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, size_t id, CargoVec cargoVec)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id), cargoVec_(std::move(cargoVec))
{}

Ship::Ship(size_t maxCrew, size_t speed,const size_t id)
    : Ship(0, maxCrew, speed, "", id, {})
{}

void Ship::setName(const std::string& name) { 
    name_ = name; 
}

//In the situation when we will have negative crew - exception will be thrown - so we have to remember that method which will   use this operator, should catch it!
Ship& Ship::operator-=(size_t numCrew) {
    if (crew_ < numCrew) {
        throw std::invalid_argument("Not allowed! You will be below zero!");
    }
    crew_ -= numCrew;
    return *this;
}
//This operator can throw exception - we have to remember that method which will use this operator, should catch it!
Ship& Ship::operator+=(size_t numCrew) {
    if (maxCrew_ - crew_ < numCrew) {
        throw std::invalid_argument("Not allowed! There will be too many people on the board!");
    }
    crew_ += numCrew;
    return *this;
}

size_t Ship::getCapacity() const { 
    return capacity_; 
}

size_t Ship::getMaxCrew() const { 
    return maxCrew_; 
}

size_t Ship::getSpeed() const { 
    return speed_; 
}

const std::string& Ship::getName() const { 
    return name_; 
}

size_t Ship::getId() const { 
    return id_; 
}

const Ship::CargoVec& Ship::getCargoVec() const { 
    return cargoVec_; 
}
