#include "store.hpp"

#include <algorithm>

std::string Store::getResponse(const Response& response) {
    switch (response) {
    case Response::done:
        return "done";
    case Response::lack_of_cargo:
        return "Lack of cargo";
    case Response::lack_of_money:
        return "Lack of money";
    case Response::lack_of_space:
        return "Lack of space";
    }
}

std::vector<std::shared_ptr<Cargo>>::iterator Store::findCargo(const std::shared_ptr<Cargo>& cargo) {
    auto find = std::find_if(stock_.begin(), stock_.end(),
                             [cargo](const auto& el) { return cargo->getName() == el->getName() &&
                                                              cargo->getBasePrice() == el->getBasePrice(); });
    return find;
}

void Store::load(std::shared_ptr<Cargo> cargo, size_t amount) {
    auto newLoad = findCargo(cargo);

    if (newLoad == stock_.end()) {
        stock_.push_back(cargo);
        return;
    }

    **newLoad += amount;
}

void Store::unload(std::shared_ptr<Cargo> cargo, size_t amount) {
    auto soldCargo = findCargo(cargo);
    if(soldCargo == stock_.end()) {
        return;
    }
    if((*soldCargo)->getAmount() <= cargo->getAmount()) {
        stock_.erase(findCargo(cargo));
    }
    **soldCargo -= amount;
}

Response Store::buy(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player) {
    if (amount > player->getAvailableSpace()) {
        return Response::lack_of_space;
    }
    if (player->getMoney() < cargo->getBasePrice() * amount) {
        return Response::lack_of_money;
    }
    if(findCargo(cargo) == stock_.end()) {
        return Response::lack_of_cargo;
    }
    unload(cargo, amount);
    player->setMoney(player.get()->getMoney() - amount * cargo->getBasePrice());

    return Response::done;

}