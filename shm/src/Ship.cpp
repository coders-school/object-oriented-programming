#include "shm/inc/Ship.hpp"

#include <algorithm>
#include <iostream>

#include "shm/inc/Cargo.hpp"
#include "shm/inc/Delegate.hpp"

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

Ship& Ship::operator+=(const size_t amount) {
    if (amount + crew_ <= maxCrew_) {
        crew_ += amount;
    } else {
        std::cerr << "Maximum amount of crew is " << maxCrew_ << '\n';
    }
    return *this;
}

Ship& Ship::operator-=(const size_t amount) {
    if (crew_ <= amount) {
        crew_ -= amount;
    } else {
        std::cerr << "Amount of crew can't be under 0\n";
    }
    return *this;
}

void Ship::setName(const std::string& name) {
    name_ = name;
}

std::shared_ptr<Cargo> Ship::getCargo(size_t index) const {
    if (cargo_.size() <= index) {
        return nullptr;
    }
    return cargo_[index];
}

void Ship::load(const std::shared_ptr<Cargo>cargo) {
    if (cargo != nullptr) {
        bool ifExistCargo = false;
        for (auto const & element : cargo_) {
            if (element == cargo) {
                *element+=cargo->getAmount();
                ifExistCargo = true;
                break;
            }
        }
        if (ifExistCargo == false) {
            cargo_.push_back(cargo);
        }
    }
}

void Ship::unload(Cargo* cargo) {
    if (cargo != nullptr) {
        int it = -1;
        for (int i = 0; i < static_cast<int>(cargo_.size()); i++) {
            if (*(cargo_[i].get()) == *cargo) {
                it = i;
                break;
            }
        }
        if (it == -1) {
            std::cerr << "Cargo not exist in ship\n";
        } else if (cargo->getAmount() > cargo[it].getAmount()) {
            std::cerr << "Wrong value, you wanna unload more then exist in ship\n";
        } else if (cargo->getAmount() == cargo[it].getAmount()) {
            cargo_.erase(std::remove(cargo_.begin(), cargo_.end(), cargo_[it]), cargo_.end());
        } else {
            *cargo_[it]-= cargo->getAmount();
        }
    }
}

void Ship::nextDay() {
    delegate_->payCrew(crew_);
}
