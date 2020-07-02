#include "Ship.h"

Ship::Ship()
    : id_(-1){};
Ship::Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, size_t id)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id) {}
Ship::Ship(size_t maxCrew, size_t speed, size_t id)
    : Ship(0, maxCrew, speed, "", id) {}

void Ship::setName(const std::string& name) {
    name_ = name;
}

Ship& Ship::operator-=(size_t num) {
    if (num >= crew_) {
        crew_ = 0;
    } else {
        crew_ -= num;
    }
    return *this;
}
Ship& Ship::operator+=(size_t num) {
    crew_ += num;
    if (crew_ > maxCrew_) {
        crew_ = maxCrew_;
    }
    return *this;
}

std::shared_ptr<Cargo> Ship::getCargo(size_t index) {
    return cargo_[index];
}
std::vector<std::shared_ptr<Cargo>> Ship::getCargos() const {
    return cargo_;
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
