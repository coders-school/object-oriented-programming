#include "store.hpp"

#include <algorithm>
#include <random>

Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    if (cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    }

    auto totalPrice = amount * cargo->getPrice();
    player->changeMoney(totalPrice);
    receiveCargo(cargo, amount, player);
    return Response::done;
}

Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    if (player->getavailableSpace() < amount) {
        return Response::lack_of_space;
    }

    auto totalPrice = amount * cargo->getPrice();
    if (player->getMoney() < totalPrice) {
        return Response::lack_of_money;
    }

    auto cargoIt = std::find_if(cargo_.begin(), cargo_.end(), [cargo](auto& cargoPtr) { return cargoPtr.get() == cargo; });
    if (cargoIt == cargo_.end() or (*cargoIt)->getAmount() < amount) {
        return Response::lack_of_cargo;
    }

    player->changeMoney(-totalPrice);
    player->receiveCargo(cargo, amount, this);
    return Response::done;
}

void Store::receiveCargo(Cargo* cargo, size_t amount, CargoHolder* cargoHolder) {
    auto clonedCargo = cargo->cloneToShared();
    (*clonedCargo) -= (clonedCargo->getAmount() - amount);
    (*cargo) -= amount;
    if (cargo->getAmount() == 0) {
        cargoHolder->clearEmptyCargos();
    }
    cargo_.push_back(clonedCargo);
}

void Store::clearEmptyCargos() {
    cargo_.erase(std::remove_if(cargo_.begin(), cargo_.end(), [](auto& cargo) { return cargo->getAmount() == 0; }), cargo_.end());
}

void Store::nextDay() {
    constexpr size_t addItems = 1;
    constexpr size_t removeItems = 0;
    constexpr size_t minQuantityOfProducts = 40;
    constexpr size_t maxQuantityOfProducts = 100;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> optionDistrib(removeItems, addItems);
    std::uniform_int_distribution<> quantityDistrib(minQuantityOfProducts, maxQuantityOfProducts);

    size_t option = optionDistrib(gen);

    if (option == addItems) {
        for (auto& item : cargo_) {
            *item += quantityDistrib(gen);
        }
    } else if (option == removeItems) {
        for (auto& item : cargo_) {
            *item -= quantityDistrib(gen);
        }
    }
}
