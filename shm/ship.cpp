#include "ship.hpp"

#include <iostream>
#include <string>

Ship::Ship()
    : id_(-1) {}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, int id)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id) {}

Ship::Ship(int maxCrew, int speed, size_t id)
    : Ship(0, maxCrew, speed, "", id) {}

void Ship::setName(const std::string& name) {
    name_ = name;
}

Ship& Ship::operator-=(size_t crewman) {
    if (crew_ > crewman) {
        crew_ -= crewman;
    }
    return *this;
}
Ship& Ship::operator+=(size_t crewman) {
    if (crew_ + crewman < maxCrew_) {
        crew_ += crewman;
    }
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
std::string Ship::getName() const {
    return name_;
}
int Ship::getId() {
    return id_;
}
