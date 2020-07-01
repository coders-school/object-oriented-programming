#include "store.hpp"

Store::Store() {
}

Response Store::buy(cargoPtr cargo, size_t amount, Player* player) {
    int totalPrice = cargo->getPrice() * amount;

    size_t totalAmount = 0;
    for (const auto el : player->getShip()->getCargo()) {
        totalAmount += el->getAmount();
    }
    if (player->getShip()->getCapacity() - totalAmount < amount)
        return Response::lack_of_space;

    else if (cargo->getAmount() < amount)
        return Response::lack_of_cargo;

    else if (totalPrice > player->getMoney())
        return Response::lack_of_money;

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

cargoPtr Store::GetCargo(const size_t pos) {
    if (pos >= cargo_.size())
        return cargo_.at(cargo_.size() - 1);
    return cargo_.at(pos);
}

void Store::GenerateCargo() {
    // size_t number = 1 + std::rand() / ((RAND_MAX + 1u) / 10);
    // double basePrice = 1 + std::rand() / ((RAND_MAX + 1u) / 100);
    // Cargo cargo1("alko", number, basePrice);
    // cargo_.emplace_back(cargo1);
}

cargoPtr Store::FindMatchCargo(cargoPtr cargo) {
    for (auto el : cargo_) {
        if (*el == *cargo) {
            return el;
        }
    }
    return nullptr;  // czy tak może być?
}