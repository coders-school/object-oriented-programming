#include <algorithm>
#include "cargo.hpp"
#include "player.hpp"
#include "Time.hpp"
#include "Store.hpp"

constexpr size_t numberOfPossibleFruitCargo = 4;
constexpr size_t numberOfPossibleAlcoholCargo = 4;
constexpr size_t numberOfPossibleItemCargo = 4;
constexpr size_t numberOfPossibleCargo = numberOfPossibleFruitCargo + numberOfPossibleAlcoholCargo + numberOfPossibleItemCargo;
constexpr size_t maxQuantityOfCargo = 1000;
std::vector<std::string> possibleFruitCargoNames = {"Banana", "Pineapple", "Apple", "Pear"};
std::vector<std::string> possibleAlcoholCargoNames = {"Whiskey", "Rum", "Vodka", "Beer"};
std::vector<std::string> possibleItemCargoNames = {"Nail", "Hook", "Screw", "Spoon"};

Store::Store(int money, size_t availableSpace, Time *time)
    : Storable(money, availableSpace, time)
{
    //SetUpRandomCargo(time);
    storeCargo.push_back(new Fruit("Banany", 10, 20, time, 15, 0)); 
    storeCargo.push_back(new Fruit("Apple", 15, 14, time, 20, 0));
    storeCargo.push_back(new Alcohol("Vodka", 33, 60, time, 70));        
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

Response Store::buy(Cargo * cargo, size_t amount, Player *player) //Buying cargo from store to player
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
void Store::SetUpRandomCargo(Time *time) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib1(1, numberOfPossibleCargo);
    std::uniform_real_distribution<> fruitCargoDistrib(0, numberOfPossibleFruitCargo);
    std::uniform_real_distribution<> alcoholCargoDistrib(0, numberOfPossibleAlcoholCargo);
    std::uniform_real_distribution<> itemCargoDistrib(0, numberOfPossibleItemCargo);

    size_t fruitCargoNumber = fruitCargoDistrib(gen);
    size_t alcoholCargoNumber = alcoholCargoDistrib(gen);
    size_t itemCargoNumber = itemCargoDistrib(gen);

    std::string fruitCargoName = possibleFruitCargoNames[fruitCargoNumber];
    std::string alcoholCargoName = possibleAlcoholCargoNames[alcoholCargoNumber];
    std::string itemCargoName = possibleItemCargoNames[itemCargoNumber];

    // std::cout << "fruitCargo : " << fruitCargoName  << '\n';
    // std::cout << "alcoholCargo : " << alcoholCargoName  << '\n';
    // std::cout << "itemCargo : " << itemCargoName  << '\n';


    storeCargo.push_back(new Fruit(fruitCargoName, 10, 20, time, 15, 0)); 
    storeCargo.push_back(new Fruit(alcoholCargoName, 10, 20, time, 15, 0)); 
    storeCargo.push_back(new Fruit(itemCargoName, 10, 20, time, 15, 0)); 

}
