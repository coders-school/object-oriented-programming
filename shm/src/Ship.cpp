#include "Ship.hpp"

#include <algorithm>
#include <numeric>

#include "Cargo.hpp"

Ship::Ship() { id_ = -1; }
Ship::Ship(int id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity)
    : id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity) { }
Ship::Ship(int id, size_t speed, size_t maxCrew)
    : Ship(id, "", speed, maxCrew, 0) { }

size_t Ship::getId() const { return id_; }
std::string Ship::getName() const { return name_; }
size_t Ship::getSpeed() const { return speed_; }
size_t Ship::getMaxCrew() const { return maxCrew_; }
size_t Ship::getCapacity() const { return capacity_; }
void Ship::setName(const std::string& name) { name_ = name; }
Cargo* Ship::getCargo(size_t index) const { return cargo_.at(index).get(); }
size_t Ship::getCargoWeight() const {
    return std::accumulate(begin(cargo_), end(cargo_), 0, [](const std::shared_ptr<Cargo>& cargo){ return cargo->getAmount(); });
}

Ship& Ship::operator+=(const int crew) {
    if (crew_ + crew <= maxCrew_) {
        crew_ += crew;
    }
    else {
        std::cerr << "Error! The number of crew members cannot be greater than " << getMaxCrew();
    }
    return *this;
}

Ship& Ship::operator-=(const int crew) {
    if (crew_ > crew) {
        crew_ -= crew;
    }
    else {
        std::cerr << "Error! The number of crew members cannot be lower than 0!";
    }
    return *this;
}
