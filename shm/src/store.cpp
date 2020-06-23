#include "store.hpp"

Store::Store() {
}

Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    int totalPrice = cargo->getPrice() * amount;

    if (player->getAvailableSpace() < amount)
        return Response::lack_of_space;

    else if (cargo->getAmount() < amount)
        return Response::lack_of_cargo;

    else if (totalPrice > player->getMoeny())
        return Response::lack_of_money;

    player->getShip()->load(cargo);
    player->subtractMoney(totalPrice);
    cargo -= amount;
    return Response::done;
}

Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    if (player->getShip()->FindMatchCargo(cargo)->getAmount() < amount)
        return Response::lack_of_cargo;

    size_t money = amount * cargo->getPrice();
    player->addMoney(money);

    return Response::done;
}
