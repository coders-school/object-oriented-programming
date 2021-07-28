#include "Store.hpp"
#include <iostream>
#include "Time.hpp"

Response Store::buy(const Cargo* const cargo, size_t amount, Player* player) {
    if (!cargo or !player or !amount) {
        return Response::lack_of_cargo;
    }

    Ship* playerShip = player->getShip();
    if (!playerShip) {
        return Response::lack_of_cargo;
    }

    Cargo* soldPlayerCargo = nullptr;
    for (const auto& el : playerShip->getCargoVec()) {
        Cargo* currentCargo = el.get();

        if (*currentCargo == *cargo) {
            if (currentCargo->getAmount() < amount) {
                return Response::lack_of_cargo;
            }
            soldPlayerCargo = currentCargo;
        }
    }

    if (!soldPlayerCargo) {
        return Response::lack_of_cargo;
    }
    //Store have unlimited space and money

    //player sell all
    if (soldPlayerCargo->getAmount() == amount) {
        auto ownedCargo = soldPlayerCargo->split(amount);
        playerShip->unload(soldPlayerCargo);
        auto moneyToPay = ownedCargo->getPrice() * ownedCargo->getAmount();
        player->income(moneyToPay);

        load(std::move(ownedCargo));
        return Response::done;
    }

    //player sell less than all
    auto moneyToPay = soldPlayerCargo->getPrice() * amount;
    auto buyedCargoPart = soldPlayerCargo->split(amount);

    if (!buyedCargoPart) {
        return Response::lack_of_cargo;
    }
    player->pay(moneyToPay);

    load(std::move(buyedCargoPart));
    return Response::done;
}

Response Store::sell(const Cargo* const cargo, size_t amount, Player* player) {
    if (!cargo or !amount) {
        return Response::lack_of_cargo;
    }
    if (!player) {
        return Response::lack_of_space;
    }

    Ship* playerShip = player->getShip();
    if (!playerShip) {
        return Response::lack_of_space;
    }

    //check if player can take cargo on ship
    bool playerHaveComperableCargo = false;
    const auto& playerCargo = playerShip->getCargoVec();  // player/ship should have findCargo
    for (const auto& el : playerCargo) {
        if (cargo == el.get()) {
            playerHaveComperableCargo = true;
            break;
        }
    }
    if (!playerHaveComperableCargo and !player->getAvailableSpace()) {
        return Response::lack_of_space;
    }

    auto storeCargo = findCargoInStore(cargo);

    if (!storeCargo) {  //can't find cargo in store
        return Response::lack_of_cargo;
    }

    if (storeCargo->getAmount() < amount) {  //to much cargo needed
        return Response::lack_of_cargo;
    }

    auto moneyToPay = amount * storeCargo->getPrice();
    if (player->getMoney() < moneyToPay) {  //to expensive for player
        return Response::lack_of_money;
    }

    if (amount == storeCargo->getAmount()) {  //we sall all cargo - remove it from
        try {
            auto soldCargo = storeCargo->split(amount);
            unload(storeCargo);
            playerShip->load(std::move(soldCargo));
        } catch (std::logic_error& err) {
            //rest of cargo disapear in store?
        }
        return Response::done;
    }

    auto soldCargo = storeCargo->split(amount);
    playerShip->load(std::move(soldCargo));
    return Response::done;
}

Cargo* Store::findCargoInStore(const Cargo* const exampleCargo) const {
    if (!exampleCargo) {
        return nullptr;
    }

    for (const auto& el : cargoVec_) {
        Cargo* targetCargo = el.get();
        if (targetCargo) {
            /*if (targetCargo == exampleCargo) {  //we dont want to compare same Cargo pointers
                return nullptr;
            }*/

            if (*targetCargo == *exampleCargo) {  //depend this means equality or comperable
                return targetCargo;
            }
        }
    }
    return nullptr;
}

size_t Store::getCargoNum() const {
    return cargoVec_.size();
}

void Store::nextDay() {
    changeAssortment();
    std::cout << "Store change asortment.";
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    for (const auto& el : store.cargoVec_) {
        if (el) {
            out << el->getName() << " || "
                << el->getAmount() << " || "
                << el->getPrice() << '\n';
        }
    }
    return out;
}
