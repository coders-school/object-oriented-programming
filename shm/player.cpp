#include "player.hpp"

Player::Player(std::unique_ptr<Ship> ship, int money, int availableSpace)
    : ship_(ship_.get()), money_(money), availableSpace_(availableSpace)
    {}
