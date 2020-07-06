#include "ship.hpp"

#include <numeric>

Ship::Ship(int maxCrew, int speed, size_t id, Time* time, Delegate* delegate)
    : Ship(0, maxCrew, speed, "", id, time, delegate)
{}
Ship::Ship(int capacity, int maxCrew, int speed,
        const std::string& name, size_t id, Time* time, Delegate* delegate)
    : capacity_(capacity)
    , maxCrew_(maxCrew) 
    , crew_(0)
    , speed_(speed)
    , name_(name)
    , id_(id)
    , time_(time)
    , delegate_(delegate)
{
    time_->addObserver(this);
}
Ship::~Ship() {
    time_->removeObserver(this);
}

Ship& Ship::operator-=(const size_t crew) {
  if (crew <= crew_) {
    crew_ -= crew;
    return *this;
  }
  return *this;
}
Ship& Ship::operator+=(const size_t crew) {
  if (crew_ + crew <= maxCrew_) {
    crew_ += crew;
    return *this;
  }
  return *this;
}

void Ship::setName(const std::string& name) { name_ = name; }
void Ship::setDelegate(Delegate* delegate) { 
    delegate_ = delegate; }

size_t Ship::getCapacity() const { return capacity_; }
size_t Ship::getMaxCrew() const { return maxCrew_; }
size_t Ship::getCrew() const { return crew_; }
size_t Ship::getSpeed() const { return speed_; }
std::string Ship::getName() const { return name_; }
size_t Ship::getId() const { return id_; }

Cargo* Ship::getCargo(const std::string& name) {
  return Common::getCargo(name, cargo_);
}

size_t Ship::getAvailableSpace() const {
  return Common::getAvailableSpace(capacity_, cargo_);
}

bool Ship::addCargo(Cargo* cargo) {
  bool success = false;
  if (getAvailableSpace() >= cargo->getAmount()) {
    auto ptrCargo = getCargo(cargo->getName());
    if (ptrCargo == nullptr) {
      cargo_.push_back(cargo);
    } else {
      size_t tmpAmount = ptrCargo->getAmount() + cargo->getAmount();
      ptrCargo->setAmount(tmpAmount);
    }
    success = true;
  }
  return success;
}

bool Ship::removeCargo(Cargo* cargo) {
  bool success = false;
  auto it = std::find_if(cargo_.begin(), cargo_.end(), [=](Cargo* el) {
    return el->getName() == cargo->getName();
  });

  if (it != cargo_.end()) {
    cargo_.erase(it);
    success = true;
  }
  return success;
}

void Ship::cloneCargo(Cargo* cargo){
    Cargo* ptr = cargo->clone();
    cargo_.push_back(ptr);
}

void Ship::printCargo() {
    Common::printCargo(cargo_);
}
void Ship::nextDay() {
    if (delegate_) {
        delegate_->payCrew(crew_);
    }
}
