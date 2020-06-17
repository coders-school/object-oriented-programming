#pragma once

#include <memory>

#include "Ship.cpp"

class Player {
private:
    std::shared_ptr<Ship> ship_;
    int money_;
    size_t availableSpace_;

public:
    std::shared_ptr<Ship> GetShip_() const { return ship_; };
    int GetMoney_() const { return money_; };
    size_t GetAvailableSpace_() const { return availableSpace_; };

    size_t getSpeed() const { return ship_->GetSpeed_(); };
    Cargo* getCargo(size_t index) const {return ship_->Get};

    Player(std::shared_ptr<Ship> ship,
           int money,
           size_t availableSpace)
        : ship_(std::make_shared<Ship>(ship)),
          money_(money),
          availableSpace_(availableSpace) {}
};
