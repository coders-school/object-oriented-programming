#pragma once

#include <memory>
#include "Cargo.hpp"
#include "Ship.hpp"

// Class responsible for managing player in the game world. Should be only one instance (for now).
class Player {
public:
    Player(std::unique_ptr<Ship> ship, const size_t& money);
    Ship* getShip() const;
    const Cargo* getCargo(size_t index) const;

    // If player is in a possesion of a ship this method prints out all the cargo from the ship to a screen.
    void printCargoManifest() const;

    size_t getMoney() const;
    size_t getAvailableSpace();
    size_t getSpeed() const;

    bool pay(size_t money);
    void income(size_t money);

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    void calculateAvailableSpace();
};
