#include "store.hpp"

Store::Store() {
}

Response Store::buy(cargoPtr cargo, size_t amount, Player* player) {
    int totalPrice = cargo->getPrice() * amount;

    if (player->getAvailableSpace() < amount) {
        return Response::lack_of_space;
    } else if (cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    } else if (totalPrice > player->getMoney()) {
        return Response::lack_of_money;
    }
    player->getShip()->load(cargo);
    player->subtractMoney(totalPrice);
    *cargo.get() -= amount;
    return Response::done;
}

Response Store::sell(cargoPtr cargo, size_t amount, Player* player) {
    if (player->getShip()->FindMatchCargo(cargo.get())->getAmount() < amount)
        return Response::lack_of_cargo;

    *cargo.get() += amount;

    size_t money = amount * cargo->getPrice();
    player->addMoney(money);

    return Response::done;
}

void Store::nextDay() {
    for (auto el : cargo_) {
        *el.get() += 1;
    }
}