#include "../inc/Ship.hpp"

#include <algorithm>
#include <numeric>
#include <string>

#include "../inc/Cargo.hpp"

size_t Ship::getId() const { return id_; }
std::string Ship::getName() const { return name_; }
size_t Ship::getSpeed() const { return speed_; }
size_t Ship::getMaxCrew() const { return maxCrew_; }
size_t Ship::getCapacity() const { return capacity_; }
void Ship::setName(const std::string& name) { name_ = name; }
Cargo* Ship::getCargo(size_t index) const { return cargo_[index].get(); }
size_t Ship::getCargoWeight() const {
    return std::accumulate(begin(cargo_), end(cargo_), 0, [](const std::shared_ptr<Cargo>& cargo){ return cargo->getAmount(); });
}

Ship::Ship() { id_ = -1; }
Ship::Ship(int id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity)
    : id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity) { }
Ship::Ship(int id, size_t speed, size_t maxCrew)
    : Ship(id, "", speed, maxCrew, 0) { }

Ship& Ship::operator+=(const int crew) {
    if (crew_ + crew <= maxCrew_) {
        crew_ += crew;
    }
    return *this;
}

Ship& Ship::operator-=(const int crew) {
    if (crew_ > crew) {
        crew_ -= crew;
    }
    return *this;
}
