#pragma once

#include <memory>
#include "Cargo.hpp"
#include "Ship.hpp"

class Player
{
public:
    Player(Ship ship, size_t money, size_t space) : money_(money), availableSpace_(space)
    {
        ship_ = std::make_unique<Ship>(std::move(ship));
    };

    [[nodiscard]] size_t getAvailableSpace() const;
    [[nodiscard]] size_t getMoney() const;
    [[nodiscard]] size_t getSpeed() const;
    [[nodiscard]] Cargo* getCargo(size_t index) const;

    void setMoney(size_t amount);
private:

    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    void updateAvailableSpace();
};
