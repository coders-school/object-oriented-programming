#pragma once
#include <memory>

#include "Cargo.hpp"
#include "Ship.hpp"

class Player {
public:
    Player(Ship ship, size_t money);

    size_t getMoney() const { return _money; }
    size_t getAvailableSpace() const { return _availableSpace; }
    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;

private:
    std::unique_ptr<Ship> _ship;
    size_t _money;
    size_t _availableSpace;

    void updateAvailableSpace();
};
