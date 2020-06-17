#pragma once
#include <memory>

#include "Cargo.hpp"
#include "Ship.hpp"

class Player {
public:
    Player(Ship ship, size_t money)
        : _ship(std::make_shared<Ship>(ship)), _money(money) {}

    std::shared_ptr<Ship> getShip() const { return _ship; }
    size_t getMoney() const { return _money; }
    size_t getAvailableSpace() const { return _availableSpace; }

private:
    std::shared_ptr<Ship> _ship;
    size_t _money;
    size_t _availableSpace;
};