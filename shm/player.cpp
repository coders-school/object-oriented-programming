#include "player.hpp"

Player::Player(const Ship& ship,
               int money,
               size_t availableSpace)
    : ship_(std::make_shared<Ship>(ship)),
      money_(money),
      availableSpace_(availableSpace) {}
