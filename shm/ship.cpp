#include "ship.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>

Ship::Ship() : id_(-1) {}

Ship::Ship(size_t capacity,
           size_t maxCrew,
           size_t maxSpeed,
           const std::string& name,
           int id,
           std::shared_ptr<Time> publisher)
    : capacity_(capacity), 
    maxCrew_(maxCrew), 
    crew_(0), 
    maxSpeed_(maxSpeed), 
    speed_(maxSpeed),
    name_(name), 
    id_(id), 
    publisher_(publisher) {
    this->publisher_->addObserver(this);
    }


void Ship::setName(const std::string& name) {
    name_ = name;
}

void Ship::nextDay() {
    int lottery = (rand() % 10 + 1) + (rand() % 10 + 1);
    switch (lottery) {
    case 1:
        std::cout << "One of your sailor has drown!\n";
        if (crew_ >= 1) {
            --crew_;
        } else {
            crew_ = 0;
        }
        break;
    case 6:
        std::cout << "One of your sailor died because of malaria!\n";
        if (crew_ >= 1) {
            --crew_;
        } else {
        std::cout << "You lost all of your crew";
            crew_ = 0;
        }
        break;
    case 15:
        if (crew_ >= 1) {
            std::cout << "One of your sailor rebelled and drowned under the keel\n";
            --crew_;
        } else {
            std::cout << "You lost all of your crew";
            crew_ = 0;
        }
        break;
    case 20:
        if (crew_ >= 2) {
            std::cout << "You lost half of your crew during battle with pirates!\n";
            crew_ = crew_ / 2;
        } else {
            std::cout << "You lost all of your crew during battle with pirates!\n";
            crew_ = 0;
        }
        break;
    default:
        std::cout << "Fortunately today everyone are still alive!\n";
    }

}

void Ship::load(std::shared_ptr<Cargo> cargo, size_t amount) {
    auto it = findSameCargo(cargo.get());

    if (it != cargo_.end()) {
        *it->get() += amount;
    } else {
        auto newCargo = cargo->Clone();
        newCargo->setAmount(amount);
        cargo_.push_back(newCargo);
    }
}

Ship& Ship::operator-=(size_t crewman) {
    if (crew_ > crewman) {
        crew_ -= crewman;
        speed_ = static_cast<int>(static_cast<double>(maxSpeed_)*(static_cast<double>(crew_) / static_cast<double>(maxCrew_)));
        return *this;
    }
    if (crew_ == crewman){
        crew_ = 0;
        speed_ = 0;
        return *this;
    }
    else return *this;
}

Ship& Ship::operator+=(size_t crewman) {
    if (crew_ + crewman <= maxCrew_) {
        crew_ += crewman;
        speed_ = static_cast<int>(static_cast<double>(maxSpeed_)*(static_cast<double>(crew_) / static_cast<double>(maxCrew_)));
    }
    return *this;
}

size_t Ship::getCapacity() const {
    return capacity_;
}

size_t Ship::getCrew() const {
    return crew_;
}

size_t Ship::getMaxCrew() const {
    return maxCrew_;
}

size_t Ship::getMaxSpeed() const {
    return maxSpeed_;
}
void Ship::setSpeed(double actualSpeed){
    speed_ = static_cast<int>(actualSpeed);
}

size_t Ship::getSpeed() const {
    return speed_;
}

std::string Ship::getName() const {
    return name_;
}

int Ship::getId() const {
    return id_;
}

Cargo* Ship::getCargo(size_t index) const {
    if (cargo_.size() > index) {
        return cargo_[index].get();
    }
    return nullptr;
}

size_t Ship::countAvailableSpace() const {
    size_t loadedSpace = std::accumulate(cargo_.begin(), cargo_.end(), 0,
                                         [=](size_t item, const auto& cargo) { return item += cargo->getAmount(); });
    return capacity_ - loadedSpace;
}

size_t Ship::fillInCrew() {
    if (crew_ < maxCrew_) {
        size_t previousCrew = crew_;
        crew_ = maxCrew_;
        std::cout << "You hired: " << (maxCrew_ - previousCrew) << " sailors\n";
        std::cout << "You paid for them: " << maxCrew_ - previousCrew << '\n';
        std::cout << "Your speed is maximum: " << maxSpeed_ << " knots\n";
        speed_ = maxSpeed_;
        return maxCrew_ - previousCrew;
    }
    else {
        std::cout << "You have maximum number of sailors!\n";
        return 0;
        }

}


Cargo* Ship::findCargoByName(const std::string& name) const {
    auto found =
        std::find_if(cargo_.begin(), cargo_.end(), [name](const auto element) { return name == element->getName(); });
    if (found != cargo_.end()) {
        return (*found).get();
    }
    return nullptr;
}

Cargo* Ship::findCargo(Cargo* cargo) const {
    auto found =
        std::find_if(cargo_.begin(), cargo_.end(), [&cargo](const auto element) { return *cargo == *element; });
    if (found != cargo_.end()) {
        return (*found).get();
    }
    return nullptr;
}


void Ship::removeCargo(Cargo* cargo) {
    cargo_.erase(
        std::find_if(cargo_.begin(), cargo_.end(), [&cargo](const auto& element) { return *element == *cargo; }));
}


void Ship::printCargo() const {
    std::for_each(cargo_.begin(), cargo_.end(), [i{0}](const auto& index) mutable {
        std::cout << ++i << "* ";
        std::cout << index->getName() << ": " << index->getAmount();
    });
}

CargoIt Ship::findSameCargo(Cargo* cargo) {
    Fruit* fruit = dynamic_cast<Fruit*>(cargo);
    Alcohol* alcohol = nullptr;
    Item* item = nullptr;
    CargoIt result = cargo_.end();

    if (fruit) {
        result = findIdenticalCargo(fruit);
    } else if (alcohol = dynamic_cast<Alcohol*>(cargo)) {
        result = findIdenticalCargo(alcohol);
    } else if (item = dynamic_cast<Item*>(cargo)) {
        result = findIdenticalCargo(item);
    }

    return result;
}

template <class T>
CargoIt Ship::findIdenticalCargo(T* concreteCargo) {
    auto it = std::find_if(cargo_.begin(), cargo_.end(), [concreteCargo](const auto& cargo){
        T* t = dynamic_cast<T*>(cargo.get());

        if(t){
            return *concreteCargo == *t;
        }
        else {
            return false;
        }
    });

    return it;
}

