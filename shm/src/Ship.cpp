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

void Ship::load(const std::shared_ptr<Cargo>cargo) {
    if (cargo) {
        bool ifExistCargo = false;
        for (auto const & element : cargos_) {
            if (element == cargo) {
                *element+=cargo->getAmount();
                ifExistCargo = true;
                break;
            }
        }
        if (ifExistCargo == false) {
            cargos_.push_back(cargo);
        }
    }
}

// FIXME:
void Ship::unload(Cargo* cargo) {
    if (cargo) {
        int it = -1;
        for (int i = 0; i < static_cast<int>(cargos_.size()); i++) {
            if (*(cargos_[i].get()) == *cargo) {
                it = i;
                break;
            }
        }
        if (it == -1) {
            std::cerr << "Cargo not exist in ship\n";
        } else if (cargo->getAmount() > cargo[it].getAmount()) {
            std::cerr << "Wrong value, you wanna unload more then exist in ship\n";
        } else if (cargo->getAmount() == cargo[it].getAmount()) {
            cargos_.erase(std::remove(cargos_.begin(), cargos_.end(), cargos_[it]), cargos_.end());
        } else {
            *cargos_[it]-= cargo->getAmount();
        }
    }
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
