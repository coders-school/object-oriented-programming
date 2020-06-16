#include "Player.hpp"

size_t countAvailableSpace() {
    auto total = std::accumulate(begin(ship_->getAllCargos()), end(ship_->getAllCargos()), 0, [](const auto& cargo) {
        cargo->getAmount();
    });
    if (ship_->getCapacity() <= total) {
        return 0;
    }
    return ship_->getCapacity() - total;
}