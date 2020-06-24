#include "player.hpp"

Player::Player(const Ship& ship,
               int money,
               size_t availableSpace)
    : ship_(std::make_shared<Ship>(ship)),
      money_(money),
      availableSpace_(availableSpace) {}

size_t Player::calcAvailableSpace() {
    availableSpace_ = 0;
    for (const auto el : ship_->getCargos()) {
        availableSpace_ += el->getAmount();
    }
    return availableSpace_;
}
