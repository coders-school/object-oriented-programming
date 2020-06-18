#pragma once

#include <memory>

#include "ship.cpp"

class Player {
private:
    std::shared_ptr<Ship> ship_;
    int money_;
    size_t availableSpace_;

public:
    std::shared_ptr<Ship> GetShip_() const;
    int GetMoney_() const;
    size_t GetAvailableSpace_() const;

    size_t GetSpeed() const;
    Cargo* GetCargo(size_t index) const;

    Player(const Ship& ship,
           int money,
           size_t availableSpace)
        : ship_(std::make_shared<Ship>(ship)),
          money_(money),
          availableSpace_(availableSpace) {}
};
