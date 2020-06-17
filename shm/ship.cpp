#include "ship.hpp"
#include <iostream>
#include <string>

Ship::Ship() : id_(-1){};

Ship::Ship(uint8_t capacity, uint8_t maxCrew, uint8_t speed, const std::string& name, uint8_t id)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id){};

Ship::Ship(uint8_t maxCrew, uint8_t speed, uint8_t id) : Ship(0, maxCrew, speed, "", id){};

void Ship::setName(const std::string& name) {
    name_ = name;
}

Ship& Ship::operator-=(uint8_t crew) {
    if (crew_ < crew) {
        crew_ -= crew;
    }
    std::cerr << "Too few sailors!";
    return *this;
}

Ship& Ship::operator+=(uint8_t crew) {
    if (crew_ + crew <= maxCrew_) {
        crew_ += crew;
    }
    std::cerr << "Too many sailors!";
    return *this;
}

uint8_t Ship::getId() const {
    return id_;
}

std::string Ship::getName() const {
    return name_;
}

uint8_t Ship::getSpeed() const {
    return speed_;
}

uint8_t Ship::getMaxCrew() const {
    return maxCrew_;
}

uint8_t Ship::getCapacity() const {
    return capacity_;
}
