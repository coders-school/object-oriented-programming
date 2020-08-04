#include "StockManagement.hpp"
#include <algorithm>

CargoPtr StockManagement::findCargo(const CargoStock& stock_, const CargoPtr& cargo) {
    auto it = std::find_if(begin(stock_), end(stock_),
    [&cargo](const auto& ptr) {
        return  *cargo == *ptr;
    });

    return (it == end(stock_)) ? nullptr : *it;
}

void StockManagement::removeCargoFromStock(CargoStock& stock_, const CargoPtr& cargo, size_t amount) {
    if (amount == cargo->getAmount()) {
        stock_.erase(std::remove(begin(stock_), end(stock_), cargo), stock_.end());
    } else {
        *cargo -= amount;
    }
}

void StockManagement::addCargoToStock(CargoStock& stock_, const CargoPtr& cargo, size_t amount) {
    auto ptr = findCargo(stock_, cargo);

    if(ptr) {
        *ptr += amount;
    } else {
        stock_.push_back(cargo);
    }
}


