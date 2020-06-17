
#include "Player.hpp"

class Player {
private:
    std::shared_ptr<Ship> ship_;
    int money_;
    size_t availableSpace_;

public:
    std::shared_ptr<Ship> GetShip_() const { return ship_; };
    int GetMoney_() const { return money_; };
    size_t GetAvailableSpace_() const { return availableSpace_; };

    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;
};
