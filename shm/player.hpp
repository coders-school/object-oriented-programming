#pragma once

#include <memory>
class Ship;
class Cargo;
//Class responsible for handling Player object
class Player {
private:
    std::unique_ptr<Ship> ship_;
    int money_;
    size_t availableSpace_;
    size_t calculateAvailableSpace(); //calculates space available on the ship based on cargo and ship capacity
    size_t gettingCargoAmount();

public:
    Player(std::unique_ptr<Ship> ship, int money, int availableSpace);

    const std::unique_ptr<Ship>& getShip();
    int getMoney();
    size_t getAvailableSpace();

    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;

    
};
