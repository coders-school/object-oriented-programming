
#include <algorithm>
#include <iostream>
#include <memory>

#include "cargo.hpp"
#include "ship.hpp"

// Class responsible for managing Ships in the game.

Ship& Ship::operator-=(size_t num) {
    if (crew_ - num <= crew_) {
        crew_ -= num;
    } else {
        std::cerr << "You need at least one member of the crew !!!\n";
    }
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    if (crew_ + num <= maxCrew_) {
        crew_ += num;
    } else {
        std::cerr << " The maximum amount of members of the crew is " << maxCrew_ << " !!!! \n";
    }

    return *this;
}

size_t Ship::getCapacity() const {
    return capacity_;
}
size_t Ship::getMaxCrew() const {
    return maxCrew_;
}
size_t Ship::getCrew() const {
    return crew_;
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
// Function returns specific cargo
std::shared_ptr<Cargo> Ship::getCargo(size_t index) const {
    if (cargos_.size() <= index) {
        return nullptr;
    }
    return cargos_[index];
}

std::vector<std::shared_ptr<Cargo>> Ship::getCargosVector() const {
    return cargos_;
}

void Ship::setName(const std::string& name) {
    name_ = name;
}

 std::vector<std::shared_ptr<Cargo>>::iterator Ship::findMatchCargo(std::shared_ptr<Cargo> cargo) {
    auto findCargo = std::find_if(cargos_.begin(),
                                  cargos_.end(),
                                  [&cargo](const auto& searchCargo)
                                  { return searchCargo->getName() == cargo->getName(); });
}

void Ship::removeFromShip(std::shared_ptr<Cargo> cargo, size_t amount) {
    auto findCargo = findMatchCargo(cargo);
    if(!findCargo->get() ) {
        return;
    }
    if (findCargo != cargos_.end()) {
        **findCargo -= amount;
    }
}

void Ship::addAmountToShip(std::shared_ptr<Cargo> cargo, size_t amount) {
    auto findCargo = findMatchCargo(cargo);
    if(!findCargo->get() ) {
        return;
    }
    if (findCargo != cargos_.end()) {
        if (capacity_ > cargo->getAmount()) {
            **findCargo += amount;
        } else {
            std::cerr << "Not enuogh space on ship!!!!\n";
        }
    }
}