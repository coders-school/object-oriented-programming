#pragma once

#include <memory>

#include "cargo.hpp"
#include "ship.hpp"

class Player {
public:
    Player(std::shared_ptr<Ship> ship, uint16_t money, uint8_t availableSpace);
    ~Player();

    std::shared_ptr<Ship> getShip() const;
    uint16_t getMoney() const;
    uint16_t getAvailableSpace() const;

private:
    std::shared_ptr<Ship> ship_;
    uint16_t money_;
    uint16_t availableSpace_;
};
