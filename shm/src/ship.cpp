#include "ship.hpp"

#include <algorithm>
#include <iostream>

Ship::Ship() : id_(-1) {}

Ship::Ship(int capacity,
           int maxCrew,
           int speed,
           const std::string& name,
           size_t id,
           Delegate* delegate,
           Time* time)
    : delegate_(delegate),
      capacity_(capacity),
      maxCrew_(maxCrew),
      crew_(0),
      speed_(speed),
      name_(name),
      id_(id),
      time_(time) {}

Ship::Ship(int maxCrew, int speed, size_t id, Delegate* delegate, Time* time)
    : Ship(0, maxCrew, speed, "", id, delegate, time) {
    time_->addObserver(this);
}

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
    for (const auto& el : cargo_) {
        allAmount += el->getAmount();
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

void Ship::unload(Cargo* cargo) {
    auto thing = std::find_if(cargo_.begin(), cargo_.end(), [cargo](const auto& el) {
        return (el->getName() == cargo->getName() &&
                el->getBasePrice() == cargo->getBasePrice() &&
                el->getPrice() == cargo->getPrice());
    });
    if (thing == cargo_.end()) {
        return;
    }

    if ((*thing)->getAmount() <= cargo->getAmount()) {
        cargo_.erase(thing);
        return;
    }
    **thing -= cargo->getAmount();
}

void Ship::nextDay() {
    delegate_->payCrew(crew_);
}

Ship::~Ship() {
    time_->removeObserver(this);
}
