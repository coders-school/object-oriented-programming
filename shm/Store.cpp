#include "Store.hpp"

#include <algorithm>
#include <random>

#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"

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

std::shared_ptr<Cargo> Store::makeCargoToBuy(const std::shared_ptr<Cargo>& cargo, size_t amount) const {
    if (typeid(*cargo) == typeid(Fruit)) {
        Fruit fruit(cargo->getName(), amount, cargo->getBasePrice(), (expirationDays * cargo->getPrice() / cargo->getBasePrice()));
        return std::make_shared<Fruit>(fruit);
    } else if (typeid(*cargo) == typeid(Alcohol)) {
        Alcohol alco(cargo->getName(), amount, cargo->getBasePrice(), (maximumAlcoholContent * cargo->getPrice() / cargo->getBasePrice()));
        return std::make_shared<Alcohol>(alco);
    } else if (typeid(*cargo) == typeid(Item)) {
        Item item(cargo->getName(), amount, cargo->getBasePrice(), static_cast<Rarity>(cargo->getPrice() / cargo->getBasePrice()));
        return std::make_shared<Item>(item);
    }

    return nullptr;
}

std::shared_ptr<Cargo> Store::getCargo(size_t index) const {
    return market_[index - 1];
}

void Store::removeFromStore(std::shared_ptr<Cargo> cargo, size_t amount) {
    if (amount == cargo->getAmount()) {
        market_.erase(std::remove(begin(market_), end(market_), cargo), market_.end());
    } else {
        *cargo -= amount;
    }
}

Response Store::buy(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player) {
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

Response Store::sell(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player) {
    size_t price = cargo->getPrice() * amount;
    player->sellCargo(cargo, amount, price);

    return Response::done;
}

void Store::nextDay() {
    //Doing nothing for now. Interface purposes
}

//simple operator just to know what is inside market, remove later
std::ostream& operator<<(std::ostream& os, const Store& store) {
    size_t i = 1;
    for (auto el : store.market_) {
        os << i << ". " << el->getName() << " | Amount: " << el->getAmount() << " | Price: " << el->getPrice() << "\n";
        i++;
    }

    return os;
}
