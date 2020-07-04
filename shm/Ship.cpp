#include "Ship.hpp"

#include <algorithm>


Cargo* Ship::getCargo(size_t index) const {
    if (index > cargo_.size()) {
        return nullptr;
    }
    return cargo_[index-1].get();
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

void Ship::unload(Cargo* cargo) {
    if (!cargo->getAmount()) {
        std::remove_if(cargo_.begin(), cargo_.end(), [cargo](const auto& ptr) {
            return ptr.get() == cargo;
        });
    }
}

void Ship::nextDay() {
    if (delegate_) {
        delegate_->payCrew(crew_ * salaryPerWorker); 
    }
    std::for_each(cargo_.begin(), cargo_.end(), [](const auto& el){ el->nextDay(); });
}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string &name, size_t id, std::shared_ptr<Time>& time)
        : capacity_(capacity)
        , maxCrew_(maxCrew)
        , crew_(0)
        , speed_(speed)
        , name_(name)
        , id_(id)
        , time_(time)
{
    time_->addObserver(this);
}

Ship::Ship(int maxCrew, int speed, size_t id, std::shared_ptr<Time>& time)
        : Ship(0, maxCrew, speed, "", id, time) {

}

Ship::Ship()
        : id_(0) {

}