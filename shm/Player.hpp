#pragma once

#include "Ship.hpp"
#include "Cargo.hpp"

#include <memory>

class Player {
public:
    Player(std::unique_ptr<Ship> ship, size_t money);

    size_t getMoney() const;
    int getSpeed() const;
    Cargo* getCargo(size_t index) const;

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t avaibleSpace_;
};