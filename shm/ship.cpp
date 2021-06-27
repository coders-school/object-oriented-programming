#include <memory>
#include <iostream>
#include "cargo.hpp"
#include "ship.hpp"

Ship& Ship::operator-=(size_t num) {
    crew_ -= num;
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    crew_ += num;
    return *this;
}

size_t Ship::getCapacity() const {
    return capacity_;
}
size_t Ship::getMaxCrew() const {
    return maxCrew_;
}
size_t Ship::getSpeed() const {
    return speed_;
}
std::string Ship::getName() const {
    return name_;
}
size_t Ship::getId() const {
    return id_;
}
std::shared_ptr<Cargo>Ship::getCargo(size_t index) const {
    if(index < 0) {
        std::cerr << "\nInvalid Cargo\n";
    }
    return cargos_[index];
}

std::vector<std::shared_ptr<Cargo>> Ship::getCargos() const {
    return cargos_;
}

void Ship::setName(const std::string& name) {
    name_ = name;
}
