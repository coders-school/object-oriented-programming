#include "Ship.h"

#include <algorithm>

Ship::Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, size_t id, Time* time)
    : capacity_(capacity), max_crew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id), time_(time) {
    time_->subscribe(this);
}

//override from Observer;
Ship::~Ship() {
    time_->unsubscribe(this);
}

void Ship::setName(const std::string& name) {
    name_ = name;
}

Ship& Ship::operator-=(size_t num) {
    if (num >= crew_) {
        crew_ = 0;
    } else {
        crew_ -= num;
    }
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    crew_ += num;
    if (crew_ > max_crew_) {
        crew_ = max_crew_;
    }
    return *this;
}

std::shared_ptr<Cargo> Ship::getCargo(size_t index) {
    return cargos_[index];
}
std::vector<std::shared_ptr<Cargo>> Ship::getCargos() const {
    return cargos_;
}

size_t Ship::getCapacity() const {
    return capacity_;
}

size_t Ship::getMaxCrew() const {
    return max_crew_;
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

void Ship::load(std::shared_ptr<Cargo> cargo) {
    cargos_.push_back(cargo);
}

void Ship::unload(Cargo* cargo) {
    cargos_.erase(std::remove_if(cargos_.begin(), cargos_.end(), [cargo](auto listedCargo) {
        return *cargo == *listedCargo;
    }));
}

void Ship::setPayCrewDelegate(PayCrewDelegate* delegate) {
    crewPayer_ = delegate;
}

void Ship::nextDay() {
    if (!crewPayer_) {
        return;
    }

    crewPayer_->payCrew(crew_);
}

//override from Observer;
void Ship::update() {
    this->nextDay();
}
