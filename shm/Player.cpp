#include "Player.hpp"

#include <numeric>

Player::Player(std::unique_ptr<Ship> ship, size_t money) {
    ship_ = std::move(ship);
    money_ = money;
    avaliableSpace_ = countAvailableSpace();
};

size_t Player::countAvailableSpace() {
    auto occupiedSpace = std::accumulate(begin(ship_->getAllCargos()),
                                         end(ship_->getAllCargos()),
                                         0,
                                         [](int accumulated, const auto& cargo) {
                                             return accumulated + cargo->getAmount();
                                         });

    if (ship_->getCapacity() <= occupiedSpace) {
        return 0;
    }
    return ship_->getCapacity() - occupiedSpace;
}
