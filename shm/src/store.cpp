#include "store.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>

#include "alcohol.hpp"
#include "fruit.hpp"
#include "item.hpp"

Store::Store(std::shared_ptr<Time> time)
    : time_(time) {
    GenerateCargo();
    time_->addObserver(this);
}

Store::~Store() {
    time_->removeObserver(this);
}

Response Store::buy(cargoPtr cargo, size_t amount, std::unique_ptr<Player>& player) {
    int totalPrice = cargo->getPrice() * amount;

    size_t totalAmount = 0;
    for (const auto el : player->getShip()->getCargo()) {
        totalAmount += el->getAmount();
    }

    if (player->getShip()->getCapacity() - totalAmount < amount) {
        return Response::lack_of_space;
    }

    if (cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    }

    if (totalPrice > player->getMoney()) {
        return Response::lack_of_money;
    }

    cargoPtr tempCargo = nullptr;
    if (typeid(*cargo) == typeid(Alcohol)) {
        Alcohol tempAlcohol(cargo->getName(), amount, cargo->getBasePrice());
        tempCargo = std::make_shared<Alcohol>(tempAlcohol);
    } else if (typeid(*cargo) == typeid(Fruit)) {
        Fruit tempFruit(cargo->getName(), amount, cargo->getBasePrice());
        tempCargo = std::make_shared<Fruit>(tempFruit);
    } else if (typeid(*cargo) == typeid(Item)) {
        Item tempItem(cargo->getName(), amount, cargo->getBasePrice());
        tempCargo = std::make_shared<Item>(tempItem);
    }
    player->getShip()->load(tempCargo);

    *cargo.get() -= amount;
    player->subtractMoney(totalPrice);
    return Response::done;
}

Response Store::sell(cargoPtr cargo, size_t amount, std::unique_ptr<Player>& player) {
    if (player->getShip()->FindMatchCargo(cargo.get())->getAmount() < amount) {
        return Response::lack_of_space;
    }
    if (player->getShip()->FindMatchCargo(cargo.get())) {
        *cargo.get() += amount;
        size_t money = amount * cargo->getPrice();
        player->addMoney(money);
        player->getShip()->Unload(cargo.get(), amount);
        return Response::done;
    }
    return Response::lack_of_cargo;
}

void Store::nextDay() {
    cargo_.clear();
    GenerateCargo();
}

cargoPtr Store::GetCargo(const size_t pos) {
    if (pos >= cargo_.size())
        return cargo_.at(cargo_.size() - 1);
    return cargo_.at(pos);
}

void Store::GenerateCargo() {
    GenerateFruits();
    GenerateItems();
    GenerateAlco();
}

cargoPtr Store::FindMatchCargo(cargoPtr cargo) {
    for (auto el : cargo_) {
        if (*el == *cargo) {
            return el;
        }
    }
    return nullptr;
}

size_t Store::GenerateRandom(size_t minValue, size_t maxValue) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minValue, maxValue);
    return distrib(gen);
}

void Store::RemoveFromStore(cargoPtr cargo) {
    cargo_.erase(std::find_if(std::begin(cargo_), std::end(cargo_),
                              [cargo](const auto& el) {
                                  return *el == *cargo;
                              }));
}

void Store::GenerateFruits() {
    for (auto el : fruitsNames) {
        size_t number = GenerateRandom(1, 15);
        double basePrice = GenerateRandom(1, 20);
        size_t timeToRotten = GenerateRandom(1, 28);
        Fruit fr(el, number, basePrice, timeToRotten);
        auto ptr = std::make_shared<Fruit>(fr);
        cargo_.emplace_back(ptr);
    }
}
void Store::GenerateAlco() {
    for (auto el : alcoNames) {
        size_t number = GenerateRandom(1, 10);
        double basePrice = GenerateRandom(1, 100);
        Alcohol alco(el, number, basePrice);
        auto ptr = std::make_shared<Alcohol>(alco);
        cargo_.emplace_back(ptr);
    }
}
void Store::GenerateItems() {
    for (auto el : itemNames) {
        size_t number = GenerateRandom(1, 10);
        double basePrice = GenerateRandom(1, 70);
        Item itm(el, number, basePrice);
        auto ptr = std::make_shared<Item>(itm);
        cargo_.emplace_back(ptr);
    }
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    int i = 1;
    out << "Index:\t"
        << std::setw(10) << "Name:\t"
        << std::setw(10) << "Amount:\t"
        << std::setw(10) << "Price:\n";

    for (const auto el : store.cargo_) {
        out << i << ":\t" << std::setw(10) << el->getName() << '\t' << std::setw(10)
            << el->getAmount() << '\t' << std::setw(10) << el->getPrice() << '\n';
        i++;
    }

    return out;
}
