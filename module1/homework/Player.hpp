#pragma once

#include<memory>

#include "Ship.hpp"

class Player{
private:
    std::shared_ptr<Ship> ship_;
    int money;
}