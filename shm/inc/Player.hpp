#pragma once

#include <cstddef>
#include <memory>

#include "shm/inc/Delegate.hpp"
#include "shm/inc/Ship.hpp"

class Cargo;

// class responsible for manage user in game
class Player : public Delegate {

public:
    Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace);
    ~Player() override {};

    Ship* getShip() { return ship_.get(); };
    size_t getMoney() const { return money_; };
    size_t getAvailableSpace() const { return availableSpace_.second; };
    size_t getSpeed() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;

    //override from Delegate
    void payCrew(const size_t payCrew) override;
    void setPlayerPtr();
    void buy(const size_t & amount, const size_t & price, const size_t & cargoNumber);

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    std::pair<bool, size_t> availableSpace_;
    size_t countAvailableSpace() const;
};
