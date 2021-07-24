#include "cargo.hpp"
#include "player.hpp"
#include "Time.hpp"
#include "Store.hpp"

Store::Store(int money, size_t availableSpace, Time *time)
    : Storable(money, availableSpace, time)
{
    storeCargo.push_back(std::make_shared<Fruit>("Banany", 10, 20, time, 15, 0)); 
    storeCargo.push_back(std::make_shared<Fruit>("Apple", 15, 14, time, 20, 0));
    storeCargo.push_back(std::make_shared<Alcohol>("Vodka", 33, 60, time, 70));        
    storeCargo.push_back(std::make_shared<Item>("Hook", 5, 100, time, Rarity::common)); 
}
Store::~Store() {}

Cargo *Store::findMatchCargo(Cargo *cargo)
{
    for (auto &el : storeCargo)
    {
        if (*el == *cargo)
        {
            return el.get();
        }
    }
    return nullptr;
}

Response Store::buy(Cargo *cargo, size_t amount, Player *player) //Buying cargo from store to player
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

        player->SpendMoney(price);
        player->load(cargo, amount);

        return Response::done;
    }
    else
    {
        return Response::lack_of_cargo;
    }
}

Response Store::sell(Cargo *cargo, size_t amount, Player *player) 
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
        if (player->getMoney() < amount * cargo->getBasePrice())
        {
            return Response::lack_of_money;
        }

        player->unload(cargo, amount);
        player->EarnMoney(price);

        return Response::done;
    }
    else
    {
        return Response::lack_of_cargo;
    }

    if (Cargo *ptr = findMatchCargo(cargo))
    {
        *ptr += amount;
    }

    return Response::done;
}

std::shared_ptr<Cargo> Store::getCargo(size_t index) const
{
    return nullptr;
}

void Store::nextDay()
{
    for (auto el : storeCargo)
    {
        el.get()->reduceAmount();
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
