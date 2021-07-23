#include "shm/inc/Ship.hpp"

#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "shm/inc/Cargo.hpp"
#include "shm/inc/Delegate.hpp"
#include "shm/inc/Player.hpp"
#include "shm/inc/Store.hpp"

Ship::Ship(int id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity, Time* time, Delegate* delegate)
    : id_(id)
    , name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , capacity_(capacity)
    , time_(time)
    , delegate_(delegate)
{
    time_->addSubscriber(this);
}

Ship::Ship(int id, size_t speed, size_t maxCrew, Time* time, Delegate* delegate) 
    : Ship(id, "Ship", speed, maxCrew, 100, time, delegate)
{}

Ship& Ship::operator+=(const size_t crew) {
    if (crew_ + crew > maxCrew_) {
        //throw std::out_of_range("Too many sailors!\n");
        std::cout << "Too many sailors!\n";
        return *this;
    }
    crew_ += crew;
    return *this;
}

Ship& Ship::operator-=(const size_t crew) {
    if (crew_ < crew) {
        // throw std::out_of_range("Number of sailors lower than zero!");
        std::cout << "Number of sailors can't be lower than zero! You can dismiss " << crew_ << '\n';
        return *this;
    }
    crew_ -= crew;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Ship& ship) {
    for (size_t i = 0; i < ship.cargo_.size(); i++) {
        out << "|" << std::setfill('-') << std::setw(100) << "|\n";
        out << std::setfill(' ')<< std::setw(10) << "| ID: " << i + 1;
        out << std::setw(30) << " | CARGO NAME: " << ship.cargo_[i]->getName();
        out << std::setw(10) << " | AMOUNT: " << ship.cargo_[i]->getAmount();
        Cargo* cargo = ship.cargo_[i].get();
        if (typeid(cargo) == typeid(Alcohol)) {
            const Alcohol* alcohol = static_cast<const Alcohol*>(ship.cargo_[i].get());
            out << std::setw(10) << " | PERCENTAGE: " << alcohol->getPercentage() << " |\n";
        }
        if (typeid(cargo) == typeid(Fruit)) {
            const Fruit* fruit = static_cast<const Fruit*>(ship.cargo_[i].get());
            out << std::setw(10) << " | TIME TO ROTTEN: " << fruit->getRottenTime() << " |\n";
        }
        if (typeid(cargo) == typeid(DryFruit)) {
            const DryFruit* dryFruit = static_cast<const DryFruit*>(ship.cargo_[i].get());
            out << std::setw(10) << " | TIME TO ROTTEN: " << dryFruit->getRottenTimeForDryFruit() << " |\n";
        } 
        if (typeid(cargo) == typeid(Item)) {
            const Item* item = static_cast<const Item*>(ship.cargo_[i].get());
            out << std::setw(10) << " | RARITY: ";
            switch (item->getRarity()) {
            case (Item::Rarity::common):
                out << "common"; break;
            case (Item::Rarity::rare):
                out << "rare"; break;
            case (Item::Rarity::epic):
                out << "epic"; break;
            case (Item::Rarity::legendary):
                out << "legendary"; break;
            }
            out << " |\n";
        }   
    }
    out << "|" << std::setfill('-') << std::setw(100) << "|\n";
    return out;
}

void Ship::setName(const std::string& name) {
    name_ = name;
}

Cargo* Ship::getCargo(size_t index) const {
    if (index >= cargo_.size()) {
        throw std::out_of_range("Invalid cargo!");
    }
    return cargo_[index].get();
}

Cargo* Ship::getCargo(const std::string& name) const {
    auto result{ std::find_if(cargo_.begin(), cargo_.end(),
                             [&name](const auto& cargo) {
                                return cargo->getName() == name ;
                             })
    };
    
    return result != cargo_.end() ? result->get() : nullptr;
}

void Ship::load(Cargo* cargo, size_t amount) {
    if (cargo) {
        bool ifFindCargo = false;
        for (auto & searchCargo : cargo_) {
            if (searchCargo->getName() == cargo->getName()) {
                searchCargo->setAmount(searchCargo->getAmount() + amount);
                ifFindCargo = true;
            }
        }
        if (ifFindCargo == false) {
            addCargo(cargo, amount);
        }
    }
}

void Ship::unload(Cargo* cargo, size_t amount) {
    if (cargo) {
        for (auto & searchCargo : cargo_) {
            if (searchCargo->getName() == cargo->getName()) {
                searchCargo->setAmount(searchCargo->getAmount() - amount);
            }
        }
    }
}

void Ship::nextDay() {
    delegate_->payCrew(crew_);
    for (size_t i = 0; i < cargo_.size(); i++) {
        if (cargo_[i]->isExpired() == true) {
            std::cout << cargo_[i]->getAmount() << ' ' << cargo_[i]->getName() 
                      << " was completty rotten and the captain threw overboard\n";
            cargo_.erase(std::remove(cargo_.begin(), cargo_.end(), cargo_[i]), cargo_.end());
        }
    }
}

void Ship::changeDelegate(Player* player) {
    delegate_ = player;
}

void Ship::addCargo(Cargo* cargo, size_t amount) {
    if (typeid(*cargo) == typeid(Alcohol)) {
        Alcohol* alcohol = static_cast<Alcohol*>(cargo);
        cargo_.push_back(std::make_unique<Alcohol>(alcohol->getName(),
                                                   amount,
                                                   alcohol->getBasePrice(),
                                                   alcohol->getPercentage()));
    } else if (typeid(cargo) == typeid(Fruit)) {
        Fruit* fruit = static_cast<Fruit*>(cargo);
        cargo_.push_back(std::make_unique<Fruit>(fruit->getName(),
                                                 amount,
                                                 fruit->getBasePrice()));
    } else if (typeid(cargo) == typeid(DryFruit)) {
        DryFruit* fruit = static_cast<DryFruit*>(cargo);
        cargo_.push_back(std::make_unique<DryFruit>(fruit->getName(),
                                                    amount,
                                                    fruit->getBasePrice()));
    } else if (typeid(cargo) == typeid(Item)) {
        Item* item = static_cast<Item*>(cargo);
        cargo_.push_back(std::make_unique<Item>(item->getName(),
                                                amount,
                                                item->getBasePrice(),
                                                item->getRarity()));
    }
}
