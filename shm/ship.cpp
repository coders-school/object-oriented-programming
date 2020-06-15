#include "ship.hpp"

Ship::Ship()
    : id_(-1)
{}

Ship::Ship(int id, std::string name, size_t speed, size_t maxCrew, size_t capacity)
    : id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity)
{}

Ship::Ship (int id, std::string name, size_t speed)
    : Ship(id, name, speed, 0, 0)
{}

int Ship::getId() {
    return id_;
}

std::string Ship::getName() {
    return name_;
}

size_t Ship::getSpeed() {
    return speed_;
}

size_t Ship::getMaxCrew() {
    return maxCrew_;
}

size_t Ship::getCapacity() {
    return capacity_;
}

void Ship::setName(const std::string &name) {
    name_ = name;
}

