#include "Ship.hpp"

#include <iostream>
#include <algorithm>

Ship::Ship()
    : id_(0) {
}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, std::shared_ptr<Time>& time)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id), time_(time) {
    time_->addObserver(this);
}

Ship::Ship(int maxCrew, int speed, size_t id, std::shared_ptr<Time>& time)
    : Ship(0, maxCrew, speed, "", id, time) {
}

std::shared_ptr<Cargo> Ship::getCargo(size_t index) const {
    if (index > cargo_.size() || index == 0) {
        return nullptr;
    }
    return cargo_[index - 1];
}

Ship& Ship::operator-=(const size_t crew) {
    if (crew > crew_) {
        crew_ = 0;
        return *this;
    }
    crew_ -= crew;
    return *this;
}

Ship& Ship::operator+=(const size_t crew) {
    if (crew_ + crew > maxCrew_) {
        crew_ = maxCrew_;
        return *this;
    }
    crew_ += crew;
    return *this;
}

void Ship::load(const std::shared_ptr<Cargo>& cargo) {
    cargo_.push_back(cargo);
}

void Ship::unload(const std::shared_ptr<Cargo>& cargo, size_t amount) {
    if (amount == cargo->getAmount()) {
        cargo_.erase(std::remove(begin(cargo_), end(cargo_), cargo), cargo_.end());
    } else {
        *cargo -= amount;
    }
}

void Ship::print() const {
    size_t i = 1;
    for(const auto& el : cargo_) {
        std::cout << i << ". " <<  el->getName() << " | Amount: " << el->getAmount() << " Price: " << el->getPrice() << "\n";
        i++; 
    }
}

void Ship::nextDay() {
    if (delegate_) {
        delegate_->payCrew(crew_ * salaryPerWorker);
    }
    std::for_each(cargo_.begin(), cargo_.end(), [](const auto& el) { el->nextDay(); });
}
