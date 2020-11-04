#include "Store.hpp"

#include <algorithm>
#include <random>

#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"

Store::Store(Time* time):_time(time){
    _time->addObserver(this);
};
Store::~Store(){
    _time->removeObserver(this);
};

Cargo* Store::findCargo(Cargo* cargo) const {
    auto matchCargo = std::find_if(std::begin(_cargo), std::end(_cargo),
                                   [cargo](const auto& el) {
                                       return *el == *cargo;
                                   });
    if (matchCargo != std::end(_cargo)) {
        return matchCargo->get();
    }
    return nullptr;
}

constexpr size_t AMOUNT_MIN = 5;
constexpr size_t AMOUNT_MAX = 150;
constexpr size_t PRICE_MIN = 20;
constexpr size_t PRICE_MAX = 860;
constexpr size_t POWER_MIN = 40;
constexpr size_t POWER_MAX = 96;
constexpr size_t DATE_MIN = 2;
constexpr size_t DATE_MAX = 16;
constexpr size_t TIME_MIN = 0;
constexpr size_t TIME_MAX = 6;
constexpr size_t RARITY_MIN = 0;
constexpr size_t RARITY_MAX = 35;
constexpr size_t COUNTER_MAX = 8;

Store::Response Store::Buy(Cargo* cargo, size_t amount, Player* player) {
    if ((amount + cargo->getAmount()) > cargo->getMaxAmount()) {
        std::cout << "cargo, lack of space\n";
        return Response::lack_of_space;
    }
    if (amount > player->getAvailableSpace()) {
        std::cout << "player, lack of space\n";
        return Response::lack_of_space;
    }
    const size_t price = amount * cargo->getPrice();
    if (price > player->getMoney()) {
        std::cout << "player, lack of money\n";
        return Response::lack_of_money;
    }
    if (auto* matchCargo = findCargo(cargo)) {
        if (amount > matchCargo->getAmount()) {
            std::cout << "Store, lack of cargo\n";
            return Response::lack_of_cargo;
        } else {
            *matchCargo -= amount;
        }
    } else {
        std::cout << "Store, lack of cargo\n";
        return Response::lack_of_cargo;
    }
    if (cargo->getAmount() == 0) {
        _cargo.erase(std::find_if(std::begin(_cargo), std::end(_cargo),
                                  [cargo](const auto& el) {
                                      return *el == *cargo;
                                  }));
    }
    *cargo += amount;
    return Response::done;
}

Store::Response Store::Sell(Cargo* cargo, size_t amount, Player* player) {
    const size_t price = amount * cargo->getPrice();
    if (amount > cargo->getAmount()) {
        std::cout << "cargo, lack of cargo\n";
        return Response::lack_of_cargo;
    }
    if (auto* matchCargo = findCargo(cargo)) {
        if (matchCargo->getAmount() + amount > matchCargo->getMaxAmount()) {
            std::cout << "cargo, lack of space\n";
            return Response::lack_of_space;
        } else {
            *matchCargo += amount;
        }
    } else {
        if (auto* alcoholType = dynamic_cast<Alcohol*>(cargo)) {
            _cargo.push_back(std::make_shared<Alcohol>(alcoholType->getName(), amount, alcoholType->getBasePrice(), alcoholType->getPower(), _time));
        } else if (auto* fruitType = dynamic_cast<Fruit*>(cargo)) {
            _cargo.push_back(std::make_shared<Fruit>(fruitType->getName(), amount, fruitType->getBasePrice(), fruitType->getExpiryDate(), fruitType->getTimeToSpoil(), _time));
        } else if (auto* itemType = dynamic_cast<Item*>(cargo)) {
            _cargo.push_back(std::make_shared<Item>(itemType->getName(), amount, itemType->getBasePrice(), itemType->getRarity(), _time));
        }
    }
    *cargo -= amount;
    return Response::done;
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    out << "Cargo available in Store:\n";
    std::for_each(begin(store._cargo), end(store._cargo),
                  [&out, &store, i{0}](const auto& cargo) mutable {
                      out << ++i << ". ";
                      cargo->showCargo(out);
                  });
    return out;
}

void Store::nextDay() {
    static size_t counter = 0;

    if (counter++ > COUNTER_MAX) {
        counter = 0;
        _cargo.clear();
        generateDefaultCargo();
    }
}

void Store::generateDefaultCargo() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> amountDist(AMOUNT_MIN, AMOUNT_MAX);
    std::uniform_int_distribution<> priceDist(PRICE_MIN, PRICE_MAX);
    std::uniform_int_distribution<> powerDist(POWER_MIN, POWER_MAX);
    std::uniform_int_distribution<> dateDist(DATE_MIN, DATE_MAX);
    std::uniform_int_distribution<> timeDist(TIME_MIN, TIME_MAX);
    std::uniform_int_distribution<> rarityDist(RARITY_MIN, RARITY_MAX);

    _cargo.reserve(12);
    _cargo.push_back(std::make_shared<Alcohol>("whiskey", amountDist(gen), priceDist(gen), powerDist(gen), _time));
    _cargo.push_back(std::make_shared<Alcohol>("koniak", amountDist(gen), priceDist(gen), powerDist(gen), _time));
    _cargo.push_back(std::make_shared<Alcohol>("burbon", amountDist(gen), priceDist(gen), powerDist(gen), _time));
    _cargo.push_back(std::make_shared<Alcohol>("zytnia", amountDist(gen), priceDist(gen), powerDist(gen), _time));
    _cargo.push_back(std::make_shared<Fruit>("malina", amountDist(gen), priceDist(gen), dateDist(gen), timeDist(gen), _time));
    _cargo.push_back(std::make_shared<Fruit>("wisnia", amountDist(gen), priceDist(gen), dateDist(gen), timeDist(gen), _time));
    _cargo.push_back(std::make_shared<Fruit>("porzeczka", amountDist(gen), priceDist(gen), dateDist(gen), timeDist(gen), _time));
    _cargo.push_back(std::make_shared<Fruit>("jagoda", amountDist(gen), priceDist(gen), dateDist(gen), timeDist(gen), _time));
    _cargo.push_back(std::make_shared<Item>("gold", amountDist(gen), priceDist(gen), Item::ChooseRarity(rarityDist(gen)), _time));
    _cargo.push_back(std::make_shared<Item>("sword", amountDist(gen), priceDist(gen), Item::ChooseRarity(rarityDist(gen)), _time));
    _cargo.push_back(std::make_shared<Item>("amulet", amountDist(gen), priceDist(gen), Item::ChooseRarity(rarityDist(gen)), _time));
    _cargo.push_back(std::make_shared<Item>("books", amountDist(gen), priceDist(gen), Item::ChooseRarity(rarityDist(gen)), _time));
}
