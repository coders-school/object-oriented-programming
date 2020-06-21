#include "ship.hpp"

#include <algorithm>
#include <iostream>

Ship::Ship()
    : id_(-1) {}
Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
    : capacity_(capacity), maxCrew_(maxCrew), speed_(speed), name_(name), id_(id), crew_(0) {}
Ship::Ship(int maxCrew, int speed, size_t id)
    : Ship(0, maxCrew, speed, "", id) {}

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

void Ship::load(const std::shared_ptr<Cargo>& cargo) {
    cargo_.push_back(cargo);
    // apply checking if this cargo type exist
    // and have same expiry date!
    // if yes - increase amount
    // else pushback
}

void Ship::unload(Cargo* cargo) {
    // this should remove given amount of cargo
    auto it = std::find_if(cargo_.begin(), cargo_.end(), [cargo](const auto& ptr) {
        return ptr.get() == cargo;
    });
    if (it != cargo_.end()) {
        cargo_.erase(it);
    }
}
