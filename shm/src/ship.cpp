#include "fruit.hpp"
#include "ship.hpp"

#include <algorithm>

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
    Ship::RemoveFromStorageIfRotten();
    delegate_ -> payCrew(crew_);
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
            *el +=cargo->getAmount();
            return;
        }
    }
    cargo_.push_back(std::move(cargo));
}

//TODO: use == operators of each classes to comparison
/*cargoPtr Ship::FindMatchCargo(Cargo* cargo) {
    for (auto el : cargo_) {
        if (*el == *cargo) {
            return el;
        }
    }
}*/

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
                                    if (typeid(el).name() == "Fruit") {
                                        return std::dynamic_pointer_cast<Fruit>(el)->getTimeToRotten() == 0;
                                    }
                                    return false;
                                }),
                 cargo_.end());
}
