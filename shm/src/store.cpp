#include "store.hpp"
#include "alcohol.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "locators.hpp"

#include <algorithm>
#include <iomanip>
#include <ostream>
#include <random>

Store::Store(const std::vector<std::shared_ptr<Cargo>>& stock) : stock_(stock) {
    TimeServiceLocator::getTime()->addObserver(this);
}
Store::Store() : stock_(std::vector<std::shared_ptr<Cargo>>{}) {
    TimeServiceLocator::getTime()->addObserver(this);

    generateRegularCargo();
    generateItems();
}

Store::~Store() {
    TimeServiceLocator::getTime()->removeObserver(this);
}

Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    if (amount > player->getAvailableSpace()) {
        return Response::lack_of_space;
    }

    auto toBuy = findStock(cargo);

    if (toBuy == stock_.end() || (*toBuy)->getAmount() < amount) {
        return Response::lack_of_cargo;
    }
    if ((*toBuy)->getPrice() > player->getMoney()) {
        return Response::lack_of_money;
    }

    unload(cargo, amount);
    player->loadShip(std::shared_ptr<Cargo>(cargo));
    player->setMoney(player->getMoney() - cargo->getPrice());

    return Response::done;
}

Store::Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    load(std::shared_ptr<Cargo>(cargo), amount);
    player->unloadShip(cargo, amount);
    player->setMoney(player->getMoney() + cargo->getPrice());

    return Response::done;
}

void Store::load(std::shared_ptr<Cargo> cargo, size_t amount) {
    auto result = findStock(cargo.get());

    if (result == stock_.end()) {
        stock_.push_back(cargo);
        return;
    }
    **result += amount;
}

void Store::unload(Cargo* cargo, size_t amount) {
    auto thing = findStock(cargo);

    if (thing == stock_.end()) {
        return;
    }

    if ((*thing)->getAmount() <= cargo->getAmount()) {
        stock_.erase(thing);
        return;
    }
    **thing -= amount;
}

std::vector<std::shared_ptr<Cargo>>::iterator Store::findStock(Cargo* cargo) {
    return std::find_if(stock_.begin(), stock_.end(), [cargo](const auto& el) {
        return (el->getName() == cargo->getName() &&
                el->getBasePrice() == cargo->getBasePrice() &&
                el->getPrice() == cargo->getPrice());
    });
}

void Store::nextDay() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);
    std::uniform_int_distribution<> distrib2(1, 20);
    for (const auto& cargo_ptr : stock_) {
        if (distrib(gen)) {
            *cargo_ptr += distrib2(gen);
        } else {
            *cargo_ptr -= distrib2(gen);
        }
    }
}

void Store::randomizeRegularCargo(
    const std::vector<std::shared_ptr<Cargo>>& possibleRegularCargo) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> initialAmount(0, 20);

    for (const auto& cargo : possibleRegularCargo) {
        *cargo += initialAmount(gen);
        stock_.push_back(cargo);
    }
}

void Store::randomizeItems(const std::vector<std::shared_ptr<Cargo>>& items) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> itemRarity(0, 100);

    auto result = itemRarity(gen);

    if (result > 50) {
        stock_.push_back(items[0]);
    }
    if (result > 80) {
        stock_.push_back(items[1]);
    }
    if (result > 95) {
        stock_.push_back(items[2]);
    }
    if (result > 98) {
        stock_.push_back(items[3]);
    }
}

void Store::generateRegularCargo() {
    std::vector<std::shared_ptr<Cargo>> possibleRegularCargo{
        std::make_shared<Alcohol>(Alcohol("Whisky", 0, 100, 47)),
        std::make_shared<Alcohol>(Alcohol("Beer", 0, 12, 8)),
        std::make_shared<Alcohol>(Alcohol("Wine", 0, 40, 47)),
        std::make_shared<Fruit>(Fruit("Banana", 0, 5, 10)),
        std::make_shared<Fruit>(Fruit("Orange", 0, 7, 7)),
        std::make_shared<Fruit>(Fruit("Raspberry", 0, 30, 2)),
        std::make_shared<Fruit>(Fruit("GoldenCucumber", 0, 70, 1)),
    };
    randomizeRegularCargo(possibleRegularCargo);
}

void Store::generateItems() {
    std::vector<std::shared_ptr<Cargo>> items{
        std::make_shared<Item>(Item("MetalScrap", 10, 2, Item::Rarity::common)),
        std::make_shared<Item>(Item("Sextant", 3, 120, Item::Rarity::rare)),
        std::make_shared<Item>(Item("BlackPearl", 1, 400, Item::Rarity::epic)),
        std::make_shared<Item>(Item("Kraken's eye", 1, 1000, Item::Rarity::legendary))

    };

    randomizeItems(items);
}

Cargo* Store::getCargo(const size_t position) {
    if (position < stock_.size()) {
        return stock_[position].get();
    } else {
        return nullptr;
    }
}

std::ostream& operator<<(std::ostream& str, const Store& store) {
    std::string dash(60, '-');
    for (const auto& cargo_ptr : store.stock_) {
        str << "Type: " << std::setw(10) << cargo_ptr->getName() << std::setw(3) << "| ";
        str << "Amount: " << std::setw(10) << cargo_ptr->getAmount() << std::setw(3)
            << "| ";
        str << "Price: " << std::setw(10) << cargo_ptr->getPrice() << std::setw(3)
            << "| ";
        str << "\n" << dash << "\n";
    }
    return str;
}
