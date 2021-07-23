#include "Ship.hpp"
#include "Cargos/Cargo.hpp"
#include "Time.hpp"
#include "Warehouse.hpp"

#include <iostream>
#include <stdexcept>

size_t Ship::nextId = 0;

Ship::Ship()
    : Warehouse::Warehouse(), id_{nextId++} {}

Ship::Ship(Crew maxCrew, Speed speed)
    : Warehouse::Warehouse(), maxCrew_(maxCrew), speed_(speed), id_{nextId++} {}

Ship::Ship(Capacity capacity, Crew maxCrew, Speed speed, const std::string& name)
    : Warehouse(), capacity_(capacity), maxCrew_(maxCrew), speed_(speed), name_(name), id_{nextId++} {}


Ship::Ship(CargoVec cargoVec, Capacity capacity, Crew maxCrew, Speed speed, const std::string& name)
    : Warehouse(std::move(cargoVec)), capacity_(capacity), maxCrew_(maxCrew), speed_(speed), name_(name), id_{nextId++} {}

void Ship::setName(const std::string& name) {
    name_ = name;
}

Ship& Ship::operator-=(Crew numCrew) {
    if (crew_ < numCrew) {
        throw std::invalid_argument("Not allowed! You will be below zero!");
    }
    crew_.value -= numCrew.value;
    return *this;
}

Ship& Ship::operator+=(Crew numCrew) {
    if (maxCrew_ - crew_ < numCrew) {
        throw std::invalid_argument("Not allowed! There will be too many people on the board!");
    }
    crew_.value += numCrew.value;
    return *this;
}

Capacity Ship::getCapacity() const {
    return capacity_;
}

Crew Ship::getMaxCrew() const {
    return maxCrew_;
}

Speed Ship::getSpeed() const {
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
    std::cout << "Crew income: " << crew_ << '\n';
    if (debt) {
        auto result = debt(crew_);
        if (!result) {
            std::cout << "Ship strike again.\n";
        }
    }
}

void Ship::setDebt(std::function<bool(size_t)> payFunction) {
    debt = payFunction;  //PLAYER::pay
}