#pragma once
#include <memory>

class Cargo;
class Ship;
// Class responsible for managing Player in the game.
class Player {
public:
    Player(std::shared_ptr<Ship> ship, const size_t& money);

    size_t getMoney() const;
    size_t getAvailableSpace() const;
    std::shared_ptr<Ship> getShip() const;
    size_t getSpeed() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;

    void printCargo() const;

private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    void countAvailableSpace();
};
