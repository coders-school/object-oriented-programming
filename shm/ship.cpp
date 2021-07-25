#include <algorithm>
#include <iterator>
#include <memory>
#include "ship.hpp"

Ship::Ship()
    : id_(-1), crew_(0), capacity_(0), maxCrew_(0), speed_(0), name_(""), cargo_({}) {}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, std::vector<std::shared_ptr<Cargo>> cargo, size_t coins)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id), cargo_(cargo), coins_(coins) {}

Ship::Ship(int maxCrew, int speed, size_t id, std::vector<std::shared_ptr<Cargo>> cargo)
    : Ship(0, maxCrew, speed, "", id, cargo, 100) {}    //initialization of default capacity = 0, lack of ship name and default amount of coins = 100

size_t Ship::getAmountOfCargosCapacity() const {
    auto Cargos = getCargo();
    size_t returnAmount{};
    if (Cargos.size() != 0) {
        for (auto& shipCargo : Cargos) {
            returnAmount += shipCargo->getAmount();
        }
    }
    return returnAmount;
}
Ship& Ship::operator-=(size_t num) {
    if (crew_ > num) {
        crew_ -= num;
    } else if (crew_ < num) {
        crew_ = 0;
    }
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    crew_ += num;
    if (crew_ > maxCrew_) {
        crew_ = maxCrew_;
    }
    return *this;
}

void Ship::addAmounntToShipCargo(std::shared_ptr<Cargo> cargo, size_t amount) {
    auto VecOfcargos = getCargo();
    for (auto it = VecOfcargos.begin(); it < VecOfcargos.end(); ++it) {
        if ((*it)->getName() == cargo->getName()) {
            if (capacity_ >= (getAmountOfCargosCapacity() + amount)) {
                (*it)->addAmount(amount);
            }
        }
    }
}

void Ship::dellAmounntFromShipCargo( std::shared_ptr<Cargo> cargo, size_t amount ) {
    auto VecOfcargos = getCargo();
    for (auto it = VecOfcargos.begin(); it < VecOfcargos.end(); ++it) {
        if ((*it)->getName() == cargo->getName()) {
            (*it)->dellAmount(amount);
        }
    }
}

// crew wages for 1 work day
// in game.hpp make this function work when "dayNr.endCurrentDay()" in time.hpp happens
size_t nextDay(size_t crew, size_t coins) {
    for(int i = 0; i < crew; i++) {
        coins -= 1;
    }
    return coins;
}
