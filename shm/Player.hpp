#pragma once

#include "Ship.hpp"
#include "Cargo.hpp"
#include <memory>

// Class responsible for managing player in the game world. Should be only one instance (for now).
class Player {
public:
    Player(std::unique_ptr<Ship> ship, const size_t& money);
    const Ship* getShip() const;
    const Cargo* getCargo(size_t index) const;

    // If player is in a possesion of a ship this method prints out all the cargo from the ship to a screen.
    void printCargoManifest() const;

    size_t getMoney() const;
    size_t getAvailableSpace() const;
    size_t getSpeed() const;

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    void calculateAvailableSpace();
};
