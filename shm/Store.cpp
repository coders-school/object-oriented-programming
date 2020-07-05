#include "Store.h"

#include <algorithm>
#include <random>

#include "Alcohol.h";
#include "Fruit.h";
#include "Item.h";

Store::Store(Time* time)
    : time_(time) {
    generateCargos();
    time_->subscribe(this);
}

//override from Observer;
Store::~Store() {
    time_->unsubscribe(this);
}

void Store::generateCargos() {
    available_cargos_.clear();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> amountDistrib(min_cargo_amount, max_cargo_amount);
    std::uniform_int_distribution<> priceDistrib(min_price, max_price);
    std::uniform_int_distribution<> itemDistrib(0, available_items.size());

    size_t cargoAmount = amountDistrib(gen);
    size_t cargoPrice = priceDistrib(gen);
    ItemData itemData = available_items[itemDistrib(gen)];
    available_cargos_.push_back(std::make_unique<Item>(new Item::Item(itemData.name_, cargoAmount, cargoPrice, itemData.rarity_)));

    std::uniform_int_distribution<> fruitDistrib(0, available_fruits.size());
    cargoAmount = amountDistrib(gen);
    cargoPrice = priceDistrib(gen);
    FruitData fruitData = available_fruits[fruitDistrib(gen)];
    available_cargos_.push_back(std::make_unique<Item>(new Fruit::Fruit(fruitData.name_, cargoAmount, cargoPrice, fruitData.expiration_date_)));

    std::uniform_int_distribution<> alcohohlDistrib(0, available_alcohols.size());
    cargoAmount = amountDistrib(gen);
    cargoPrice = priceDistrib(gen);
    AlcoholData alcoholData = available_alcohols[alcohohlDistrib(gen)];
    available_cargos_.push_back(std::make_unique<Item>(new Alcohol::Alcohol(alcoholData.name_, cargoAmount, cargoPrice, alcoholData.power_)));
}

Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    if (player->getAvailableSpace() < amount) {
        return Response::lack_of_space;
    }

    auto foundCargoIt = std::find(available_cargos_.begin(), available_cargos_.end(), [&cargo](auto otherCargo) {
        return cargo == otherCargo;
    });

    if (foundCargoIt == available_cargos_.end() || foundCargoIt->get()->getAmount() < amount) {
        return Response::lack_of_cargo;
    }
    size_t totalPrice = foundCargoIt->get()->getPrice() * amount;

    if (player->getMoney() < totalPrice) {
        return Response::lack_of_money;
    }

    player->setMoney(player->getMoney() - totalPrice);
    player->getShip()->load(std::make_shared<Cargo>(cargo));
    return Response::done;
}

Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    auto foundCargoIt = std::find(player->getCargos().begin(), player->getCargos().end(), cargo);

    if (foundCargoIt == player->getCargos().end() || foundCargoIt->get()->getAmount() < amount) {
        return Response::lack_of_cargo;
    }

    size_t totalPrice = foundCargoIt->get()->getPrice() * amount;
    player->setMoney(player->getMoney() + totalPrice);

    cargo -= amount;
    if (cargo->getAmount() == 0) {
        player->getShip()->unload(cargo);
    }

    return Response::done;
}

void Store::nextDay() {
    generateCargos();
}

//override from Observer;
void Store::update() {
    nextDay();
}

std::string Store::getDescription() const {
    std::string description = "";
    for (auto&& it : available_cargos_) {
        description += it->getDescription();
        description += "\n------\n";
    }
    return description;
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    return out << store.getDescription();
}