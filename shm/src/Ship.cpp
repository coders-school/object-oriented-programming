#include "shm/inc/Ship.hpp"

#include <stdexcept>

#include "shm/inc/Cargo.hpp"

Ship::Ship(int id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity)
    : id_(id)
    , name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , capacity_(capacity)
{}

Ship::Ship(int id, size_t speed, size_t maxCrew) 
    : Ship(id, "Ship", speed, maxCrew, 100)
{}

Ship& Ship::operator+=(const size_t crew) {
    if (crew_ + crew > maxCrew_) {
        throw std::out_of_range("Too many sailors!");
    }
    crew_ += crew;
    return *this;
}

Ship& Ship::operator-=(const size_t crew) {
    if (crew_ < crew) {
        throw std::out_of_range("Number of sailors lower than zero!");
    }
    crew_ -= crew;
    return *this;
}

void Ship::setName(const std::string& name) {
    name_ = name;
}

std::shared_ptr<Cargo> Ship::getCargo(size_t index) const {
    if (index >= cargos_.size()) {
        throw std::out_of_range("Invalid cargo!");
    }
    return cargos_[index];
}

std::vector<std::shared_ptr<Cargo>> Ship::getCargos() const {
    return cargos_;
}
