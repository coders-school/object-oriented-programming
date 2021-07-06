#pragma once

#include "Ship.hpp"
#include "Cargo.hpp"
#include <memory>

// Class responsible for managing player in the game world. Should be only one instance (for now).
class Player {
public:
    Player(std::unique_ptr<Ship> ship, const size_t& money);

    // Returns constant raw pointer to ship in players possesion if one exists, otherwise returns nullptr.
    Ship* getShip() const;

    // Returns constant raw pointer to cargo instance of index in cargo vector provided as a parameter.
    // If cargo object doesn't exist - returns nullptr
    const Cargo* getCargo(size_t index) const;

    // If player is in a possesion of a ship this method prints out all the cargo from the ship to a screen.
    void printCargoManifest() const;

    size_t getMoney() const;
    size_t getAvailableSpace();
    size_t getSpeed() const;

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    void calculateAvailableSpace();
};
