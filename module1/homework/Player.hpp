#pragma once

#include <memory>

#include "Ship.hpp"



class Player{
private:
    std::shared_ptr<Ship> ship_;
    int money_;
    size_t availableSpace_;
public:
    Player(std::shared_ptr<Ship> ship,int money,size_t space);
    int getMoney() const;
    int getAvalibleSpace() const;
    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;
    void updateAvailableSpace();
};