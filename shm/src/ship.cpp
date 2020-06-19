#include "ship.hpp"

Ship::Ship()
    : id_(-1) {}
Ship::Ship(size_t id, std::string name, size_t speed, size_t maxCrew, size_t capacity)
    : id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity) {}
Ship::Ship(size_t id, std::string name, size_t speed)
    : Ship(id, name, speed, 0, 0) {}

void Ship::setName(const std::string& name) {
    name_ = name;
}

Ship& Ship::operator+=(const size_t& crew) {
    if (crew_ + crew <= maxCrew_) {
        crew_ += crew;
    }
    return *this;
}

Ship& Ship::operator-=(const size_t& crew) {
    if (crew_ - crew >= 0) {
        crew_ -= crew;
    }
    return *this;
}

/*void Ship::load(std::shared_ptr<Cargo> cargo) {
    if (auto match_cargo = FindMatchCargo(cargo.get())) {
        *match_cargo += cargo->getAmount();
        return;
    }
    cargo_.push_back(std::move(cargo));
}

/*Cargo* Ship::FindMatchCargo(Cargo* cargo) {
    for (auto el : cargo_) {
        if (el->getName() == "Fruit") {
            if (el->getName() == cargo->getName() &&
                el->getBasePrice() == cargo->getBasePrice() &&
                el->getExpiryDate() == cargo->getExpiryDate())
                return el.get();
        } else if (el->getName() == "Alcohol") {
            if (el->getName() == cargo->getName() &&
                el->getBasePrice() == cargo->getBasePrice() &&
                el->GetPercentage() == cargo->getPercentage())
                return el.get();
        } else {
            if (el->getName() == cargo->getName() &&
                el->getBasePrice() == cargo->getBasePrice() &&
                el->getRarity() == cargo->getRarity())
                return el.get();
        }
    }
}*/
