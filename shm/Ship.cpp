#include "Ship.hpp"

#include <iostream>

Ship::Ship()
    : id_(-1) {}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
    : capacity_(capacity),
      maxCrew_(maxCrew),
      crew_(0),
      speed_(speed),
      name_(name),
      id_(id) {}

Ship::Ship(int maxCrew, int speed, size_t id)
    : Ship(0, maxCrew, speed, "", id) {}

Ship& Ship::operator-=(size_t num) {
    if (num > crew_) {
        std::cerr << "Number of papays is lower than 0\n";
        return *this;
    }
    crew_ -= num;
    return *this;
}
Ship& Ship::operator+=(size_t num) {
    if (crew_ + num > maxCrew_) {
        std::cerr << "Too many papays!\n";
        return *this;
    }
    crew_ += num;
    return *this;
}
