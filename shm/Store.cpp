#include "Store.h"

#include <algorithm>

Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    if (player->getAvailableSpace() < amount) {
        return Response::lack_of_space;
    }

    auto foundCargoIt = std::find(available_cargos_.begin(), available_cargos_.end(), [&cargo](auto otherCargo) {
        return cargo == otherCargo;
    });

    if (foundCargoIt == available_cargos_.end() || foundCargoIt->get()->getAmount() < amount) {
        return Response::lack_of_cargo;
    }
    size_t totalPrice = foundCargoIt->get()->getPrice() * amount;

    if (player->getMoney() < totalPrice) {
        return Response::lack_of_money;
    }

    player->setMoney(player->getMoney() - totalPrice);
    player->getCargos().push_back(std::make_shared<Cargo>(cargo));
    return Response::done;
}

Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    auto foundCargoIt = std::find(player->getCargos().begin(), player->getCargos().end(), cargo);

    if (foundCargoIt == player->getCargos().end() || foundCargoIt->get()->getAmount() < amount) {
        return Response::lack_of_cargo;
    }

    size_t totalPrice = foundCargoIt->get()->getPrice() * amount;
    player->setMoney(player->getMoney() + totalPrice);

    cargo -= amount;
    if (cargo->getAmount() == 0) {
        player->getCargos().erase(std::remove(player->getCargos().begin(), player->getCargos().end(), cargo));
    }

    return Response::done;
}
