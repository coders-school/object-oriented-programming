#include "ship.hpp"
#include <iostream>
#include <string>

void Ship::setName(const std::string& name) {
    name_ = name;
}

Ship& Ship::operator-=(size_t crew) {
    if (crew_ < crew) {
        crew_ -= crew;
    }
    std::cerr << "Too few sailors!";
    return *this;
}

Ship& Ship::operator+=(size_t crew) {
    if (crew_ + crew <= maxCrew_) {
        crew_ += crew;
    }
    std::cerr << "Too many sailors!";
    return *this;
}

size_t Ship::getId() const {
    return id_;
}

std::string Ship::getName() const {
    return name_;
}

size_t Ship::getSpeed() const {
    return speed_;
}

size_t Ship::getMaxCrew() const {
    return maxCrew_;
}

size_t Ship::getCapacity() const {
    return capacity_;
}
