
#include "player.hpp"

class Player {
private:
    std::shared_ptr<Ship> ship_;
    int money_;
    size_t availableSpace_;

public:
    std::shared_ptr<Ship> GetShip() const { return ship_; };
    int GetMoney() const { return money_; };
    size_t GetAvailableSpace() const { return availableSpace_; };

    size_t GetSpeed() const { return ship_->GetSpeed(); };
    Cargo* GetCargo(size_t index) const { ship_->GetCargo(index); };

    Player(const Ship& ship,
           int money,
           size_t availableSpace)
        : ship_(std::make_shared<Ship>(ship)),
          money_(money),
          availableSpace_(availableSpace) {}
};
