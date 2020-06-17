#include "player.hpp"

#include <algorithm>

size_t Player::calculateavailableSpace() {
    size_t reservedSpace = 0;
    std::for_each(ship_->getallCargo().begin(),
                  ship_->getallCargo().end(),
                  [&reservedSpace](const Cargo& cargo) {
                      reservedSpace += cargo.getAmount();
                  });
    size_t freeSpace = ship_->getmaxCapacity() - reservedSpace;

    return freeSpace;
}