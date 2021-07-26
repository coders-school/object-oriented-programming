#include "Ship.hpp"
#include "Cargo.hpp"
//#include "Delegate.hpp"
//#include "Tieme.hpp"

#include <algorithm>

Ship::Ship()
    : Ship(0, 0, 0, "", -1, nullptr)
{}

Ship::Ship(int maxCrew, int speed, size_t id)
    : Ship(0, maxCrew, speed, "", id, nullptr)
{}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, Time* time)
    : name_(name)
    , capacity_(capacity)
    , maxCrew_(maxCrew)
    , id_(id)
    , crew_(0)
    , speed_(speed)
    , time_(time)
    , cargo_()
{}

// ~ Ship::Ship() override;

void Ship::setName(const std::string& name) { name_ = name; }

Ship& Ship::operator-=(size_t num) {
    crew_ = (crew_ > num)? crew_ - num : 0;
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    crew_ = (crew_ + num < maxCrew_)? crew_ + num : maxCrew_;
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

std::string Ship::getName() const { 
    return name_; 
}

size_t Ship::getId() const { 
    return id_; 
}

std::vector<std::unique_ptr<Cargo>>& Ship::getCargo() {
    return cargo_;
}

// void Ship::printCargo() const;

void Ship::load(std::unique_ptr<Cargo> cargo) {
    cargo_.push_back(std::move(cargo));
}

void Ship::unload(Cargo* cargo) {
    if (!cargo) {
        return;
    }
    auto result = std::find_if(cargo_.begin(), cargo_.end(), [cargo](const auto& el) { return el.get() == cargo; } );
    if (result != cargo_.end()) {
        std::iter_swap(result, (cargo_.end() - 1));
        cargo_.pop_back();
    }
}

Cargo* Ship::getCargo(const size_t index) const { 
    if (index < cargo_.size()) {            
        return cargo_[index].get();
    }
    return nullptr; 
}

// Cargo* Ship::findMatchCargo(Cargo* cargo);

// void Ship::RemoveFromStorage(Cargo* cargo);

void Ship::nextDay() {

}
