#include "Ship.hpp"
#include "Cargo.hpp"
#include "Time.hpp"

#include <iostream>
#include <stdexcept>

Ship::Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, size_t id, CargoVec cargoVec)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id), cargoVec_(std::move(cargoVec)) {}

Ship::Ship(size_t maxCrew, size_t speed, const size_t id)
    : Ship(0, maxCrew, speed, "", id, {}) {}

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

void Ship::load(std::unique_ptr<Cargo> cargo) {
    if (!cargo) {
        return;
    }

    Cargo* storedCargo = nullptr;
    for (const auto& el : cargoVec_) {
        if (*cargo == *el) {
            storedCargo = el.get();
            break;
        }
    }

    if (!storedCargo) {
        for (auto& el : cargoVec_) {
            if (!el) {
                el = std::move(cargo);  //move cargo into empty cargo space
                return;
            }
        }
        cargoVec_.push_back(std::move(cargo));  //move cargo into vector
        return;
    }
    *storedCargo += cargo->getAmount();  //transfer amount into comperable cargo
    //here cargo will be destroyed
}

void Ship::unload(const Cargo* const cargo) {  //ver A
    if (!cargo) {
        return;
    }
    for (auto& el : cargoVec_) {
        if (el.get() == cargo) {  //equal pointers -> equal amount
            el.reset();
            //we leave empty cargo space in store here
            cargoVec_.erase(std::remove(begin(cargoVec_), end(cargoVec_), nullptr), end(cargoVec_));
            return;
        }
    }
    throw std::logic_error("Store: Not my Cargo!");
}

void Ship::nextDay() {
    std::cout << "Next Day in Ship " << name_ << '\n';
}
