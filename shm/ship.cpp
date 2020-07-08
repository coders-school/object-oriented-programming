#include "ship.hpp"

#include <algorithm>
#include <numeric>

Ship::Ship() : id_(-1) {}

Ship::Ship(size_t capacity,
           size_t maxCrew,
           size_t speed,
           const std::string& name,
           int id,
           std::shared_ptr<Time> publisher)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id), publisher_(publisher) {
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
        --crew_;
        break;
    case 6:
        std::cout << "One of your sailor died because of malaria!\n";
        --crew_;
        break;
    case 15:
        std::cout << "One of your sailor rebelled and drowned under the keel\n";
        --crew_;
        break;
    case 20:
        std::cout << "You lost half of your crew during battle with pirates!\n";
        crew_ = crew_ / 2;
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
    }
    return *this;
}

Ship& Ship::operator+=(size_t crewman) {
    if (crew_ + crewman < maxCrew_) {
        crew_ += crewman;
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

        return maxCrew_ - previousCrew;
    }
    std::cout << "You have maximum number of sailors!\n";
    return 0;
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