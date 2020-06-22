#include "ship.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>

Ship::Ship()
    : id_(-1) {}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, unsigned int id)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id) {}

Ship::Ship(int maxCrew, int speed, unsigned int id)
    : Ship(0, maxCrew, speed, "", id) {}

Ship& Ship::operator-=(size_t num) {
    if (num > crew_) {
        crew_ = 0;
    } else if (crew_ > 0) {
        crew_ -= num;
    } else {
        std::cerr << "There is no crew\n";
    }
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    if (crew_ < maxCrew_) {
        crew_ += num;
    } else {
        std::cerr << "You can't have more crew\n";
    }
    return *this;
}

std::shared_ptr<Cargo> Ship::getCargo(size_t index) {
    if (index >= cargo_.size()) {
        std::cerr << "Invalid index\n";
        return nullptr;
    }
    return cargo_[index];
}

size_t Ship::getAvailableSpace() const {
    size_t reservedSpace = std::accumulate(cargo_.begin(),
                                           cargo_.end(),
                                           0, [](size_t space, const auto& cargo) {
                                               return space += cargo->getAmount();
                                           });
    return capacity_ - reservedSpace;
}

void Ship::load(const std::shared_ptr<Cargo>& cargo) {
    if (cargo->getAmount() > getAvailableSpace()) {
        std::cerr << "not enough space on the ship\n";
        return;
    }
    auto cargoOnShip = std::find_if(cargo_.begin(), cargo_.end(),
                                    [name = cargo->getName()](const auto& el) {
                                        return el->getName() == name;
                                    });
    if (cargoOnShip == cargo_.end()) {
        cargo_.push_back(cargo);
    } else {
        (*cargoOnShip)->operator+=(cargo->getAmount());
    }
}

void Ship::unload(const Cargo* const& cargo) {
    auto cargoOnShip = std::find_if(cargo_.begin(), cargo_.end(),
                                    [name = cargo->getName()](const auto& el) {
                                        return el->getName() == name;
                                    });
    if (cargoOnShip == cargo_.end()) {
        std::cerr << "Not found cargo\n";
        return;
    }
    if ((*cargoOnShip)->getAmount() < cargo->getAmount()) {
        std::cerr << "You don't have enough cargo\n";
        return;
    }

    (*cargoOnShip)->operator-=(cargo->getAmount());

    if ((*cargoOnShip)->getAmount() == 0) {
        std::copy(cargo_.end(), cargo_.end() - 1, cargoOnShip);
        cargo_.erase(cargo_.end() - 1, cargo_.end());
        cargo_.shrink_to_fit();
    }
}

void Ship::receiveCargo(Cargo* cargo, size_t amount, CargoHolder* cargoHolder) {
    auto clonedCargo = cargo->cloneToShared();
    (*clonedCargo) -= (clonedCargo->getAmount() - amount);
    (*cargo) -= amount;
    if (cargo->getAmount() == 0) {
        cargoHolder->clearEmptyCargos();
    }
    cargo_.push_back(clonedCargo);
}

void Ship::clearEmptyCargos() {
    cargo_.erase(std::remove_if(cargo_.begin(), cargo_.end(), [](auto& cargo) { return cargo->getAmount() == 0; }), cargo_.end());
}
