#include "Ship.hpp"

#include <iostream>

constexpr size_t CREW = 16;

Ship::Ship()
    : _id(-1) {
}

Ship::Ship(int id,
           const std::string& name,
           size_t speed,
           size_t maxCrew,
           size_t capacity,
           Delegate* delegate,
           Time* time)
    : _id(id),
    _name(name),
    _speed(speed),
    _maxCrew(maxCrew),
    _capacity(capacity),
    _crew(CREW),
    _delegate(delegate),
    _time(time){
        _time->addObserver(this);
}

Ship::Ship(int id,
           size_t speed,
           size_t maxCrew,
           Time* time)
    : Ship(id, "", speed, maxCrew, 0, nullptr, time) {
}

Ship::~Ship(){
    _time->removeObserver(this);
}

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

void Ship::nextDay(){
    _delegate->payCrew(_crew);
}

void Ship::showCargo() const {
    for (const auto elem : _cargo)
        elem->showCargo(std::cout);
}
