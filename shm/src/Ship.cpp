#include "shm/inc/Ship.hpp"
#include "shm/inc/Cargo.hpp"
#include "shm/inc/Delegate.hpp"
#include "shm/inc/Player.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>

Ship::Ship(int id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity, Delegate* delegate)
    : id_(id)
    , name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , capacity_(capacity)
    , delegate_(delegate)
{}

Ship::Ship(int id, size_t speed, size_t maxCrew, Delegate* delegate) 
    : Ship(id, "Ship", speed, maxCrew, 100, delegate)
{}

Ship& Ship::operator+=(const size_t crew) {
    if (crew_ + crew > maxCrew_) {
        throw std::out_of_range("Too many sailors!");
    }
    crew_ += crew;
    return *this;
}

Ship& Ship::operator-=(const size_t crew) {
    if (crew_ < crew) {
        throw std::out_of_range("Number of sailors lower than zero!");
    }
    crew_ -= crew;
    return *this;
}

void Ship::setName(const std::string& name) {
    name_ = name;
}

std::shared_ptr<Cargo> Ship::getCargo(size_t index) const {
    if (index >= cargos_.size()) {
        throw std::out_of_range("Invalid cargo!");
    }
    return cargos_[index];
}

Cargo* Ship::getCargo(const std::string& name) const {
    auto result{ std::find_if(cargos_.begin(), cargos_.end(),
                             [&name](const auto& cargo) {
                                return cargo->getName() == name ;
                             })
    };
    
    return result != cargos_.end() ? result->get() : nullptr;
}

void Ship::load(const std::shared_ptr<Cargo>cargo) {
 // WRITE ME
}
// FIXME:
void Ship::unload(const std::shared_ptr<Cargo> cargo) {
 // WRITE ME
}

void Ship::nextDay() {
    delegate_->payCrew(crew_);
    for (size_t i = 0; i < cargos_.size(); i++) {
        if (cargos_[i]->isExpired() == true) {
            std::cout << cargos_[i]->getAmount() << ' ' << cargos_[i]->getName() 
                      << " was completty rotten and the captain threw overboard\n";
            cargos_.erase(std::remove(cargos_.begin(), cargos_.end(), cargos_[i]), cargos_.end());
        }
    }
}

void Ship::changeDelegate(Player* player) {
    delegate_ = player;
}
