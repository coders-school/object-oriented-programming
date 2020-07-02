#include "store.hpp"

#include <algorithm>
#include <random>

Store::Store() {}
Store::~Store() {}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    out << "Available Cargo in Store: \n0 - Exit \n";
    std::for_each(store.cargo_.begin(), store.cargo_.end(), [&, i{0}](const auto& cargo) mutable {
        out << ++i << " - " << cargo->getName() << "  AMOUNT: " << cargo->getAmount()
            << "  PRICE: " << cargo->getBasePrice() << '\n';
    });
    return out;
}

Store::Response Store::buy(std::shared_ptr<Cargo> cargo, uint32_t amount, Player* player) {
    const uint32_t price = amount * cargo->getBasePrice();
    std::shared_ptr<Cargo> buyCargo = cargo->clone();

    if (amount > player->getAvailableSpace()) {
        return Store::Response::lack_of_space;
    }
    if (amount > cargo->getAmount()) {
        return Store::Response::lack_of_cargo;
    }
    if (price > player->getMoney()) {
        return Store::Response::lack_of_money;
    }
    *cargo -= amount;
    *buyCargo -= cargo->getAmount();
    player->purchaseCargo(buyCargo, amount, price);

    return Store::Response::done;
}

Store::Response Store::sell(std::shared_ptr<Cargo> cargo, uint32_t amount, Player* player) {
    const uint32_t price = amount * cargo->getBasePrice();

    if (amount > cargo->getAmount()) {
        return Store::Response::lack_of_cargo;
    }
    player->sellCargo(cargo, amount, price);
    loadToStore(cargo, amount);
    return Store::Response::done;
}

std::shared_ptr<Cargo> Store::getCargo(uint32_t index) const {
    if (cargo_.size() > index) {
        return cargo_[index];
    }
    return nullptr;
}

void Store::generateCargo() {
    const int minAmountOfCargo = 50;
    const int maxAmountOfCargo = 300;
    const int minPriceOfCargo = 5;
    const int maxPriceOfCargo = 15;
    std::uniform_int_distribution<> amountOfCargo(minAmountOfCargo, maxAmountOfCargo);
    std::uniform_int_distribution<> priceOfCargo(minPriceOfCargo, maxPriceOfCargo);
    std::random_device rd;
    std::mt19937 gen(rd());

    cargo_.push_back(std::make_shared<Fruit>(Fruit(amountOfCargo(gen), "Oranges", priceOfCargo(gen), 6)));
    cargo_.push_back(std::make_shared<Fruit>(Fruit(amountOfCargo(gen), "Bananas", priceOfCargo(gen), 4)));
    cargo_.push_back(std::make_shared<Fruit>(Fruit(amountOfCargo(gen), "Apples", priceOfCargo(gen), 9)));

    cargo_.push_back(std::make_shared<Alcohol>(Alcohol(amountOfCargo(gen), "Vodka", priceOfCargo(gen), 40)));
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol(amountOfCargo(gen), "Liquor", priceOfCargo(gen), 24)));
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol(amountOfCargo(gen), "Whiskey", priceOfCargo(gen), 38)));
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol(amountOfCargo(gen), "Bimber", priceOfCargo(gen), 70)));

    cargo_.push_back(
        std::make_shared<Item>(Item(amountOfCargo(gen), "Woods", priceOfCargo(gen), Item::Rarity::common)));
    cargo_.push_back(std::make_shared<Item>(Item(amountOfCargo(gen), "Bronze", priceOfCargo(gen), Item::Rarity::rare)));
    cargo_.push_back(std::make_shared<Item>(Item(amountOfCargo(gen), "Silver", priceOfCargo(gen), Item::Rarity::epic)));
    cargo_.push_back(
        std::make_shared<Item>(Item(amountOfCargo(gen), "Gold", priceOfCargo(gen), Item::Rarity::legendary)));
    //   for_each(cargoProducts.begin(), cargoProducts.end(),
    //           [&](const auto& cargo) { cargo_.push_back(std::make_shared<cargo.second()>; });
}

void Store::printCargo() const {
    std::cout << "CARGO IN STORE : "
              << "\n";
    std::for_each(cargo_.begin(), cargo_.end(), [](const auto& cargo) {
        std::cout << cargo->getName() << "  " << cargo->getAmount() << "  " << cargo->getBasePrice() << "\n";
    });
}

void Store::loadToStore(std::shared_ptr<Cargo> cargo, uint32_t amount) {
    for (auto& element : cargo_) {
        if (cargo.get()->getName() == element->getName()) {
            *element += amount;
            return;
        }
    }
    cargo_.emplace_back(cargo);
}
