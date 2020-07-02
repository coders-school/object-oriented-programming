#include "store.hpp"

#include "algorithm"
#include "fruit.hpp"
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
    // size_t number = GenerateRandom(10);
    // double basePrice = GenerateRandom(100);
    // for (auto el : fruitsNames) {
    // Fruit fr
    // }
    // cargo_.emplace_back(&cargo1);
}

cargoPtr Store::FindMatchCargo(cargoPtr cargo) {
    for (auto el : cargo_) {
        if (*el == *cargo) {
            return el;
        }
    }
    return nullptr;  // czy tak może być? Bo coś tu chyba musimy zwracać, jak się nie znajdzie? Ale czy nullptr to dobra myśl?
}

size_t Store::GenerateRandom(size_t range) {
    return 1 + std::rand() / ((RAND_MAX + 1u) / range);
}

void Store::RemoveFromStore(cargoPtr cargo) {
    cargo_.erase(std::find_if(std::begin(cargo_), std::end(cargo_),
                              [cargo](const auto& el) {
                                  return *el == *cargo;
                              }));
}