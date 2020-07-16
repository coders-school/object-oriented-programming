#include "ship.hpp"
#include "locators.hpp"

#include <algorithm>
#include <iostream>

Ship::Ship() : id_(-1) {}

Ship::Ship(int capacity,
           int maxCrew,
           int speed,
           const std::string& name,
           size_t id,
           Delegate* delegate)
    : delegate_(delegate),
      capacity_(capacity),
      maxCrew_(maxCrew),
      crew_(0),
      speed_(speed),
      name_(name),
      id_(id) {
    TimeServiceLocator::getTime()->addObserver(this);
}

Ship::Ship(int maxCrew, int speed, size_t id, Delegate* delegate)
    : Ship(100, maxCrew, speed, "", id, delegate) {}

void Ship::setName(const std::string& name) {
    name_ = name;
}

Ship& Ship::operator-=(size_t crew) {
    (crew_ < crew) ? crew_ = 0 : crew_ -= crew;
    return *this;
}
Ship& Ship::operator+=(size_t crew) {
    (crew_ + crew > maxCrew_) ? crew_ = maxCrew_ : crew_ += crew;
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

void Ship::unload(Cargo* cargo, size_t amount) {
    auto thing = std::find_if(cargo_.begin(), cargo_.end(), [cargo](const auto& el) {
        return (el->getName() == cargo->getName() &&
                el->getBasePrice() == cargo->getBasePrice() &&
                el->getPrice() == cargo->getPrice());
    });
    if (thing == cargo_.end()) {
        return;
    }

    if ((*thing)->getAmount() <= amount) {
        cargo_.erase(thing);
        return;
    }
    **thing -= amount;
}

void Ship::nextDay() {
    delegate_->payCrew(crew_);
}

Ship::~Ship() {
    TimeServiceLocator::getTime()->removeObserver(this);
}
