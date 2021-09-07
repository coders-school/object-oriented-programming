#include "store.hpp"
#include "alcohol.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "player.hpp"
#include "ship.hpp"

#include <algorithm>
#include <iomanip>
#include <random>
#include <typeinfo>

constexpr size_t AMOUNT_MIN = 5;
constexpr size_t AMOUNT_MAX = 150;
constexpr size_t POWER_MIN = 10;
constexpr size_t POWER_MAX = 90;
constexpr size_t DAY_MIN = 5;
constexpr size_t DAY_MAX = 17;
constexpr size_t PRICE_MIN = 5;
constexpr size_t PRICE_MAX = 145;

Store::Store() {
    generateDefaultCargo();
}

std::vector<std::shared_ptr<Cargo>>::iterator Store::findMatchCargo(const std::shared_ptr<Cargo> wantedCargo) {
    auto find = std::find_if(stock_.begin(),
                             stock_.end(),
                             [&wantedCargo](const auto& cargo) { return cargo->getName() == wantedCargo->getName(); });

    return find;
}

Response Store::buy(std::shared_ptr<Cargo> cargo, const size_t& amount, Player* player) {
    if (!cargo || !amount || !player) {
        return Response::lack_of_cargo;
    }

    std::shared_ptr<Ship> playerShip = player->getShip();
    if (!playerShip) {
        return Response::lack_of_cargo;
    }

    auto shipCargo = playerShip->findMatchCargo(cargo);
    auto shipStock = playerShip->getCargosVector();
    if (shipCargo == shipStock.end()) {
        return Response::lack_of_cargo;
    }

    if (shipCargo->get()->getAmount() < amount) {
        return Response::lack_of_cargo;
    }

    player->sell(cargo, amount);
    unloadShip(cargo, amount);

    return Response::done;
}

Response Store::sell(std::shared_ptr<Cargo> cargo, const size_t& amount, Player* player) {
    if (!cargo || !amount) {
        Response::lack_of_cargo;
    }

    if (!player) {
        return Response::lack_of_space;
    }

    std::shared_ptr<Ship> playerShip = player->getShip();
    if (!playerShip) {
        return Response::lack_of_space;
    }
    auto wantedCargo = findMatchCargo(cargo);
    if (wantedCargo != stock_.end()) {
        if (wantedCargo->get()->getAmount() < amount) {
            std::cout << "Not enough cargo in Store \n";
            return Response::lack_of_cargo;
        }
    }

    if (player->getAvailableSpace() < amount) {
        std::cout << "There is no space on the ship\n";
        return Response::lack_of_space;
    }

    if (player->getMoney() <= 0) {
        std::cout << "NO MONEY\n";
        return Response::lack_of_money;
    }

    player->buy(cargo, amount);
    std::cout << '\n';
    loadShip(cargo, amount);
    return Response::done;
}

std::ostream& operator<<(std::ostream& os, const Store& store) {
    int counter = 1;
    os << '\n';
    os << std::setfill(' ') << "ID" << std::setw(30) << " TYPE OF CARGO" << std::setw(18) << "AMOUNT" << std::setw(27) << "PRICE\n";
    for (const auto& el : store.stock_) {
        os << std::left << std::setfill(' ') << std::setw(19) << counter << std::setw(25) << el->getName() << std::setw(27) << el->getAmount() << std::setw(5) << el->getPrice() << '\n';
        counter++;
    }
    os << std::setfill('*') << std::setw(100) << "\n";

    return os;
}

