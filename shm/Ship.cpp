#include "Ship.hpp"

#include <iostream>

Ship::Ship()
    : _id(-1) {}

Ship::Ship(int id,
           const std::string& name,
           size_t speed,
           size_t maxCrew,
           size_t capacity)
    : _id(id), _name(name), _speed(speed), _maxCrew(maxCrew), _capacity(capacity) {}

Ship::Ship(int id,
           size_t speed,
           size_t maxCrew)
    : Ship(id, "", speed, maxCrew, 0) {}

Ship& Ship::operator+=(const size_t crew) {
    if (_crew + crew > _maxCrew) {
        std::cerr << "To many papays!\n";
        return *this;
    }

    _crew += crew;
    return *this;
}

Ship& Ship::operator-=(const size_t crew) {
    if (_crew < crew) {
        std::cerr << "Number of papays is lower then zero!\n";
        return *this;
    }

    _crew -= crew;
    return *this;
}

std::shared_ptr<Cargo> Ship::getCargo(const size_t id) const {
    if (id < _cargo.size()) {
        return _cargo[id];
    }
    return {};
}
