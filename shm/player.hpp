#pragma once

#include <memory>

#include "cargo.hpp"
#include "ship.hpp"

class Player {
public:
    Player(std::shared_ptr<Ship> ship, size_t money, size_t availableSpace);
    ~Player();

    // getters
    size_t getMoney() const;
    size_t getAvailableSpace() const;
    std::shared_ptr<Ship> getShip() const;
    size_t getSpeed() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;


private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    //metods
   // size_t availableSpace();
};
