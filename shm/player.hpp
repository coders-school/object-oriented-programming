#pragma once
#include "Storable.hpp"
#include <memory>
#include "ship.hpp"

class Cargo;
//Class responsible for handling Player object
class Player : public Storable{
private:
    std::string playerName_;
    std::unique_ptr<Ship> ship_;
    size_t calculateAvailableSpace(); //calculates space available on the ship based on cargo and ship capacity

public:
    Player(std::unique_ptr<Ship> ship, int money, int availableSpace);
    ~Player();
    const std::unique_ptr<Ship>& getShip();
    size_t getSpeed() const;
    void setName(std::string playerName) {playerName_ = playerName;}
    std::string getName() {return playerName_;}
    
    Cargo * getCargo(size_t) const override;
    
    void setCrew(size_t newCrewSize);

    void setStartingCargo();
};
