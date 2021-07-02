#include "Cargo.hpp"
#include "Ship.hpp"

Ship::Ship()
    : Ship(0, 0, 0, "", -1, {})
{}

Ship::Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, const size_t id, CargoVec cargoVec)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id), cargoVec_(std::move(cargoVec))
{}

Ship::Ship(size_t maxCrew, size_t speed,const size_t id)
    : Ship(0, maxCrew, speed, "", id, {})
{}


void Ship::setName(const std::string& name) { 
    name_ = name; 
}

Ship& Ship::operator-=(size_t num) {
    crew_ -= num;
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    crew_ += num;
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
