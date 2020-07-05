#include "store.hpp"

#include <algorithm>
#include <numeric>
#include <iostream>

#include "fruit.hpp"
#include "item.hpp"
#include "alcohol.hpp"

Store::Store(size_t capacity, size_t avaiableFunds)
    : capacity_(capacity), avaiableFunds_(avaiableFunds) {}

Store::Store()
    : Store(DEFAULT_CAPACITY, DEFAULT_FUNDS) {}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> The buy method allows Player to purchase cargo in store
//-----------------------------------------------------------------------------------
Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    if (cargo) {
        if (getCargo(cargo->getName()) != nullptr) {
            size_t totalPrice =
                getCargo(cargo->getName())->getBasePrice() * amount;

            if (player->getMoney() < totalPrice)
                return Response::lack_of_money;

            if (getCargo(cargo->getName())->getAmount() < amount)
                return Response::lack_of_cargo;

            if (player->getAvailableSpace() <
                getCargo(cargo->getName())->getAmount())
                return Response::lack_of_space;

            setAvaiableFunds(getAvaiableFunds() + totalPrice);
            updateCargo(cargo, amount, updateMode::BUY);

            std::unique_ptr<Cargo> purchase = cargo->clone();
            purchase->setAmount(amount);
            player->purchaseCargo(std::move(purchase), totalPrice);

            return Response::done;
        }
    }
    return Response::invalid_cargo;
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> The sell method allows Player to sell cargo in store
//-----------------------------------------------------------------------------------
Store::Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    if (cargo) {
        if (getCargo(cargo->getName()) != nullptr) {
            size_t totalPrice =
                player->getCargo(cargo->getName())->getPrice() * amount;

            if (getAvaiableFunds() < totalPrice)
                return Response::lack_of_money;

            if (player->getCargo(cargo->getName())->getAmount() < amount)
                return Response::lack_of_cargo;

            if (getAvaiableSpace() <
                player->getCargo(cargo->getName())->getAmount())
                return Response::lack_of_space;

            setAvaiableFunds(getAvaiableFunds() - totalPrice);
            updateCargo(cargo, amount, updateMode::SELL);

            player->sellCargo(cargo, totalPrice);

            return Response::done;
        }
    }
    return Response::invalid_cargo;
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> This method allows to add cargo to the store / updated the cargo vec
//-----------------------------------------------------------------------------------
bool Store::addCargo(Cargo* cargo) {
    bool success = false;
    if (getAvaiableSpace() >= cargo->getAmount()) {
        auto ptrCargo = getCargo(cargo->getName());
        if (ptrCargo == nullptr) {
            cargo_.emplace_back(cargo->clone());
        } else {
            size_t tmpAmount = ptrCargo->getAmount() + cargo->getAmount();
            ptrCargo->setAmount(tmpAmount);
        }
        success = true;
    }
    return success;
}


/*public*/
//-----------------------------------------------------------------------------------
// <summary> Finds particular cargo in cargo vec using std::name for comparsion
//-----------------------------------------------------------------------------------
Cargo* Store::getCargo(const std::string& name) {
    return Common::getCargo(name, cargo_);
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> Checks the Store's avaiable space
//-----------------------------------------------------------------------------------
size_t Store::getAvaiableSpace() const {
    return Common::getAvailableSpace(capacity_, cargo_);
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> Prints out the cargo vector content
//-----------------------------------------------------------------------------------
void Store::printCargo() {
    Common::printCargo(cargo_);
}

/*private*/
//-----------------------------------------------------------------------------------
// <summary> This method is used for updating the cargo amount in cargo vec while 
//           player is buying/selling goods
//-----------------------------------------------------------------------------------
void Store::updateCargo(Cargo* cargo,
                        size_t amount,
                        updateMode mode) {
    if (mode == BUY) {
        if (getCargo(cargo->getName())->getAmount() == amount) {
            auto it = std::find_if(cargo_.begin(), cargo_.end(), [=](std::unique_ptr<Cargo>& el) {
                return el->getName() == cargo->getName();
            });
            cargo_.erase(it);

        } else {
            size_t tmpAmount = getCargo(cargo->getName())->getAmount() - amount;
            getCargo(cargo->getName())->setAmount(tmpAmount);
        }

    } else if (mode == SELL) {
        size_t tmpAmount = getCargo(cargo->getName())->getAmount() + amount;
        getCargo(cargo->getName())->setAmount(tmpAmount);
    }
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> Prints the relevant Response message
//-----------------------------------------------------------------------------------
void Store::printResponseMessage(Response& response) {
    if (response == Response::invalid_cargo)
        std::cout << "Response Message: Invalid cargo.\n";
    else if (response == Response::done)
        std::cout << "Response Message: Transaction completed.\n";
    else if (response == Response::lack_of_cargo)
        std::cout << "Response Message: There might be not enough cargo.\n";
    else if (response == Response::lack_of_money)
        std::cout << "Response Message: Not enought money.\n";
    else if (response == Response::lack_of_space)
        std::cout << "Response Message: Not enouhg space.\n";
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    for (const auto& cargo : store.cargoVec) {
        out << "Product: " << cargo->getName() << '\n';
        out << "Amount: " << cargo->getAmount() << '\n';
        out << "Base price: " << cargo->getBasePrice() << '\n';

        if (typeid(*cargo) == typeid(Fruit)) {
            Fruit* fruit = static_cast<Fruit*>(cargo);
            out << "Current price: " << fruit->getPrice() << '\n';
            out << "Expires in: " << fruit->getTimeToSpoilLeft() << '\n';
        }
        if (typeid(*cargo) == typeid(Item)) {
            Item* item = static_cast<Item*>(cargo);
            out << "Current price: " << item->getPrice() << '\n';
            switch (item->getRarity()) {
            case (Item::Rarity::common):
                out << "Rarity: common\n";
                break;
            case (Item::Rarity::epic):
                out << "Rarity: epic\n";
                break;
            case (Item::Rarity::legendary):
                out << "Rarity: legendary\n";
                break;
            case (Item::Rarity::rare):
                out << "Rarity: rare\n";
                break;
            }
        }
        if (typeid(*cargo) == typeid(Alcohol)) {
            Alcohol* alcohol = static_cast<Alcohol*>(cargo);
            out << "Current price: " << alcohol->getPrice() << '\n';
            out << "Expires in: " << alcohol->getTimeToSpoilLeft() << '\n';
        }
    }
    return out;
}
