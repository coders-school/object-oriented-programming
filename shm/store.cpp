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

Store::Store()
    {
        generateDefaultCargo();
    };

std::vector<std::shared_ptr<Cargo>>::iterator Store::findCargoInStore(const std::shared_ptr<Cargo>& wantedCargo) {
    auto find = std::find_if(stock_.begin(),
                             stock_.end(),
                             [wantedCargo](const std::shared_ptr<Cargo>& cargo) { return *cargo == *wantedCargo; });
}

Response Store::buy(std::shared_ptr<Cargo> cargo, size_t amount, Player* player) {
    if (!cargo || !amount || !player) {
        return Response::lack_of_cargo;
    }

    std::shared_ptr<Ship> playerShip = player->getShip();
    if (!playerShip) {
        return Response::lack_of_cargo;
    }

    auto soldPlayerCargo = playerShip->getCargosVector()[0];
    for (const auto el : playerShip->getCargosVector()) {
        auto loopCargo = el;

        if (loopCargo == cargo) {
            if (loopCargo->getAmount() < amount) {
                return Response::lack_of_space;
            }
        }
        soldPlayerCargo = loopCargo;
    }

    if (!soldPlayerCargo) {
        return Response::lack_of_cargo;
    }

    // player sell

    if (soldPlayerCargo->getAmount() < amount) {
        auto playerPrice = soldPlayerCargo->getAmount() * soldPlayerCargo->getPrice();

        //playerShip->;  // funkcja wyładunku ze statku napisać.;
        int a = 3;
        player->setMoney(player->getMoney() + playerPrice);
    }
}

Response Store::sell(std::shared_ptr<Cargo> cargo, size_t amount, Player* player) {
    //lack of an amount of cargo in store
    if (!cargo || !amount) {
        Response::lack_of_cargo;
    }

    //lack of space on player's ship
    if (!player) {
        return Response::lack_of_space;
    }

    std::shared_ptr<Ship> playerShip = player->getShip();
    if (!playerShip) {
        return Response::lack_of_space;
    }

    // Check if player can take cargo on ship
    bool playerHaveTheSameCargo = false;
    auto playerCargo = playerShip->getCargosVector();
    for (const auto& el : playerCargo) {
        if (el == cargo) {
            playerHaveTheSameCargo = true;
            break;
        }
    }
    if (!playerHaveTheSameCargo && player->getAvailableSpace()) {
        return Response::lack_of_space;
    }

    // Finding cargo in the store
    auto StoredCargo = findCargoInStore(cargo);

    if (!StoredCargo->get()) {
        return Response::lack_of_cargo;
    }

    // not enough cargo amount in the store

    if (StoredCargo->get()->getAmount() < amount) {
        return Response::lack_of_cargo;
    }

    // Too expenisive for player

    if (player->getMoney() < amount * (StoredCargo->get()->getPrice())) {
        return Response::lack_of_money;
    }

    // Dopisać co sie stanie gdy dojedzie do sprzedaży.
    // Unload ze Statku. Load na statek.
    // Jak sie zmieni konto gracza.
    //if()
}
void Store::load(const std::shared_ptr<Cargo>& cargo) {
    auto storeCargo = findCargoInStore(cargo);
    if (!cargo) {
        return;
    }
    if (storeCargo != stock_.end()) {
        **storeCargo += cargo->getAmount();
        return;
    }
    /// Dopracuj co sie dziej jeżeli to nie jest nullptr, ale nie ma go w wektorze stock_;
}

void Store::unload(const std::shared_ptr<Cargo>& cargo) {
    if (!cargo) {
        return;
    }
    auto storeCargo = findCargoInStore(cargo);

    if (storeCargo != stock_.end()) {
        **storeCargo -= cargo->getAmount();
    }
}

std::ostream& operator<<(std::ostream& os, const Store& store) {
    int counter = 1;
    for (const auto& el : store.stock_) {
        os << "|" << std::setw(20);
        os << std::setfill(' ') << std::setw(20) << "ID: " << counter;
        os << std::setw(20) << " TYPE OF CARGO: " << el->getName();
        os << std::setw(20) << " AMOUNT: " << el->getAmount();
        os << std::setw(20) << " PRICE: " << el->getPrice() << '\n';
        counter++;
    }
    os << "|" << std::setfill('*') << std::setw(100) << "|\n";

    return os;
}
constexpr size_t AMOUNT_MIN = 5;
constexpr size_t AMOUNT_MAX = 150;
constexpr size_t POWER_MIN = 10;
constexpr size_t POWER_MAX = 90;
constexpr size_t DAY_MIN = 5;
constexpr size_t DAY_MAX = 17;
constexpr size_t PRICE_MIN = 5;
constexpr size_t PRICE_MAX = 145;

void Store::generateDefaultCargo() {
    std::random_device rm;
    std::mt19937 gr(rm());

    std::uniform_int_distribution<> amountR(AMOUNT_MIN, AMOUNT_MAX);
    std::uniform_int_distribution<> powerR(POWER_MIN, POWER_MAX);
    std::uniform_int_distribution<> dayR(DAY_MIN, DAY_MAX);
    std::uniform_int_distribution<> priceR(PRICE_MIN, PRICE_MAX);

    stock_.reserve(12);

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
}