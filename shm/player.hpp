#pragma once

#include <memory>

#include "cargo.hpp"
#include "ship.hpp"

class Coordinates;
class Player {
public:
    Player(std::shared_ptr<Ship> ship, size_t money, size_t space);
    Player(std::shared_ptr<Ship> ship);

    size_t getMoney() const { return money_; }
    void   giveMoney(size_t money);
    void   takeMoney(size_t money);
    size_t getAvailableSpace();
    size_t getSpeed() const;
    void   giveCargo(Cargo* cargo);
    void   removeCargo (Cargo* cargo);
    Cargo* getCargoWithName(std::string name);
    Cargo* getCargo(size_t index) const;

private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
    size_t countAvailableSpace();
    Coordinates* ActualPosition;
};
