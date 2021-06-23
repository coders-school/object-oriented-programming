#pragma once
#include "ship.hpp"
#include "cargo.hpp"
#include <memory>

class Player
{
public:
    Player(std::shared_ptr<Ship> ship, uint16_t money_, uint8_t availableSpace_);
    ~Player();

    std::shared_ptr<Ship> getShip() const;
    uint16_t getMoney() const;
    uint16_t getAvailableSpace() const;

private:
    std::shared_ptr<Ship> ship_;
    uint16_t money_;
    uint16_t availableSpace_;

};

