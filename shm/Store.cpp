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

    Cargo* playerCargoToSell = nullptr;
    for (const auto& playerCargo : playerShip->getCargoVec()) {
        playerCargoToSell = playerCargo.get();

        if(!playerCargoToSell){
            continue;
        }

        if (*playerCargoToSell == *cargo) {
            if (playerCargoToSell->getAmount() < amount) {
                return Response::lack_of_cargo;
            }
            break;
        }
    }

    if (!playerCargoToSell) {
        return Response::lack_of_cargo;
    }
    //Store have unlimited space and money

    //player sell all
    if (playerCargoToSell->getAmount() == amount) {
        auto takenCargo = playerCargoToSell->split(amount);
        playerShip->unload(playerCargoToSell);
        auto moneyToPay = takenCargo->getPrice() * takenCargo->getAmount();
        player->income(moneyToPay);
        load(std::move(takenCargo));
        return Response::done;
    }

    //player sell less than all
    auto takenCargoPart = playerCargoToSell->split(amount);
    auto moneyToPay = takenCargoPart->getPrice() * takenCargoPart->getAmount();

    if (!takenCargoPart) {
        return Response::lack_of_cargo;
    }
    player->income(moneyToPay);
    load(std::move(takenCargoPart));
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
    for (const auto& playerCargo : playerShip->getCargoVec()) {
        if (cargo == playerCargo.get()) {
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

    if (amount == storeCargo->getAmount()) {
        try {
            auto soldCargo = storeCargo->split(amount);
            unload(storeCargo);
            playerShip->load(std::move(soldCargo));
            player->pay(moneyToPay);
        } catch (std::logic_error& err) {
            //rest of cargo disapear in store?
        }
        return Response::done;
    }

    auto soldCargoPart = storeCargo->split(amount);
    playerShip->load(std::move(soldCargoPart));
    player->pay(moneyToPay);
    return Response::done;
}

Cargo* Store::findCargoInStore(const Cargo* const exampleCargo) const {
    if (!exampleCargo) {
        return nullptr;
    }

    for (const auto& el : cargoVec_) {
        Cargo* targetCargo = el.get();
        if (targetCargo) {
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
    for (const auto& cargo : store.cargoVec_) {
        if (cargo) {
            out << cargo->getName() << " || "
                << cargo->getAmount() << " || "
                << cargo->getPrice() << '\n';
        }
    }
    return out;
}
