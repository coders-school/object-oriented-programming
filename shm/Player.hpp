#pragma once

#include <memory>

#include "Cargo.hpp"
#include "Delegate.hpp"
#include "Ship.hpp"

class Player : public Delegate {
public:
    Player(std::unique_ptr<Ship>& ship, size_t money);  //I need to pass ship as & to construct Player in main() like this:
                                                        //      auto mnShip = std::make_unique<Ship>(150,200, 20, "TEST", 666);
                                                        //      Player mnPlayer(mnShip, 1000);

    size_t getMoney() const { return money_; };
    size_t getAvaliableSpace() const { return avaliableSpace_; };
    size_t getSpeed() const { return ship_->getSpeed(); };
    Cargo* getCargo(size_t index) const { return ship_->getCargo(index); };

    //override from Delegate
    void payCrew(size_t money) override;

    void callNextDay() {ship_->nextDay();} //TEMPORARY FOR TESTING ONLY

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t avaliableSpace_;

    size_t countAvailableSpace();
};
