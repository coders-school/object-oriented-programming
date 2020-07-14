#include "store.hpp"

#include <algorithm>
#include <iostream>
#include <random>

#include "alcohol.hpp"
#include "dryfruit.hpp"
#include "fruit.hpp"
#include "globaltime.hpp"

Store::Store(Time* time)
    : time_(time) {
    time_->addObserver(this);
    GlobalTime::provideGlobalTime(time_);
    generateCargo();
}

Store::~Store() {
    time_->removeObserver(this);
}

void Store::generateCargo() {
    constexpr size_t kNumOfCargos = 5;

    for (size_t i = 0; i < kNumOfCargos; i++) {
        switch (chooseType()) {
        case CargoType::Fruit:
            generateFruit();
            break;
        case CargoType::DryFruit:
            generateDryFruit();
            break;
        case CargoType::Alcohol:
            generateAlcohol();
            break;
        case CargoType::Item:
            generateItem();
            break;
        }
    }
}

Store::CargoType Store::chooseType() {
    constexpr auto kMinType = static_cast<int>(CargoType::Fruit);
    constexpr auto kMaxType = static_cast<int>(CargoType::Item);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> typeDistrib(kMinType, kMaxType);

    return static_cast<CargoType>(typeDistrib(gen));
}

size_t Store::generateQuantity() {
    constexpr size_t kMinQuantity = 20;
    constexpr size_t kMaxQuantity = 70;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> quantityDistrib(kMinQuantity, kMaxQuantity);

    return quantityDistrib(gen);
}

size_t Store::generatePrice() {
    constexpr size_t kMinPrice = 5;
    constexpr size_t kMaxPrice = 30;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> priceDistrib(kMinPrice, kMaxPrice);

    return priceDistrib(gen);
}

size_t Store::generateExpDate() {
    constexpr size_t kMinDate = 2;
    constexpr size_t kMaxDate = 7;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dateDistrib(kMinDate, kMaxDate);

    return dateDistrib(gen);
}

Item::Rarity Store::generateRarity() {
    constexpr auto kMinRarity = static_cast<int>(Item::Rarity::common);
    constexpr auto kMaxRarity = static_cast<int>(Item::Rarity::legendary);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> rarityDistrib(kMinRarity, kMaxRarity);

    return static_cast<Item::Rarity>(rarityDistrib(gen));
}

void Store::generateFruit() {
    size_t quantity = generateQuantity();
    std::unique_ptr<Cargo> cargo = std::make_unique<Fruit>(Fruit("orange", quantity, generatePrice(), generateExpDate()));
    receiveCargo(std::move(cargo.get()), quantity, this);
}

void Store::generateDryFruit() {
    size_t quantity = generateQuantity();
    std::unique_ptr<Cargo> cargo = std::make_unique<DryFruit>(DryFruit("orange", quantity, generatePrice(), generateExpDate()));
    receiveCargo(std::move(cargo.get()), quantity, this);
}

void Store::generateAlcohol() {
    size_t quantity = generateQuantity();
    std::unique_ptr<Cargo> cargo = std::make_unique<Alcohol>(Alcohol("vodka", quantity, generatePrice(), 40.f));
    receiveCargo(std::move(cargo.get()), quantity, this);
}

void Store::generateItem() {
    size_t quantity = generateQuantity();
    std::unique_ptr<Cargo> cargo = std::make_unique<Item>(Item("sword", quantity, generatePrice(), generateRarity()));
    receiveCargo(std::move(cargo.get()), quantity, this);
}

Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    if (cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    }

    auto totalPrice = amount * cargo->getPrice();
    player->changeMoney(totalPrice);
    receiveCargo(cargo, amount, player);
    return Response::done;
}

Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    if (player->getavailableSpace() < amount) {
        return Response::lack_of_space;
    }

    auto totalPrice = amount * cargo->getPrice();
    if (player->getMoney() < totalPrice) {
        return Response::lack_of_money;
    }

    auto cargoIt = std::find_if(cargo_.begin(), cargo_.end(), [cargo](auto& cargoPtr) { return cargoPtr.get() == cargo; });
    if (cargoIt == cargo_.end() || (*cargoIt)->getAmount() < amount) {
        return Response::lack_of_cargo;
    }

    player->changeMoney(-totalPrice);
    player->receiveCargo(cargo, amount, this);
    return Response::done;
}

void Store::receiveCargo(Cargo* cargo, size_t amount, CargoHolder* cargoHolder) {
    cargo_.push_back(cargo->getShared());

    (*cargo_.back()) -= (cargo_.back()->getAmount() - amount);
    (*cargo) -= amount;
    if (cargo->getAmount() == 0) {
        cargoHolder->clearEmptyCargos();
    }
}

void Store::clearEmptyCargos() {
    cargo_.erase(std::remove_if(cargo_.begin(), cargo_.end(), [](auto& cargo) { return cargo->getAmount() == 0; }), cargo_.end());
}

void Store::nextDay() {
    constexpr size_t addItems = 1;
    constexpr size_t removeItems = 0;
    constexpr size_t minQuantityOfProducts = 40;
    constexpr size_t maxQuantityOfProducts = 100;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> optionDistrib(removeItems, addItems);
    std::uniform_int_distribution<> quantityDistrib(minQuantityOfProducts, maxQuantityOfProducts);

    size_t option = optionDistrib(gen);

    if (option == addItems) {
        for (auto& item : cargo_) {
            *item += quantityDistrib(gen);
        }
    } else if (option == removeItems) {
        for (auto& item : cargo_) {
            *item -= quantityDistrib(gen);
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    out << "Cargo that you can buy here:\n";
    out << "-----------------------------\n";
    std::for_each(store.cargo_.begin(), store.cargo_.end(),
                  [&out, counter{1}](const auto& cargo) mutable {
                      out << counter++ << ") " << cargo->getName() << '\n';
                      out << "Amount: " << cargo->getAmount() << '\n';
                      out << "Price: " << cargo->getPrice() << '\n';
                      if (typeid(*cargo) == typeid(Alcohol)) {
                          auto alcohol = static_cast<Alcohol*>(cargo.get());
                          out << "Power: " << alcohol->getPower() << "%\n";
                      } else if (typeid(*cargo) == typeid(Fruit) || typeid(*cargo) == typeid(DryFruit)) {
                          auto fruit = static_cast<Fruit*>(cargo.get());
                          out << "Time to spoil: " << fruit->getTimeToSpoil() << '\n';
                      } else if (typeid(*cargo) == typeid(Item)) {
                          auto item = static_cast<Item*>(cargo.get());
                          switch (item->getRarity()) {
                          case Item::Rarity::common:
                              out << "Rarity: common\n";
                              break;
                          case Item::Rarity::epic:
                              out << "Rarity: epic\n";
                              break;
                          case Item::Rarity::legendary:
                              out << "Rarity: legendary\n";
                              break;
                          case Item::Rarity::rare:
                              out << "Rarity: rare\n";
                              break;
                          }
                      }
                      out << "-----------------------------\n";
                  });
    return out;
}
