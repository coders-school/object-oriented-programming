#include "Player.hpp"

size_t Player::getAvailableSpace()
{
    availableSpace_ = 0;
    for (const auto cargo : ship_->getCargos()) {
        availableSpace_ += cargo->getAmount();
    }
    return ship_->getCapacity() - availableSpace_;
}
