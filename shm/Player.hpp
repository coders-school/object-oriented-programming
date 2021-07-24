#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include <vector>

#include "Cargo.hpp"
#include "Ship.hpp"

// Class used to represent player 
class Player {
private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
    size_t calculateAvailableSpace();
    

public:
    Player(std::unique_ptr<Ship>& ship, int money, int availableSpace);

    std::unique_ptr<Ship> getShip() { return std::move(ship_); };
    size_t getMoney() const { return money_; };
    size_t getAvailableSpace() const { return availableSpace_; };
    
    void printCargo() const;

    size_t getSpeed() const { return ship_->getSpeed(); };
    std::shared_ptr<Cargo> getCargo(size_t index) const;
};

#endif