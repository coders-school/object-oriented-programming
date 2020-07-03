#include "ship.hpp"

#include <numeric>

Ship::Ship()
    : Ship(0, 0, 0, "", 0)
{}
Ship::Ship(int maxCrew, int speed, size_t id)
    : Ship(0, maxCrew, speed, "", id)
{}
Ship::Ship(int capacity, int maxCrew, int speed,
        const std::string& name, size_t id)
    : capacity_(capacity)
    , maxCrew_(maxCrew) 
    , crew_(0)
    , speed_(speed)
    , name_(name)
    , id_(id)
{}

Ship& Ship::operator-=(const size_t crew) {
    if (crew <= crew_) {
        crew_ -= crew;
        return *this;
    }
    return *this;
}
Ship& Ship::operator+=(const size_t crew) {
    if (crew_ + crew <= maxCrew_) {
        crew_ += crew;
        return *this;
    }
    return *this;
}

void Ship::setName(const std::string& name) { name_ = name; }

size_t Ship::getCapacity() const  { return capacity_; }
size_t Ship::getMaxCrew() const   { return maxCrew_; }
size_t Ship::getSpeed() const     { return speed_; }
std::string Ship::getName() const { return name_; }
size_t Ship::getId() const        { return id_; }



Cargo* Ship::getCargo(const std::string& name) {
    return Common::getCargo(name, cargo_);
}


size_t Ship::getAvailableSpace() const {
    Common::getAvailableSpace(capacity_, cargo_);
}

bool Ship::addCargo(Cargo* cargo) {
    if (this->getAvailableSpace() >= cargo->getAmount()) {
        auto ptrCargo = this->getCargo(cargo->getName());

        //If there is not such cargo type yet
        if (ptrCargo == nullptr) {
            cargo_.push_back(cargo);
            //If there is already relevant type of cargo
        } else {
            size_t tmpAmount = ptrCargo->getAmount() + cargo->getAmount();
            ptrCargo->setAmount(tmpAmount);
        }
    }
}

bool Ship::removeCargo(Cargo* cargo) {
    auto it = std::find_if(cargo_.begin(),
                           cargo_.end(),
                           [=](Cargo* el) {
                               return el->getName() == cargo->getName();
                           });
    cargo_.erase(it);
}
