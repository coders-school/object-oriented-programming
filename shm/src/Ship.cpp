#include "shm/inc/Ship.hpp"

#include <iostream>

Ship::Ship(int id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity)
    : id_(id)
    , name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , capacity_(capacity)
{}

Ship::Ship(int id, size_t speed, size_t maxCrew) 
    : Ship(id, "Ship", speed, maxCrew, 100)
{}

Ship& Ship::operator+=(const size_t crew) {
    if (crew_ + crew > maxCrew_) {
        std::cerr << "Too many sailors\n";
        return *this;
    }
    crew_ += crew;
    return *this;
}

Ship& Ship::operator-=(const size_t crew) {
    if (crew_ < crew) {
        std::cerr << "Number of sailors lower than 0\n";
        return *this;
    }
    crew_ -= crew;
    return *this;
}

void Ship::setName(const std::string& name) {
    name_ = name;
}

std::shared_ptr<Cargo> Ship::getCargo(size_t index) const {
    if (cargo_.size() <= index) {
        return nullptr;
    }
    return cargo_[index];
}
