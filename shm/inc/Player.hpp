#pragma once

#include <memory>

#include "Cargo.hpp"
#include "Ship.hpp"

class Player {
public:
    Ship* getShip() const;
    size_t getMoney() const;
    size_t getAvailableSpace() const;
    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;

    Player(std::shared_ptr<Ship> ship, size_t money, size_t availableSpace);

private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    size_t calculateAvailableSpace();
};
