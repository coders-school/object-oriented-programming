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

Store::Store() {
    generateDefaultCargo();
};

// std::shared_ptr<Cargo> Store::findCargoInStore(const std::string& name) {
//     auto find = std::find_if(stock_.begin(),
//                              stock_.end(),
//                              [&name](const auto& cargo) { return cargo->getName() == name; });
//     if (find != stock_.end()) {
//         return find->get()
//     }

//     return nullptr;
// }

// std::shared_ptr<Cargo> Store::findCargoInStore(const std::shared_ptr<Cargo> wantedCargo) {
//     for( const auto el : stock_) {
//         if(*el == *wantedCargo){
//             return el;
//         }
//     }
// }

// Response Store::buy(std::shared_ptr<Cargo>& cargo, size_t amount, Player* player) {
//     if (!cargo || !amount || !player) {
//         return Response::lack_of_cargo;
//     }

//     std::shared_ptr<Ship> playerShip = player->getShip();
//     if (!playerShip) {
//         return Response::lack_of_cargo;
//     }

//     auto soldPlayerCargo = playerShip->getCargosVector()[0];
//     for (const auto el : playerShip->getCargosVector()) {
//         auto loopCargo = el;

//         if (loopCargo == cargo) {
//             if (loopCargo->getAmount() < amount) {
//                 return Response::lack_of_space;
//             }
//         }
//         soldPlayerCargo = loopCargo;
//     }

//     if (!soldPlayerCargo) {
//         return Response::lack_of_cargo;
//     }

//     player->sell(cargo, amount);
//     unloadShip(cargo,amount);

//     return Response::done;

// }

Response Store::sell(std::shared_ptr<Cargo>& cargo, size_t amount, Player* player) {
    //lack of an amount of cargo in store

    std::cout << "nazwa ładunku: " << cargo->getName() << " ilosć ładunku: " << amount << " ile miejsc wolnych u zawodnika: " << player->getAvailableSpace() << '\n';
    if (!cargo || !amount) {
        std::cout << " lack of cargo !cargo || !amount\n";
        Response::lack_of_cargo;
    }

    //lack of space on player's ship
    if (!player) {
        std::cout << " I am here !player'\n";

        return Response::lack_of_space;
    }

    std::shared_ptr<Ship> playerShip = player->getShip();
    if (!playerShip) {
        std::cout << " I am here . NO player ship'\n";

        return Response::lack_of_space;
    }

    // Check if player can take cargo on ship
    bool playerHaveTheSameCargo = false;
    auto playerCargo = playerShip->getCargosVector();
    for (const auto& el : playerCargo) {
        if (el->getName() == cargo->getName()) {
            playerHaveTheSameCargo = true;
            break;
        }
    }
    if (!playerHaveTheSameCargo && !player->getAvailableSpace()) {
        std::cout << " I am here brak miejsca'\n";
        ;

        return Response::lack_of_space;
    }

    // Finding cargo in the store
    // auto StoredCargo = findCargoInStore(cargo);
    // std::cout << 

    // std::cout << "nazw stored Cargo: " << StoredCargo->get()->getAmount();
    // if (StoredCargo != stock_.end()) {
    //     std::cout << " I am here NIE ma cargo w store'\n" << StoredCargo->get()->getName() << '\n';

    //     return Response::lack_of_cargo;
    // }

    // // not enough cargo amount in the store

    // if (StoredCargo->get()->getAmount() < amount) {
    //     std::cout << " I am here'\n";

    //     return Response::lack_of_cargo;
    // }

    // // Too expenisive for player

    // if (player->getMoney() < amount * (StoredCargo->get()->getPrice())) {
    //     std::cout << " I am here'\n";

    //     return Response::lack_of_money;
    // }

    // Dopisać co sie stanie gdy dojedzie do sprzedaży.
    // Unload ze Statku. Load na statek.
    // Jak sie zmieni konto gracza.
    player->buy(cargo, amount);
    loadShip(cargo, amount);
    return Response::done;
    
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


void Store::loadShip(std::shared_ptr<Cargo>& cargo, size_t& amount) {
    if(!cargo){
        return;
    }
    bool flag = false;
    for (const auto& el : stock_) {
        if( el->getName() == cargo->getName())
        {
            el->setAmount(el->getAmount() - amount);
            flag = true;
            break;
        }
    }
    if(!flag) {
        std::cout << "dupa: \n";
    }
}

void Store::unloadShip(std::shared_ptr<Cargo>& cargo, size_t& amount) {
    if(!cargo){
        return;
    }
    for (const auto& el : stock_) {
        if( el->getName() == cargo->getName())
        {
            el->setAmount(el->getAmount()  + amount);
            std::cout << "dodało do store'\n";
            break;
        }
    }
}

void Store::nextDay() {
    for (auto cargo : Store::getCargoOfStore()) {
        if(cargo == nullptr) {
            break;
        } else {
            std::random_device rm;
            std::mt19937 gr(rm());
            int more_stuff_in_store = 1;
            int less_stuff_in_store = 0;
            int adding_taking_max = 10;
            int adding_taking_min = 1;
            std::uniform_int_distribution<> in_store_action(less_stuff_in_store, more_stuff_in_store);
            std::uniform_int_distribution<> to_add_or_take(adding_taking_min, adding_taking_max);
            if(in_store_action(gr)) {
                *cargo -= to_add_or_take(gr);
                if (cargo->getAmount() < 0) {
                    *cargo -= cargo->getAmount();
                }
                if (cargo->getAmount() > 500) {
                    *cargo -= cargo->getAmount();
                }
            } else {
                *cargo += to_add_or_take(gr);
            }
        }
    }
}
