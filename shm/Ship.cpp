#include "Ship.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

Ship::Ship()
    : id_(-1) {}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(10), speed_(speed), name_(name), id_(id) {}

Ship::Ship(int maxCrew, int speed, size_t id)
    : Ship(0, maxCrew, speed, "", id) {}

void Ship::setName(const std::string& name) {
    name_ = name;
}

Cargo* Ship::findCargo(Cargo* cargo) {
    auto it = std::find_if(cargoList_.begin(), cargoList_.end(),
                           [cargo](const auto& product) { return *cargo == *product; });
    if (it != cargoList_.end()) {
        return (*it).get();
    } else {
        return nullptr;
    }
}

void Ship::load(std::unique_ptr<Cargo> cargo) {
    if (auto ptr = findCargo(cargo.get())) {
        *ptr += cargo->getAmount();
        return;
    }
    cargoList_.push_back(std::move(cargo));
    printCargolist();
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

void Ship::printCargolist() {
    if (cargoList_.empty()) {
        std::cout << "\n"
                  << "Cargo room is empty"
                  << "\n";
    } else {
        int i{1};
        for (const auto& cargo : cargoList_) {
            std::cout << i++ << ". Name: " << cargo->getName()
                      << ", Amount: " << cargo->getAmount()
                      << ", Base price: " << cargo->getBasePrice()
                      << '\n';
        }
    }
    return;
}

size_t Ship::calculateCargoAmount() {
    size_t cargoAmount = std::accumulate(cargoList_.begin(),
                                         cargoList_.end(),
                                         0,
                                         [](int amount, std::unique_ptr<Cargo>& cargo) { return amount += cargo->getAmount(); });
    return cargoAmount;
}

void Ship::nextDay(){
    delegate_ -> payCrew((size_t)crew_ * 0.1);
};