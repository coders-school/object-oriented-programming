#include "StockManagement.hpp"

#include <algorithm>
#include <iostream>

CargoPtr StockManagement::findCargo(const CargoPtr& cargo) {
    auto it = std::find_if(begin(stock_), end(stock_),
                           [&cargo](const auto& ptr) {
                               return *cargo == *ptr;
                           });

    return (it == end(stock_)) ? nullptr : *it;
}

void StockManagement::removeCargoFromStock(const CargoPtr& cargo, size_t amount) {
    auto ptr = findCargo(cargo);

    if (!ptr) {
        return;
    }

    if (amount == cargo->getAmount()) {
        stock_.erase(std::remove(begin(stock_), end(stock_), cargo), stock_.end());
    } else {
        *ptr -= amount;
    }
}

void StockManagement::addCargoToStock(const CargoPtr& cargo, size_t amount) {
    auto ptr = findCargo(cargo);

    if (ptr) {
        *ptr += amount;
    } else {
        stock_.push_back(cargo);
    }
}

CargoPtr StockManagement::getCargo(size_t index) {
    return stock_[index - 1];
}
