#include "store.hpp"
#include "alcohol.hpp"
#include "fruit.hpp"
#include "item.hpp"

#include <algorithm>
#include <random>

std::string Store::getResponse(const Response& response) {
    switch (response) {
    case Response::done:
        return "done";
    case Response::lack_of_cargo:
        return "Lack of cargo";
    case Response::lack_of_money:
        return "Lack of money";
    case Response::lack_of_space:
        return "Lack of space";
    }
}

std::vector<std::shared_ptr<Cargo>>::iterator Store::findCargo(const std::shared_ptr<Cargo>& cargo) {
    auto find = std::find_if(stock_.begin(), stock_.end(),
                             [cargo](const auto& el) { return cargo->getName() == el->getName() &&
                                                              cargo->getBasePrice() == el->getBasePrice(); });
    return find;
}

void Store::load(std::shared_ptr<Cargo> cargo, size_t amount) {
    auto newLoad = findCargo(cargo);

    if (newLoad == stock_.end()) {
        stock_.push_back(cargo);
        return;
    }

    **newLoad += amount;
}

void Store::unload(std::shared_ptr<Cargo> cargo, size_t amount) {
    auto soldCargo = findCargo(cargo);
    if (soldCargo == stock_.end()) {
        return;
    }
    if ((*soldCargo)->getAmount() <= cargo->getAmount()) {
        stock_.erase(findCargo(cargo));
    }
    **soldCargo -= amount;
}

Response Store::buy(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player) {
    if (amount > player->getAvailableSpace()) {
        return Response::lack_of_space;
    }
    if (player->getMoney() < cargo->getBasePrice() * amount) {
        return Response::lack_of_money;
    }
    if (findCargo(cargo) == stock_.end()) {
        return Response::lack_of_cargo;
    }
    unload(cargo, amount);
    player->setMoney(player.get()->getMoney() - amount * cargo->getBasePrice());

    return Response::done;
}

Response Store::sell(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player) {

    player ->setMoney(player->getMoney() + cargo->getPrice());
    player->
}



constexpr int minAmount = 0;
constexpr int maxAmount = 20;
void Store::randomizeCargo(std::vector<std::shared_ptr<Cargo>> storeCargos) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randomAmount(minAmount, maxAmount);

    for (auto& cargo : storeCargos) {
        *cargo += randomAmount(gen);
        stock_.push_back(cargo);
    }
}

void Store::generateCargo() {
    std::vector<std::shared_ptr<Cargo>> posibleStoreCargos {
        std::make_shared<Fruit>(Fruit("Apple", 0, 50, 10)),
        std::make_shared<Fruit>(Fruit("Orange", 0, 30, 10)),
        std::make_shared<Fruit>(Fruit("Banana", 0, 50, 10)),
        std::make_shared<Fruit>(Fruit("Peach", 0, 50, 10)),
        std::make_shared<Fruit>(Fruit("Water melon", 0, 50, 10)),
        std::make_shared<Item>(Item("Ivory", 0, 200, Rarity::rare)),
        std::make_shared<Item>(Item("Thor's hummer", 0, 200, Rarity::legendary)),
        std::make_shared<Item>(Item("Gold neckle", 0, 200, Rarity::rare)),
        std::make_shared<Item>(Item("Souron's ring", 0, 200, Rarity::legendary)),
        std::make_shared<Item>(Item("Philosopher's stone", 0, 200, Rarity::legendary)),
        std::make_shared<Item>(Item("Knife and fork", 0, 200, Rarity::common)),        
        std::make_shared<Alcohol>(Alcohol("Johny Daniels", 0, 10, 50)),
        std::make_shared<Alcohol>(Alcohol("Jack Walker", 0, 10, 50)),
        std::make_shared<Alcohol>(Alcohol("Vodka", 0, 10, 40)),
        std::make_shared<Alcohol>(Alcohol("Beer", 0, 10, 8)),
        std::make_shared<Alcohol>(Alcohol("Gin", 0, 10, 20)),
        std::make_shared<Alcohol>(Alcohol("Pina Colada", 0, 10, 15))};

    randomizeCargo(posibleStoreCargos);
}