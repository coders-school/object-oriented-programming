#include "Ship.hpp"

Ship::Ship()
    : id_(-1) {}
Ship::Ship(size_t id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity)
    : id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity), crew_(0) {}
Ship::Ship(size_t id, size_t speed, size_t maxCrew)
    : Ship(id, "", speed, maxCrew, 0) {}

void Ship::setName(const std::string& name) {
    name_ = name;
}

Ship& Ship::operator+=(size_t newCrewMembers) {
    if (crew_ + newCrewMembers > maxCrew_) {
        std::cerr << "YThe number of crew members cannot be greater than: " << maxCrew_ << "!" << '\n';
        return *this;
    }
    crew_ += newCrewMembers;
    return *this;
}
Ship& Ship::operator-=(size_t retireesCrewMembers) {
    if (crew_ - retireesCrewMembers > crew_) {
        std::cerr << "The number of crew members cannot be less than zero!" << '\n';
        return *this;
    }
    crew_ -= retireesCrewMembers;
    return *this;
}

size_t Ship::getId() const {
    return id_;
}
std::string Ship::getName() {
    return name_;
}
size_t Ship::getSpeed() const {
    return speed_;
}
size_t Ship::getMaxCrew() const {
    return maxCrew_;
}
size_t Ship::getCapacity() const {
    return capacity_;
}