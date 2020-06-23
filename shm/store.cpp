#include "store.hpp"

Store::Store() {}

// Store::Response buy(const Cargo* cargo, size_t amount, Player* player) {
Store::Response buy(std::shared_ptr<Cargo> cargo, size_t amount, Player* player) {
    const size_t price = amount * cargo->getBasePrice();

    if (amount > player->getAvailableSpace()) {
        return Store::Response::lack_of_space;
    }
    if (amount > cargo->getAmount()) {
        return Store::Response::lack_of_cargo;
    }
    if (price > player->getMoney()) {
        return Store::Response::lack_of_money;
    }

    player->purchaseCargo(cargo, amount, price);
    *cargo -= amount;

    return Store::Response::done;
}
Store::Response sell(Cargo* cargo, size_t amount, Player* player) {
    return Store::Response::done;
}
