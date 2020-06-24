#include "ship.hpp"

#include <iostream>
#include <string>

Ship::Ship() : id_(-1){};

Ship::Ship(uint32_t capacity, uint32_t maxCrew, uint32_t speed, const std::string& name, uint32_t id, Time* time)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id), time_(time) {

    time_->registerObserver(this);

};

Ship::~Ship() {

    time_->unregisterObserver(this);

};

//Ship::Ship(uint32_t maxCrew, uint32_t speed, uint32_t id) : Ship(0, maxCrew, speed, "", id){};

void Ship::setName(const std::string& name) {
    name_ = name;
}

void Ship::addToCargo(Cargo cargo) {

    cargo_.push_back(cargo);
    time_->registerObserver(&cargo_.back());
}

Ship& Ship::operator-=(uint32_t crew) {
    if (crew < crew_) {
        crew_ -= crew;
        return *this;
    }
    std::cerr << "Too few sailors!";
    return *this;
}

Ship& Ship::operator+=(uint32_t crew) {
    if (crew_ + crew <= maxCrew_) {
        crew_ += crew;
        return *this;
    }
    std::cerr << "Too many sailors!";
    return *this;
}

uint32_t Ship::getId() const {
    return id_;
}

std::string Ship::getName() const {
    return name_;
}

uint32_t Ship::getSpeed() const {
    return speed_;
}

uint32_t Ship::getCrew() const {
    return crew_;
}

uint32_t Ship::getMaxCrew() const {
    return maxCrew_;
}

uint32_t Ship::getCapacity() const {
    return capacity_;
}

Cargo* Ship::getCargo(size_t index) {
    return &cargo_[index];
}

std::vector<Cargo> Ship::getVectorCargo() const {
    return cargo_;
}

void Ship::nextDay() {

    std::cout << "Next day in: " << getName() << " \n";

}
