#include "Store.hpp"

#include <algorithm>
#include <iomanip>
#include <iterator>
#include <random>

#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"
#include "Store.hpp"

Store::Store(Time* time)
    : time_(time) {
    time_->addObserver(this);
    generateCargo();
}

Store::~Store() {
    time_->removeObserver(this);
}

void Store::generateCargo() {
    std::vector<std::shared_ptr<Cargo>> possibleCargos{
        std::make_shared<Alcohol>(Alcohol(0, "Vodka", 30, 40)),
        std::make_shared<Alcohol>(Alcohol(0, "Rum", 50, 70)),
        std::make_shared<Alcohol>(Alcohol(0, "Whisky", 35, 45)),
        std::make_shared<Alcohol>(Alcohol(0, "Beer", 5, 7)),
        std::make_shared<Alcohol>(Alcohol(0, "Panoramix cauldron", 100, 90)),
        std::make_shared<Fruit>(Fruit(0, "Apple", 15, 14)),
        std::make_shared<Fruit>(Fruit(0, "Dried plums", 100, 100)),
        std::make_shared<Fruit>(Fruit(0, "Strawberries", 4, 6)),
        std::make_shared<Fruit>(Fruit(0, "Peach", 8, 10)),
        std::make_shared<Fruit>(Fruit(0, "Cherry", 12, 12)),
        std::make_shared<Item>(Item(0, "Bottle", 10, Rarity::common)),
        std::make_shared<Item>(Item(0, "Knife", 25, Rarity::rare)),
        std::make_shared<Item>(Item(0, "Sword", 70, Rarity::epic)),
        std::make_shared<Item>(Item(0, "Compass", 90, Rarity::epic)),
        std::make_shared<Item>(Item(0, "Golden Necklace", 200, Rarity::legendary))};

    randomizeCargo(possibleCargos);
}

constexpr uint16_t minRandomAmount = 0;
constexpr uint16_t maxRandomAmount = 10;

void Store::randomizeCargo(const std::vector<std::shared_ptr<Cargo>>& possibleCargos) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randomAmount(minRandomAmount, maxRandomAmount);

    for (const auto& cargo : possibleCargos) {
        *cargo += randomAmount(gen);
        cargos_.push_back(cargo);
    }
}

std::vector<std::shared_ptr<Cargo>>::iterator Store::findMatchCargo(std::shared_ptr<Cargo> cargo) {
    auto findCargo = std::find_if(cargos_.begin(), cargos_.end(),
                                  [cargo](const auto& el) {
                                      return cargo->getBasePrice() == el->getBasePrice() &&
                                             cargo->getPrice() == el->getPrice() &&
                                             cargo->getName() == el->getName();
                                  });

    return findCargo;
}

void Store::removeFromStore(std::shared_ptr<Cargo> cargo) {
    cargos_.erase(findMatchCargo(cargo));
}

void Store::load(std::shared_ptr<Cargo> cargo, uint16_t amount) {
    auto isCargoUniqe = findMatchCargo(cargo);

    if (isCargoUniqe == cargos_.end()) {
        cargos_.push_back(cargo);
        return;
    }

    **isCargoUniqe += amount;
}

void Store::unload(std::shared_ptr<Cargo> cargo, uint16_t amount) {
    auto choosenCargo = findMatchCargo(cargo);

    if (choosenCargo == cargos_.end()) {
        return;
    }

    if ((*choosenCargo)->getAmount() <= cargo->getAmount()) {
        removeFromStore(cargo);
        return;
    }

    **choosenCargo -= amount;
}

Cargo* Store::getCargo(const uint16_t index) const {
    return (index < cargos_.size()) ? cargos_[index].get() : nullptr;
}

std::string getResponseMessage(const Response& responseMessage) {
    switch (responseMessage) {
    case Response::done:
        return "Done!";
    case Response::lack_of_cargo:
        return "Lack of cargo!";
    case Response::lack_of_money:
        return "Lack of money!";
    case Response::lack_of_space:
        return "Lack of space!";
    }
}

Response Store::buy(std::shared_ptr<Cargo> cargo, uint16_t amount, Player* player) {
    if (amount > player->getAvailableSpace()) {
        return Response::lack_of_space;
    }

    if (amount * cargo->getPrice() > player->getMoney()) {
        return Response::lack_of_money;
    }

    if (findMatchCargo(cargo) == cargos_.end()) {
        return Response::lack_of_cargo;
    }

    unload(cargo, amount);
    player->setMoney(player->getMoney() - cargo->getPrice());
    player->loadCargoOnShip(cargo);

    return Response::done;
}

Response Store::sell(std::shared_ptr<Cargo> cargo, uint16_t amount, Player* player) {
    load(cargo, amount);
    player->setMoney(player->getMoney() + cargo->getPrice());
    player->unloadCargoFromShip(cargo, amount);

    return Response::done;
}

constexpr bool addOption = true;
constexpr bool subtractOption = false;
constexpr uint16_t minRandomAmountChangeEachDay = 0;
constexpr uint16_t maxRandomAmountChangeEachDay = 5;

void Store::nextDay() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randomAmountChangeEachDay(minRandomAmountChangeEachDay, maxRandomAmountChangeEachDay);
    std::uniform_int_distribution<> options(addOption, subtractOption);

    for (const auto& cargo : cargos_) {
        if (options(gen) == addOption) {
            *cargo += randomAmountChangeEachDay(gen);
        } else {
            *cargo -= randomAmountChangeEachDay(gen);
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    for (const auto& cargo : store.cargos_) {
        out << '\n'
            << std::setfill('#') << std::setw(40) << '\n';
        out << "Item name: " << std::setw(20) << cargo->getName() << std::setw(3) << " | ";
        out << "Price: " << std::setw(20) << cargo->getPrice() << std::setw(3) << " | ";
        out << "Amount: " << std::setw(20) << cargo->getAmount() << std::setw(3) << " | ";
    }

    return out;
}
