#include "Store.hpp"

#include <algorithm>
#include <iomanip>
#include <random>

#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"

constexpr size_t rarityAmount{4};
constexpr Rarity possibleRarities[rarityAmount]{Rarity::common, Rarity::rare, Rarity::epic, Rarity::legendary};

Store::Store(std::shared_ptr<Time>& time) {
    time_ = time;
    time->addObserver(this);
    makeStock();
}

size_t Store::genRand(size_t min, size_t max) const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distirb(min, max);

    return static_cast<size_t>(distirb(gen));
}

void Store::generateFruits() {
    size_t i = 0;
    while(i < marketSection) {
        Fruit fruit(fruitNames[genRand(0, 5)], genRand(1, 20), genRand(10, 30), genRand(1, 10));
        if(std::none_of(begin(stock_), end(stock_),[&fruit](const auto& ptr){ return ptr->getName() == fruit.getName();})) {
            stock_.emplace_back(std::make_shared<Fruit>(fruit));
            i++;
        }
    }
}

void Store::generateAlcos() {
    size_t i = 0;
    while(i < marketSection) {
        Alcohol alco(alcoNames[genRand(0, 5)], genRand(1, 5), genRand(30, 100), genRand(40, 96));
        if(std::none_of(begin(stock_), end(stock_),[&alco](const auto& ptr){ return ptr->getName() == alco.getName();})) {
            stock_.emplace_back(std::make_shared<Alcohol>(alco));
            i++;
        }
    }
}

void Store::generateItems() {
    size_t i = 0;
    while(i < marketSection) {
        Item item(itemNames[genRand(0, 5)], genRand(1, 10), genRand(30, 100), possibleRarities[genRand(0, 3)]);
        if(std::none_of(begin(stock_), end(stock_),[&item](const auto& ptr){ return ptr->getName() == item.getName();})) {
            stock_.emplace_back(std::make_shared<Item>(item));
            i++;
        }
    }
}

void Store::makeStock() {
    constexpr size_t cargosPerSection{3};
    stock_.reserve(marketSection * cargosPerSection);
    generateFruits();
    generateAlcos();
    generateItems();
    stock_.shrink_to_fit();
}

CargoPtr Store::makeNewCargo(const CargoPtr& cargo, size_t amount) const {
    if (typeid(*cargo) == typeid(Fruit)) {
        Fruit fruit(cargo->getName(), amount, cargo->getBasePrice(), cargo->getUniqueStat());
        return std::make_shared<Fruit>(fruit);
    } else if (typeid(*cargo) == typeid(Alcohol)) {
        Alcohol alco(cargo->getName(), amount, cargo->getBasePrice(), cargo->getUniqueStat());
        return std::make_shared<Alcohol>(alco);
    } else if (typeid(*cargo) == typeid(Item)) {
        Item item(cargo->getName(), amount, cargo->getBasePrice(), static_cast<Rarity>(cargo->getUniqueStat()));
        return std::make_shared<Item>(item);
    }

    return nullptr;
}

CargoPtr Store::getCargo(size_t index) const {
    return stock_[index - 1];
}

CargoPtr Store::findCargo(const CargoPtr& cargo) const {
    return StockManagement::findCargo(cargo);
}

void Store::removeCargoFromStock(const CargoPtr& cargo, size_t amount) {
    StockManagement::removeCargoFromStock(cargo, amount);
}

void Store::addCargoToStock(const CargoPtr& cargo, size_t amount) {
    StockManagement::addCargoToStock(cargo, amount);
}

Response Store::buy(const CargoPtr& cargo, size_t amount, const std::shared_ptr<Player>& player) {
    const size_t price = amount * cargo->getPrice();

    if (cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    } else if (player->getMoney() < price) {
        return Response::lack_of_money;
    } else if (player->getAvailableSpace() < amount) {
        return Response::lack_of_space;
    }

    auto cargoToBuy = makeNewCargo(cargo, amount);
    player->purchaseCargo(cargoToBuy, amount, price);
    removeCargoFromStock(cargo, amount);
    

    return Response::done;
}

Response Store::sell(const CargoPtr& cargo, size_t amount, const std::shared_ptr<Player>& player) {
    size_t price = cargo->getPrice() * amount;

    auto cargoToSell = makeNewCargo(cargo, amount);
    player->sellCargo(cargo, amount, price);
    addCargoToStock(cargoToSell, amount);

    return Response::done;
}

void Store::nextDay() {
    stock_.clear();
    makeStock();
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    const std::string horizontalSeparator(41, '=');
    size_t i = 0;

    out << horizontalSeparator 
              << "\n"
              << "|| AVAILABLE PRODUCTS" << std::setw(10)
              << "| QTY " << std::setw(3)
              << "| PRICE " << std::setw(3)
              << "||\n"
              << horizontalSeparator << "\n";

    for (const auto& el : store.stock_) {
        out << "||"
                  << std::setw(2) << ++i << ". "
                  << std::setw(18) << std::left << el->getName() << " | "
                  << std::setw(3) << std::right << el->getAmount() << " | " 
                  << std::setw(5) << std::right << el->getPrice() << " ||\n";
    }
    out << horizontalSeparator << "\n";
    
    return out;
}
