//
// Created by adi on 07.07.2020.
//

#include <algorithm>
#include "Store.hpp"
Store::Response Store::Buy(Cargo* cargo, size_t amount, Player* player)
{
    auto totalPrice = amount * cargo->GetPrice();

    if (cargo->GetAmount() < amount)
    {
        return Response::lack_of_cargo;
    }

    if (player->getAvailableSpace() < amount)
    {
        return Response::lack_of_space;
    }

    if (player->getMoney() < totalPrice)
    {
        return Response::lack_of_money;
    }

    player->spendMoney(totalPrice);
    player->getShip()->load(std::shared_ptr<Cargo>(cargo));
    return Response::done;
}

Store::Response Store::Sell(Cargo* cargo, size_t amount, Player* player)
{
    auto foundCargoIt = std::find_if(player->getCargos().begin(), player->getCargos().end(), [cargo](auto otherCargo) {
        return *cargo == *otherCargo;
    });

    if (foundCargoIt == player->getCargos().end() || foundCargoIt->get()->GetAmount() < amount)
    {
        return Response::lack_of_cargo;
    }

    size_t totalPrice = foundCargoIt->get()->GetPrice() * amount;
    player->setMoney(player->getMoney() + totalPrice);

    cargo -= amount;
    if (cargo->GetAmount() == 0)
    {
        player->getShip()->unload(cargo);
    }

    return Response::done;
}

Store::Store(Time* time) : time_(time)
{
    time_->addObserver(this);
}

Store::~Store()
{
    time_->removeObserver(this);
}
