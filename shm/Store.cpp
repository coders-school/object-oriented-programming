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
    defineStoreEconomy();
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
    while (i < marketSection) {
        Fruit fruit(fruitNames[genRand(0, 5)], genRand(1, 20), genRand(10, 30), genRand(1, 10));
        if (std::none_of(begin(stock_), end(stock_), [&fruit](const auto& ptr) { return ptr->getName() == fruit.getName(); })) {
            stock_.emplace_back(std::make_shared<Fruit>(fruit));
            i++;
        }
    }
}

void Store::generateAlcos() {
    size_t i = 0;
    while (i < marketSection) {
        Alcohol alco(alcoNames[genRand(0, 5)], genRand(1, 5), genRand(30, 100), genRand(40, 96));
        if (std::none_of(begin(stock_), end(stock_), [&alco](const auto& ptr) { return ptr->getName() == alco.getName(); })) {
            stock_.emplace_back(std::make_shared<Alcohol>(alco));
            i++;
        }
    }
}

void Store::generateItems() {
    size_t i = 0;
    while (i < marketSection) {
        Item item(itemNames[genRand(0, 5)], genRand(1, 10), genRand(30, 100), possibleRarities[genRand(0, 3)]);
        if (std::none_of(begin(stock_), end(stock_), [&item](const auto& ptr) { return ptr->getName() == item.getName(); })) {
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

Response Store::buy(const CargoPtr& cargo, size_t amount, const std::shared_ptr<Player>& player) {
    const size_t price = amount * this->calculateBuyPrice(cargo);

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
    const size_t price = cargo->getPrice() * amount;

    if (cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    }

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
    const std::string horizontalSeparator(45, '=');
    size_t i = 0;

    out << horizontalSeparator
        << "\n"
        << "|| AVAILABLE PRODUCTS" << std::setw(10)
        << "| QTY " << std::setw(5)
        << "| BUY PRICE " << std::setw(3)
        //<< "| SELL PRICE " << std::setw(3)
        << "||\n"
        << horizontalSeparator << "\n";

    for (const auto& el : store.stock_) {
        out << "||"
            << std::setw(2) << ++i << ". "
            << std::setw(18) << std::left << el->getName() << " | "
            << std::setw(3) << std::right << el->getAmount() << " | "
            << std::setw(9) << std::right << store.calculateBuyPrice(el) 
            //<< " | "
            //<< std::setw(9) << std::right << el->getPrice() 
            << " ||\n";
    }
    out << horizontalSeparator << "\n";

    return out;
}

size_t Store::calculateBuyPrice(const CargoPtr& cargo) const {
    size_t cargoPrice = cargo->getPrice();
    double buyPriceMultiplier = (cargoPrice <= cargoPriceThreshold_ ? belowThreshMultiplier_ : aboveThreshMultiplier_);

    return static_cast<size_t>(cargoPrice * buyPriceMultiplier);
}

void Store::defineStoreEconomy() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> priceThresh(10, 20);
    std::uniform_real_distribution<> below(1.5, 1.9);
    std::uniform_real_distribution<> above(1.2, 1.5);

    cargoPriceThreshold_ = priceThresh(gen);
    belowThreshMultiplier_ = below(gen);
    aboveThreshMultiplier_ = above(gen);
}
