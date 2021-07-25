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

std::shared_ptr<Cargo> Store::findMatchCargo(std::shared_ptr<Cargo> cargo)
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

Response Store::buy(std::shared_ptr<Cargo> cargo, size_t amount, Player *player) //Buying cargo from store to player
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
        //storeCargo.removeCargo();
        return Response::done;
    }
    else
    {
        return Response::lack_of_cargo;
    }
}

Response Store::sell(std::shared_ptr<Cargo> cargo, size_t amount, Player *player) 
{
    // Ship -> 
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
        money_ += price;
        player->getShip()->unload(cargo, amount);
        storeCargo.push_back(cargo);
        player->EarnMoney(price);

        return Response::done;
    }
    else
    {
        return Response::lack_of_cargo;
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
        el.get()->reduceAmount(1);
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

// void Store::removeCargo(std::shared_ptr<Cargo> item, size_t amount)
// {
//     auto storeCargoAmount = findMatchCargo(item)->getAmount();
//     if(storeCargoAmount == amount)
//     {
//         auto i = std::find(begin(storeCargo), end(storeCargo), item);
//         storeCargo.erase(i);
//     }
//     else
//     {
//         findMatchCargo(item)->reduceAmount(amount);
//     }
// }
