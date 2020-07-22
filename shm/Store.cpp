#include "Store.hpp"

#include <algorithm>
#include <random>

#include "Fruit.hpp"
#include "Item.hpp"
#include "Alcohol.hpp"

// Store::Store(std::shared_ptr<Time>& time)
//     : time_(time) {
//     time_->addObserver(this);
// }

Store::Store(std::shared_ptr<Time>& time) {
    time_ = time;
    market_ = makeStock(generateFruits(), generateAlcos(), generateItems());
}

size_t Store::generateRandom(int min, int max) const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distirb(min, max);

    return static_cast<size_t>(distirb(gen));
}

Cargos Store::generateFruits() const {
    Cargos result;
    result.reserve(marketSection);

    for (size_t i = 0; i < marketSection; i++) {
        Fruit fruit(fruitNames[generateRandom(0, 5)], generateRandom(1, 20), generateRandom(10, 30), generateRandom(1, 10));
        auto ptr = std::make_shared<Fruit>(fruit);
        result.emplace_back(ptr);
    }
    result.shrink_to_fit();

    return result;
}

Cargos Store::generateAlcos() const {
    Cargos result;
    result.reserve(marketSection);

    for (size_t i = 0; i < marketSection; i++) {
        Alcohol alco(alcoNames[generateRandom(0, 5)], generateRandom(1, 5), generateRandom(30, 100), generateRandom(40, 96));
        auto ptr = std::make_shared<Alcohol>(alco);
        result.emplace_back(ptr);
    }
    result.shrink_to_fit();

    return result;
}

Cargos Store::generateItems() const {
    Cargos result;
    result.reserve(marketSection);

    for (size_t i = 0; i < marketSection; i++) {
        Item item(itemNames[generateRandom(0, 5)], generateRandom(1, 10), generateRandom(30, 100), Rarity::rare);
        auto ptr = std::make_shared<Item>(item);
        result.emplace_back(ptr);
    }
    result.shrink_to_fit();

    return result;
}

Cargos Store::makeStock(const Cargos& fruits, const Cargos& alcos, const Cargos& items) {
    Cargos result;
    for (size_t i = 0; i < marketSection; i++) {
        result.push_back(fruits[i]);
        result.push_back(alcos[i]);
        result.push_back(items[i]);
    }

    return result;
}

Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    const size_t price = amount * cargo->getBasePrice();
    if (cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    } else if (player->getMoney() < price) {
        return Response::lack_of_money;
    } else if (player->getAvailableSpace() < amount) {
        return Response::lack_of_space;
    }
    *cargo += amount;
    player->purchaseCargo(std::shared_ptr<Cargo> (cargo), amount, price);
    return Response::done;
}

Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    const size_t price = amount * cargo->getPrice();
    *cargo -= amount; 
    player->sellCargo(std::shared_ptr<Cargo> (cargo), amount, price);
    return Response::done;
}

void Store::nextDay() {
    //Doing nothing for now. Interface purposes
}
