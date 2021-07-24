#include "Ship.hpp"
#include <string>
#include <iostream>
#include <algorithm>

Ship::Ship()
    : id_(-1) {}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id) {}

Ship::Ship(int maxCrew, int speed, size_t id)
    : Ship(0, maxCrew, speed, "", id) {}

void Ship::setName(const std::string& name) {
    name_ = name;
}

Cargo* Ship::findMatchCargo(Cargo* cargo) {
    for (auto& storedCargo : cargoList_) {
        if (*storedCargo == *cargo) {
            return storedCargo.get();
        }
    }
    return nullptr;
}
void Ship::load(std::shared_ptr<Cargo> cargo) {
    if (Cargo* ptr = findMatchCargo(cargo.get())) {
        *ptr += cargo->getAmount();
        return;
    }
    cargoList_.push_back(cargo);
}
void Ship::unload(Cargo* cargo) {
    removeFromStorage(cargo);
}

void Ship::removeFromStorage(Cargo* cargo) {
    cargoList_.erase(std::find_if(std::begin(cargoList_), std::end(cargoList_),
                              [cargo](const auto& el) {
                                  return *el == *cargo;
                              }));
}

Ship& Ship::operator-=(size_t num) {
    crew_ -= num;
    return *this;
}
Ship& Ship::operator+=(size_t num) {
    crew_ += num;
    return *this;
}

void Ship::printCargolist(){
    int i{1};
    for (const auto& cargo : cargoList_) {
        std::cout << i++ << ". Name: " << cargo->getName()
                  << ", Amount: " << cargo->getAmount()
                  << ", Base price: " << cargo->getBasePrice()
                  << '\n';
    }
}
