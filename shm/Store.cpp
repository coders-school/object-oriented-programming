#include <algorithm>
#include "cargo.hpp"
#include "player.hpp"
#include "Time.hpp"
#include "Store.hpp"


Store::Store(int money, size_t availableSpace, Time *time)
    : Storable(money, availableSpace, time)
{
    storeCargo.push_back(new Fruit("Banany", 10, 20, time, 15, 0)); 
    storeCargo.push_back(new Fruit("Apple", 15, 14, time, 20, 0));
    storeCargo.push_back(new Alcohol("Rum", 33, 60, time, 70));        
    storeCargo.push_back(new Item("Hook", 5, 100, time, Rarity::common)); 
}
Store::~Store() {}

Cargo * Store::findMatchCargo(Cargo * cargo)
{
    for (auto &el : storeCargo)
    {
        if (*el == *cargo)
        {
            return el;
        }
    }
    return nullptr;
}

Response Store::buy(Cargo * cargo, size_t amount, Player *player)
{
    if (findMatchCargo(cargo))
    {
        auto price = amount * cargo->getBasePrice();

        if (player->getAvailableSpace() < amount)
        {
            return Response::lack_of_space;
        }
        if (cargo->getAmount() < amount)
        {
            return Response::lack_of_cargo;
        }
        if (player->getMoney() < price)
        {
            return Response::lack_of_money;
        }
        
        money_ += price;
        player->SpendMoney(price);
        player->getShip()->load(cargo, amount);
        return Response::done;
    }
    else
    {
        return Response::lack_of_cargo;
    }
}

Response Store::sell(Cargo * cargo, size_t amount, Player *player) 
{
    if (player->getShip()->findMatchCargo(cargo))
    {
        auto price = amount * cargo->getBasePrice();
        if (getAvailableSpace() < amount)// miejsce sklepu
        {
            return Response::lack_of_space;
        }
        if (player->getShip()->findMatchCargo(cargo)->getAmount() < amount)//cargo gracza player->getShip()->findMatchCargo(cargo)->getAmount() < amount
        {
            return Response::lack_of_cargo;
        }
        if (money_ < amount * cargo->getBasePrice())// pieniądze sklepu
        {
            return Response::lack_of_money;
        }
        money_ -= price;
        addStoreCargo(cargo, amount);
        player->getShip()->unload(cargo, amount);
        player->EarnMoney(price);

        return Response::done;
    }
    else
    {
        return Response::lack_of_cargo;
    }

    return Response::done;
}

Cargo * Store::getCargo(size_t index) const
{
    return nullptr;
}

void Store::nextDay()
{
    for (auto el : storeCargo)
    {
        el->reduceAmount(1);
    }
}

void Store::printStoreCargo()
{
    for (auto el : storeCargo)
    {
        std::cout << '\n';
        el->printCargo();
    }
}

void Store::removeCargo(Cargo * item, size_t amount)
{
    auto storeCargoAmount = findMatchCargo(item)->getAmount();
    if(storeCargoAmount == amount)
    {
        auto i = std::find(begin(storeCargo), end(storeCargo), item);
        storeCargo.erase(i);
    }
    else
    {
        findMatchCargo(item)->reduceAmount(amount);
    }
}
void Store::addStoreCargo(Cargo * item, size_t amount)
{
    auto cargoPtr = findMatchCargo(item);
    if(*cargoPtr == *item)
    {
        cargoPtr->increaseAmount(item->getAmount());
    }
    else
    {
        storeCargo.emplace_back(item);
    }
}
