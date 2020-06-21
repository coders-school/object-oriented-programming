#include "store.hpp"

#include <algorithm>

Store::Store(const std::vector<std::shared_ptr<Cargo>>& stock) : stock_(stock) {}

Store::Response Store::buy(Cargo* cargo, Player* player) {
    if (cargo->getAmount() > player->getAvailableSpace()) {
        return Response::lack_of_space;
    }

    auto toBuy = std::find_if(stock_.begin(), stock_.end(), [cargo](const auto& el) {
        return (el->getName() == cargo->getName() &&
                el->getBasePrice() == cargo->getBasePrice() &&
                el->getPrice() == cargo->getPrice());
    });

    if (toBuy == stock_.end() || (*toBuy)->getAmount() < cargo->getAmount()) {
        return Response::lack_of_cargo;
    }
    if ((*toBuy)->getPrice() > player->getMoney()) {
        return Response::lack_of_money;
    }

    unload(cargo);
    player->loadShip(std::make_shared<Cargo>(*cargo));
    player->setMoney(player->getMoney() - cargo->getPrice());

    return Response::done;
}

Store::Response Store::sell(Cargo* cargo, Player* player) {
    load(std::make_shared<Cargo>(*cargo));
    player->unloadShip(cargo);
    player->setMoney(player->getMoney() + cargo->getPrice());

    return Response::done;
}

void Store::load(std::shared_ptr<Cargo> cargo) {
    auto result = std::find_if(stock_.begin(), stock_.end(), [cargo](const auto& el) {
        return (el->getName() == cargo->getName() &&
                el->getBasePrice() == cargo->getBasePrice() &&
                el->getPrice() == cargo->getPrice());
    });

    if (result == stock_.end()) {
        stock_.push_back(cargo);
        return;
    }
    **result += cargo->getAmount();
}

void Store::unload(Cargo* cargo) {
    auto thing = std::find_if(stock_.begin(), stock_.end(), [cargo](const auto& el) {
        return (el->getName() == cargo->getName() &&
                el->getBasePrice() == cargo->getBasePrice() &&
                el->getPrice() == cargo->getPrice());
    });
    if (thing == stock_.end()) {
        return;
    }

    if ((*thing)->getAmount() <= cargo->getAmount()) {
        stock_.erase(thing);
        return;
    }
    **thing -= cargo->getAmount();
}
