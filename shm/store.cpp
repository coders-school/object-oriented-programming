#include "store.hpp"

#include <algorithm>
#include <random>

Store::Store(Time* time) : time_(time) {
    time_->registerObserver(this);
}

Store::~Store() {
    time_->unregisterObserver(this);
}

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

    if(!cargo_.empty()) {
        cargo_.clear();
    }

    const int minAmountOfCargo = 50;
    const int maxAmountOfCargo = 300;
    const int minPriceOfCargo = 5;
    const int maxPriceOfCargo = 15;
    const int minExpiryDateOfFruits = 1;
    const int maxExpiryDateOfFruits = 10;
    std::uniform_int_distribution<> amountOfCargo(minAmountOfCargo, maxAmountOfCargo);
    std::uniform_int_distribution<> priceOfCargo(minPriceOfCargo, maxPriceOfCargo);
    std::uniform_int_distribution<> expiryDateOfFruits(minExpiryDateOfFruits, maxExpiryDateOfFruits);
    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<std::pair<std::string, int>> cargoProducts = {
        {"Oranges", 1}, {"Bananas", 1}, {"Apples", 1}, {"Vodka", 2},  {"Liquor", 2}, {"Whkiskey", 2},
        {"Bimber", 2},  {"Woods", 3},   {"Bronze", 3}, {"Silver", 3}, {"Gold", 3}};

    for_each(cargoProducts.begin(), cargoProducts.end(), [&](const auto& cargo) {
        if (cargo.second == 1) {
            cargo_.push_back(
                std::make_shared<Fruit>(amountOfCargo(gen), cargo.first, priceOfCargo(gen), expiryDateOfFruits(gen)));
        }
        if (cargo.second == 2) {
            cargo_.push_back(std::make_shared<Alcohol>(amountOfCargo(gen), cargo.first, priceOfCargo(gen), 40));
        }
        if (cargo.second == 3) {
            cargo_.push_back(
                std::make_shared<Item>(amountOfCargo(gen), cargo.first, priceOfCargo(gen), Item::Rarity::common));
        }
    });

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

void Store::nextDay() {
    std::cout << "Next day in: " << " STORE" << " \n";
    this->generateCargo();
}
