#include "Ship.hpp"
#include "Cargo.hpp"
#include "Time.hpp"
#include "Warehouse.hpp"

#include <iostream>
#include <stdexcept>
Ship::Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, size_t id, CargoVec cargoVec)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id), Warehouse(std::move(cargoVec))
{}

Ship::Ship(size_t maxCrew, size_t speed,const size_t id)
   : Warehouse::Warehouse(), capacity_(0), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(""), id_(id)
{}


void Ship::setName(const std::string& name) { 
    name_ = name;
}

Ship& Ship::operator-=(size_t numCrew) {
    if (crew_ < numCrew) {
        throw std::invalid_argument("Not allowed! You will be below zero!");
    }
    crew_ -= numCrew;
    return *this;
}

Ship& Ship::operator+=(size_t numCrew) {
    if (maxCrew_ - crew_ < numCrew) {
        throw std::invalid_argument("Not allowed! There will be too many people on the board!");
    }
    crew_ += numCrew;
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

const std::string& Ship::getName() const {
    return name_;
}

size_t Ship::getId() const {
    return id_;
}

const Ship::CargoVec& Ship::getCargoVec() const {
    return cargoVec_;
}

void Ship::nextDay() {
    std::cout << "Next Day in Ship " << name_ << '\n';
}
