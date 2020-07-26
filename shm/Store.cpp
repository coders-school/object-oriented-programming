#include "Store.hpp"

#include <algorithm>
#include <iomanip>
#include <random>

#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"

Store::Store(std::shared_ptr<Time>& time) {
    time_ = time;
    time->addObserver(this);
    market_ = makeStock();
}

size_t Store::genRand(int min, int max) const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distirb(min, max);

    return static_cast<size_t>(distirb(gen));
}

CargoStock Store::generateFruits() const {
    CargoStock result;
    result.reserve(marketSection);

    size_t i = 0;
    while(i < marketSection) {
        Fruit fruit(fruitNames[genRand(0, 5)], genRand(1, 20), genRand(10, 30), genRand(1, 10));
        if(std::none_of(begin(result), end(result),[&fruit](const auto& ptr){ return ptr->getName() == fruit.getName();})) {
            result.emplace_back(std::make_shared<Fruit>(fruit));
            i++;
        }
    }
    result.shrink_to_fit();

    return result;
}

CargoStock Store::generateAlcos() const {
    CargoStock result;
    result.reserve(marketSection);

    size_t i = 0;
    while(i < marketSection) {
        Alcohol alco(alcoNames[genRand(0, 5)], genRand(1, 5), genRand(30, 100), genRand(40, 96));
        if(std::none_of(begin(result), end(result),[&alco](const auto& ptr){ return ptr->getName() == alco.getName();})) {
            result.emplace_back(std::make_shared<Alcohol>(alco));
            i++;
        }
    }
    result.shrink_to_fit();

    return result;
}

CargoStock Store::generateItems() const {
    CargoStock result;
    result.reserve(marketSection);

    size_t i = 0;
    while(i < marketSection) {
        Item item(itemNames[genRand(0, 5)], genRand(1, 10), genRand(30, 100), Rarity::rare);
        if(std::none_of(begin(result), end(result),[&item](const auto& ptr){ return ptr->getName() == item.getName();})) {
            result.emplace_back(std::make_shared<Item>(item));
            i++;
        }
    }
    result.shrink_to_fit();

    return result;
}

CargoStock Store::makeStock() {
    CargoStock result;
    auto fruits = generateFruits();
    auto alcos = generateAlcos();
    auto items = generateItems();
    result.reserve(marketSection * 3);
    for (size_t i = 0; i < marketSection; i++) {
        result.push_back(fruits[i]);
        result.push_back(alcos[i]);
        result.push_back(items[i]);
    }
    result.shrink_to_fit();

    return result;
}

CargoPtr Store::makeCargoToBuy(const CargoPtr& cargo, size_t amount) const {
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
    return market_[index - 1];
}

void Store::removeFromStore(const CargoPtr& cargo, size_t amount) {
    if (amount == cargo->getAmount()) {
        market_.erase(std::remove(begin(market_), end(market_), cargo), market_.end());
    } else {
        *cargo -= amount;
    }
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

    auto cargoToBuy = makeCargoToBuy(cargo, amount);
    player->purchaseCargo(cargoToBuy, amount, price);
    removeFromStore(cargo, amount);

    return Response::done;
}

Response Store::sell(const CargoPtr& cargo, size_t amount, const std::shared_ptr<Player>& player) {
    size_t price = cargo->getPrice() * amount;
    player->sellCargo(cargo, amount, price);

    return Response::done;
}

void Store::nextDay() {
    //Doing nothing for now. Interface purposes
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    const std::string horizontalSeparator(41, '=');
    size_t i = 0;

    out << horizontalSeparator 
              << "\n"
              << "|| AVAILABLE PRODUCTS"
              << std::setw(10) << "| QTY "
              << std::setw(3) << "| PRICE "
              << std::setw(3) << "||\n"
              << horizontalSeparator << "\n";

    for (const auto& el : store.market_) {
        out << "||"
                  << std::setw(2) << ++i << ". "
                  << std::setw(18) << std::left << el->getName() << " | "
                  << std::setw(3) << std::right << el->getAmount() << " | " 
                  << std::setw(5) << std::right << el->getPrice() << " ||\n";
    }
    out << horizontalSeparator << "\n";
    
    return out;
}
