#pragma once
#include "Storable.hpp"
#include <memory>
#include "ship.hpp"

class Cargo;
//Class responsible for handling Player object
class Player : public Storable{
private:
    std::unique_ptr<Ship> ship_;
    size_t calculateAvailableSpace(); //calculates space available on the ship based on cargo and ship capacity

public:
    Player(std::unique_ptr<Ship> ship, int money, int availableSpace);
    ~Player();//{std::cout << "ten działa?(Player)";}
    const std::unique_ptr<Ship>& getShip();
    size_t getSpeed() const;
    
    std::shared_ptr<Cargo> getCargo(size_t index) const override;
    void setCrew(size_t newCrewSize);
};
