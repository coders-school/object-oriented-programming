#include "ship.hpp"

#include <algorithm>
#include <iostream>

Ship::Ship()
    : id_(-1) {}
Ship::Ship(size_t id, std::string name, size_t speed, size_t maxCrew, size_t capacity)
    : id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity) {}
Ship::Ship(size_t id, std::string name, size_t speed)
    : Ship(id, name, speed, 0, 0) {}

void Ship::setName(const std::string& name) {
    name_ = name;
}

void Ship::nextDay() {
    for (auto el : cargo_) {
        el->nextDay();
    }
    //Ship::RemoveFromStorageIfRotten();
    money_ -= crew_;
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
}*/

//TODO: use == operators of each classes to comparison
/*cargoPtr Ship::FindMatchCargo(Cargo* cargo) {
    auto looked_for = std::find(cargo_.begin(), cargo_.end(), *cargo);
    if (looked_for != cargo_.end()) {
        return *looked_for;
    }
    // for (auto el : cargo_) {
    //     if (el->getName() == "Fruit") {
    //         if (el->getName() == cargo->getName() &&
    //             el->getBasePrice() == cargo->getBasePrice() &&
    //             el->getExpiryDate() == cargo->getExpiryDate())
    //             return el.get();
    //     } else if (el->getName() == "Alcohol") {
    //         if (el->getName() == cargo->getName() &&
    //             el->getBasePrice() == cargo->getBasePrice() &&
    //             el->getPercentage() == cargo->getPercentage())
    //             return el.get();
    //     } else {
    //         if (el->getName() == cargo->getName() &&
    //             el->getBasePrice() == cargo->getBasePrice() &&
    //             el->getRarity() == cargo->getRarity())
    //             return el.get();
    //     }
    // }
}*/

/*void Ship::Unload(Cargo* cargo) {
    RemoveFromStorage(cargo);
}*/

/*void Ship::RemoveFromStorage(Cargo* cargo) {
    cargo_.erase(std::find_if(std::begin(cargo_), std::end(cargo_),
                              [cargo](const auto& el) {
                                  return *el == *cargo;
                              }));
}*/

/*void Ship::RemoveFromStorageIfRotten() {
    cargo_.erase(std::remove_if(cargo_.begin(),
                                cargo_.end(),
                                [](auto& el) {
                                    if (el->getName() == "Fruit") {
                                        return el->getTimeToRotten() == 0;
                                    }
                                    return false;
                                }),
                 cargo_.end());
}*/

void Ship::printCargo() const {
    if (cargo_.empty()) {
        std::cout << "Cargo is empty" << '\n';
    }
    for (const auto& cargoIt : cargo_) {
        //std::cout << *cargoIt;
    }
    std::cout << '\n';
}
