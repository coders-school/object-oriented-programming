#include "ship.hpp"

#include <algorithm>
#include <iostream>

Ship::Ship() : id_(-1) {}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
    : capacity_(capacity),
      maxCrew_(maxCrew),
      crew_(0),
      speed_(speed),
      name_(name),
      id_(id) {}

Ship::Ship(int maxCrew, int speed, size_t id) : Ship(0, maxCrew, speed, "", id) {}

void Ship::setName(const std::string& name) {
    name_ = name;
}

Ship& Ship::operator-=(size_t crew) {
    crew_ -= crew;
    return *this;
}
Ship& Ship::operator+=(size_t crew) {
    crew_ += crew;
    return *this;
}

void Ship::load(std::shared_ptr<Cargo> cargo) {
    size_t allAmount = 0;
    for (auto el : cargo_) {
        allAmount + el->getAmount();
    }

    if (allAmount + cargo->getAmount() > getCapacity()) {
        std::cerr << "Could not load, to little space\n";
        return;
    }

    auto result = std::find_if(cargo_.begin(), cargo_.end(), [cargo](const auto& el) {
        return (el->getName() == cargo->getName() &&
                el->getBasePrice() == cargo->getBasePrice() &&
                el->getPrice() == cargo->getPrice());
    });

    if (result == cargo_.end()) {
        cargo_.push_back(cargo);
        return;
    }
    **result += cargo->getAmount();
}
