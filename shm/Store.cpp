#include <algorithm>

#include "cargo.hpp"

#include "player.hpp"

#include "Time.hpp"

#include "Store.hpp"

constexpr size_t numberOfPossibleFruitCargo = 4;

constexpr size_t numberOfPossibleAlcoholCargo = 4;

constexpr size_t numberOfPossibleItemCargo = 4;

std::vector<std::string> possibleFruitCargoNames = {"Banana", "Pineapple", "Apple", "Pear"};

std::vector<std::string> possibleAlcoholCargoNames = {"Whiskey", "Rum", "Vodka", "Beer"};

std::vector<std::string> possibleItemCargoNames = {"Rope", "Hook", "Screw", "Spoon"};

std::vector<Rarity> rarityChoice = {Rarity::common, Rarity::rare, Rarity::epic, Rarity::legendary};

Store::Store(int money, size_t availableSpace, Time* time)

    : Storable(money, availableSpace, time)

{
    storeCargo.reserve(20);

    SetUpRandomCargo(time);

    storeCargo.shrink_to_fit();
}

Store::~Store() {}

void Store::SetUpRandomCargo(Time* time) {
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_real_distribution<> fruitCargoDistrib(0, numberOfPossibleFruitCargo);

    std::uniform_real_distribution<> alcoholCargoDistrib(0, numberOfPossibleAlcoholCargo);

    std::uniform_real_distribution<> itemCargoDistrib(0, numberOfPossibleItemCargo);

    std::uniform_real_distribution<> fruitPrice(10, 25);

    std::uniform_real_distribution<> alcoholPrice(50, 100);

    std::uniform_real_distribution<> itemPrice(100, 300);

    std::uniform_real_distribution<> quantity(1, 50);

    std::uniform_real_distribution<> percentage(20, 100);

    std::uniform_real_distribution<> itemRarity(0, (int)rarityChoice.size() - 1.0);

    Rarity randomRarity = rarityChoice[(int)itemRarity(gen)];

    size_t fruitCargoNumber = (size_t)fruitCargoDistrib(gen);

    size_t alcoholCargoNumber = (size_t)alcoholCargoDistrib(gen);

    size_t itemCargoNumber = (size_t)itemCargoDistrib(gen);

    size_t fruitPriceX = (size_t)fruitPrice(gen);

    size_t alcoholPriceX = (size_t)alcoholPrice(gen);

    size_t itemPriceX = (size_t)itemPrice(gen);

    size_t cargoQuantity = (size_t)quantity(gen);

    size_t alcoholPercentage = (size_t)percentage(gen);

    std::string fruitCargoName = possibleFruitCargoNames[fruitCargoNumber];

    std::string alcoholCargoName = possibleAlcoholCargoNames[alcoholCargoNumber];

    std::string itemCargoName = possibleItemCargoNames[itemCargoNumber];

    storeCargo.push_back(new Fruit(fruitCargoName, (cargoQuantity + 10), fruitPriceX, time, 15, 0));

    storeCargo.push_back(new Alcohol(alcoholCargoName, cargoQuantity, alcoholPriceX, time, alcoholPercentage));

    storeCargo.push_back(new Item(itemCargoName, (cargoQuantity / 2), itemPriceX, time, randomRarity));
}

Cargo* Store::findMatchCargo(Cargo* cargo)

{
    for (auto& el : storeCargo)

    {
        if (*el == *cargo)

        {
            return el;
        }
    }

    return nullptr;
}

Response Store::buy(Cargo* cargo, size_t amount, Player* player)

{
    if (findMatchCargo(cargo))

    {
        auto price = 0;

        price = (int)(amount * cargo->getPrice());

        if (player->getAvailableSpace() < amount)

        {
            std::cout << "Lack of space" << '\n';

            return Response::lack_of_space;
        }

        if (cargo->getAmount() < amount)

        {
            std::cout << "Lack of cargo" << '\n';

            return Response::lack_of_cargo;
        }

        if (player->getMoney() < price)

        {
            std::cout << "Lack of money" << '\n';

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

Response Store::sell(Cargo* cargo, size_t amount, Player* player)

{
    if (player->getShip()->findMatchCargo(cargo))

    {
        auto price = 0;

        price = (int)(amount * cargo->getPrice());

        if (getAvailableSpace() < amount)

        {
            std::cout << "Lack of space" << '\n';

            return Response::lack_of_space;
        }

        if (player->getShip()->findMatchCargo(cargo)->getAmount() < amount)

        {
            std::cout << "Lack of cargo" << '\n';

            return Response::lack_of_cargo;
        }

        if (money_ < (int)(amount * cargo->getBasePrice()))

        {
            std::cout << "Lack of money" << '\n';

            return Response::lack_of_money;
        }

        if (money_ < price)

        {
            std::cout << "Lack of money" << '\n';

            return Response::lack_of_money;
        }

        money_ -= price;

        addStoreCargo(cargo);

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

Cargo* Store::getCargo(size_t index) const

{
    return nullptr;
}

void Store::nextDay(size_t elapsedTime)

{
    for (auto el : storeCargo)

    {
        el->reduceAmount(1);
    }
}

void Store::printStoreCargo()

{
    auto i = 0;

    for (auto el : storeCargo)

    {
        std::cout << '\n';

        el->printCargo(i);

        i++;
    }
}

void Store::removeCargo(Cargo* item, size_t amount)

{
    auto storeCargoAmount = findMatchCargo(item)->getAmount();

    if (storeCargoAmount == amount)

    {
        auto i = std::find(begin(storeCargo), end(storeCargo), item);

        storeCargo.erase(i);

    }

    else

    {
        findMatchCargo(item)->reduceAmount(amount);
    }
}

void Store::addStoreCargo(Cargo* item)

{
    auto cargoPtr = findMatchCargo(item);

    if (cargoPtr)

    {
        cargoPtr->increaseAmount(item->getAmount());

    }

    else

    {
        storeCargo.emplace_back(item);
    }
}
