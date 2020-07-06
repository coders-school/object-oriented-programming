#include "ship.hpp"

#include <algorithm>
#include <iostream>

#include "fruit.hpp"

Ship::Ship()
    : id_(-1) {}
Ship::Ship(size_t id, std::string name, size_t speed, size_t maxCrew, size_t capacity, Delegate* delegate, std::shared_ptr<Time> time)
    : id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity), delegate_(delegate), time_(time) {
        time_->addObserver(this);
        crew_ = maxCrew_;
    }

Ship::~Ship() {
    time_->removeObserver(this);
}

void Ship::setName(const std::string& name) {
    name_ = name;
}

void Ship::nextDay() {
    for (auto el : getCargo()) {
        //*el.get() += 1;
        el.get()->nextDay();
    }
    Ship::RemoveFromStorageIfRotten();
    delegate_->payCrew(crew_);
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

void Ship::load(std::shared_ptr<Cargo> cargo) {
    for (auto el : cargo_) {
        if (*el == *cargo) {
            *el += cargo->getAmount();
            return;
        }
    }
    cargo_.push_back(std::move(cargo));
}

cargoPtr Ship::FindMatchCargo(Cargo* cargo) {
    for (auto el : cargo_) {
        if (*el == *cargo) {
            return el;
        }
    }
    return nullptr;
}

void Ship::Unload(Cargo* cargo) {
    RemoveFromStorage(cargo);
}

void Ship::RemoveFromStorage(Cargo* cargo) {
    cargo_.erase(std::find_if(std::begin(cargo_), std::end(cargo_),
                              [cargo](const auto& el) {
                                  return *el == *cargo;
                              }));
}

void Ship::RemoveFromStorageIfRotten() {
    cargo_.erase(std::remove_if(cargo_.begin(),
                                cargo_.end(),
                                [](auto& el) {
                                    if (el->getPrice() == el->getBasePrice()) {
                                        return std::dynamic_pointer_cast<Fruit>(el)->getTimeToRotten() == 0;
                                    }
                                    return false;
                                }),
                 cargo_.end());
}

void Ship::printCargo() const {
    if (cargo_.empty()) {
        std::cout << "Cargo is empty" << '\n';
    }
    std::for_each(cargo_.begin(), cargo_.end(), [](auto& it) {
        std::cout << it->getInfo();
    });
}
