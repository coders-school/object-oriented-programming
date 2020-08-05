#include "StockManagement.hpp"

#include <algorithm>
#include <iostream>

CargoPtr StockManagement::findCargo(const CargoStock& stock, const CargoPtr& cargo) {
    auto it = std::find_if(begin(stock), end(stock),
                           [&cargo](const auto& ptr) {
                               return *cargo == *ptr;
                           });

    return (it == end(stock)) ? nullptr : *it;
}

void StockManagement::removeCargoFromStock(CargoStock& stock, const CargoPtr& cargo, size_t amount) {
    if (amount == cargo->getAmount()) {
        stock.erase(std::remove(begin(stock), end(stock), cargo), stock.end());
    } else {
        *cargo -= amount;
    }
}

void StockManagement::addCargoToStock(CargoStock& stock, const CargoPtr& cargo, size_t amount) {
    auto ptr = findCargo(stock, cargo);

    if (ptr) {
        *ptr += amount;
    } else {
        stock.push_back(cargo);
    }
}

CargoPtr StockManagement::getCargo(const CargoStock& stock, size_t index) {
    return stock[index - 1];
}