void Store::generateDefaultCargo() {
    std::random_device rm;
    std::mt19937 gr(rm());

    std::uniform_int_distribution<> amountR(AMOUNT_MIN, AMOUNT_MAX);
    std::uniform_int_distribution<> powerR(POWER_MIN, POWER_MAX);
    std::uniform_int_distribution<> dayR(DAY_MIN, DAY_MAX);
    std::uniform_int_distribution<> priceR(PRICE_MIN, PRICE_MAX);

    stock_.reserve(50);
    stock_.push_back(std::make_shared<Alcohol>("BUH", amountR(gr), priceR(gr), powerR(gr)));
    stock_.push_back(std::make_shared<Alcohol>("Jack Walker", amountR(gr), priceR(gr), powerR(gr)));
    stock_.push_back(std::make_shared<Alcohol>("Johny Daniels", amountR(gr), priceR(gr), powerR(gr)));
    stock_.push_back(std::make_shared<Alcohol>("Żubrówkeczka", amountR(gr), priceR(gr), powerR(gr)));
    stock_.push_back(std::make_shared<Fruit>("Peach", amountR(gr), priceR(gr), dayR(gr)));
    stock_.push_back(std::make_shared<Fruit>("Strawbarry", amountR(gr), priceR(gr), dayR(gr)));
    stock_.push_back(std::make_shared<Fruit>("Water melon", amountR(gr), priceR(gr), dayR(gr)));
    stock_.push_back(std::make_shared<Fruit>("Coconat", amountR(gr), priceR(gr), dayR(gr)));
    stock_.push_back(std::make_shared<Item>("Fork", amountR(gr), priceR(gr), Rarity::common));
    stock_.push_back(std::make_shared<Item>("Philosopher's stone", amountR(gr), priceR(gr), Rarity::legendary));
    stock_.push_back(std::make_shared<Item>("necklace", amountR(gr), priceR(gr), Rarity::rare));
    stock_.push_back(std::make_shared<Item>("Ivory", amountR(gr), priceR(gr), Rarity::rare));
    stock_.shrink_to_fit();
}

void Store::loadShip(std::shared_ptr<Cargo> cargo, const size_t& amount) {
    if (!cargo) {
        return;
    }

    auto loadedCargo = findMatchCargo(cargo);
    if (loadedCargo != stock_.end()) {
        loadedCargo->get()->setAmount(loadedCargo->get()->getAmount() - amount);

        if (loadedCargo->get()->getAmount() == 0) {
            stock_.erase(loadedCargo);
        }
    }
    if (loadedCargo == stock_.end()) {
        std::cout << "There is no cargo!!!\n";
        return;
    }
}

void Store::unloadShip(std::shared_ptr<Cargo> cargo, const size_t& amount) {
    if (!cargo) {
        return;
    }

    auto unloadCargo = findMatchCargo(cargo);
    if (unloadCargo != stock_.end()) {
        unloadCargo->get()->setAmount(unloadCargo->get()->getAmount() + amount);
    }
    addCargo(cargo, amount);
}

void Store::addCargo(std::shared_ptr<Cargo> cargo, const size_t& amount) {
    if (Alcohol* alcohol = dynamic_cast<Alcohol*>(cargo.get())) {
        stock_.push_back(std::make_shared<Alcohol>(alcohol->getName(),
                                                   amount,
                                                   alcohol->getBasePrice(),
                                                   alcohol->getPercentage()));
    } else if (Fruit* fruit = dynamic_cast<Fruit*>(cargo.get())) {
        stock_.push_back(std::make_shared<Fruit>(fruit->getName(),
                                                 amount,
                                                 fruit->getBasePrice(),
                                                 fruit->getExpirationDate()));
    } else if (Item* item = dynamic_cast<Item*>(cargo.get())) {
        stock_.push_back(std::make_shared<Item>(item->getName(),
                                                amount,
                                                item->getPrice(),
                                                item->getRarity()));
    }
}

void Store::nextDay() {
    for (auto cargo : Store::getCargoOfStore()) {
        if(cargo) {
            std::random_device rm;
            std::mt19937 gr(rm());
            int more_stuff_in_store = 1;
            int less_stuff_in_store = 0;
            int adding_taking_max = 10;
            int adding_taking_min = 1;
            std::uniform_int_distribution<> in_store_action(less_stuff_in_store, more_stuff_in_store);
            std::uniform_int_distribution<> to_add_or_take(adding_taking_min, adding_taking_max);
            int storeCapacity = 500;
            if(in_store_action(gr)) {
                *cargo += to_add_or_take(gr);
                if (cargo->getAmount() > storeCapacity) {
                    *cargo -= cargo->getAmount() - storeCapacity;
                }
            } else {
                *cargo -= to_add_or_take(gr);
                if (cargo->getAmount() < 0) {
                    *cargo -= cargo->getAmount();
                }
                if (cargo->getAmount() > storeCapacity) {
                    *cargo -= cargo->getAmount() - storeCapacity;
                }
            }
        }
    }
}
