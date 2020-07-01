#include "ship.hpp"

#include <algorithm>
#include <iostream>

Ship::Ship()
    : id_(0) {}

Ship::Ship(int maxCrew, int speed, size_t id, const std::string& name, int capacity, Delegate* delegate)
    : maxCrew_(maxCrew), speed_(speed), id_(id), name_(name), capacity_(capacity), delegatePlayer_(delegate), crew_(0) {}

Ship::Ship(int maxCrew, int speed, size_t id)
    : Ship(maxCrew, speed, id, "", 0, nullptr) {}

void Ship::setName(const std::string& name) {
    name_ = name;
}

Ship& Ship::operator+=(const size_t crew) {
    if (crew_ + crew > maxCrew_) {
        std::cerr << "Max crew exceeded\n";
        return *this;
    }
    crew_ += crew;
    return *this;
}

Ship& Ship::operator-=(const size_t crew) {
    if (crew_ < crew) {
        std::cerr << "Crew number can't be negative\n";
        return *this;
    }
    crew_ -= crew;
    return *this;
}

void Ship::nextDay() {
    if (delegatePlayer_) {
        delegatePlayer_->PayCrew(crew_);
    }
}
