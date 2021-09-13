#pragma once
#include <memory>
#include "coordinates.hpp"


class Cargo;
class Ship;
// Class responsible for managing Player in the game.
class Player {
public:
    Player() {};
    Player(std::shared_ptr<Ship> ship, const size_t& money);
    ~Player() = default;
    size_t getMoney() const; 
    size_t getAvailableSpace() const;
    std::shared_ptr<Ship> getShip() const;
    size_t getSpeed() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;

    void printCargo() const;
    void setMoney(size_t money);

    void sell( std::shared_ptr<Cargo> cargo, const size_t& amount);
    void buy ( std::shared_ptr<Cargo> cargo, const size_t& amount);

    void countAvailableSpace();

    Coordinates getPlayerPosition() const;

    void setPlayerPosition(const size_t&, const size_t&);
private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
    Coordinates playerCoordinates_{};
};
