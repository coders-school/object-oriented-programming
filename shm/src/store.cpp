#include "store.hpp"

#include <algorithm>
#include <numeric>

Store::Store(size_t capacity, size_t avaiableFunds)
    : capacity_(capacity), avaiableFunds_(avaiableFunds) {}

Store::Store()
    : Store(DEFAULT_CAPACITY, DEFAULT_FUNDS) {}

Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    if (cargo) {
        if (this->getCargo(cargo->getName()) != nullptr) {
            size_t totalPrice =
                this->getCargo(cargo->getName())->getBasePrice() * amount;

            if (player->getMoney() < totalPrice)
                return Response::lack_of_money;

            if (this->getCargo(cargo->getName())->getAmount() < amount)
                return Response::lack_of_cargo;

            if (player->getAvailableSpace() <
                this->getCargo(cargo->getName())->getAmount())
                return Response::lack_of_space;

            player->setMoney(player->getMoney() - totalPrice);
            this->setAvaiableFunds(this->getAvaiableFunds() + totalPrice);
            this->updateCargo(cargo, amount, updateMode::BUY, player);

            return Response::done;
        }
    }
    return Response::invalid_cargo_name;
}

Store::Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    if (cargo) {
        if (this->getCargo(cargo->getName()) != nullptr) {
            size_t totalPrice =
                player->getCargo(cargo->getName())->getBasePrice() * amount;

            if (this->getAvaiableFunds() < totalPrice)
                return Response::lack_of_money;

            if (player->getCargo(cargo->getName())->getAmount() < amount)
                return Response::lack_of_cargo;

            if (this->getAvaiableSpace() <
                player->getCargo(cargo->getName())->getAmount())
                return Response::lack_of_space;

            player->setMoney(player->getMoney() + totalPrice);
            this->setAvaiableFunds(this->getAvaiableFunds() - totalPrice);
            this->updateCargo(cargo, amount, updateMode::SELL, player);
            return Response::done;
        }
    }
    return Response::invalid_cargo_name;
}

Cargo* Store::getCargo(const std::string& name) {
    return Common::getCargo(name, cargoVec);
}

size_t Store::getAvaiableSpace() const {
    return Common::getAvailableSpace(capacity_, cargoVec);
}

void Store::printCargo() {
    Common::printCargo(cargoVec);
}

void Store::updateCargo(Cargo* cargo,
                        size_t amount,
                        updateMode mode,
                        Player* player) {
    if (mode == BUY) {
        if (player->getCargo(cargo->getName()) != nullptr) {
            size_t tmpAmount = player->getCargo(cargo->getName())->getAmount() + amount;
            player->getCargo(cargo->getName())->setAmount(tmpAmount);
        } else {
            player->cloneCargo(cargo);
            player->getCargo(cargo->getName())->setAmount(amount);
        }

        if (this->getCargo(cargo->getName())->getAmount() == amount) {
            auto it = std::find_if(cargoVec.begin(), cargoVec.end(), [=](Cargo* el) {
                return el->getName() == cargo->getName();
            });
            cargoVec.erase(it);

        } else {
            size_t tmpAmount = this->getCargo(cargo->getName())->getAmount() - amount;
            this->getCargo(cargo->getName())->setAmount(tmpAmount);
        }

    } else if (mode == SELL) {
        if (player->getCargo(cargo->getName())->getAmount() == amount) {
            player->removeCargo(player->getCargo(cargo->getName()));

        } else {
            size_t tmpAmount = player->getCargo(cargo->getName())->getAmount() - amount;
            player->getCargo(cargo->getName())->setAmount(tmpAmount);
        }

        size_t tmpAmount = this->getCargo(cargo->getName())->getAmount() + amount;
        this->getCargo(cargo->getName())->setAmount(tmpAmount);
    }
}

void Store::printResponseMessage(Response& response) {
    if (response == Response::invalid_cargo_name)
        std::cout << "Response Message: Invald cargo name.\n";
    else if (response == Response::done)
        std::cout << "Response Message: Transaction completed.\n";
    else if (response == Response::lack_of_cargo)
        std::cout << "Response Message: There might be not enough cargo.\n";
    else if (response == Response::lack_of_money)
        std::cout << "Response Message: Not enought money.\n";
    else if (response == Response::lack_of_space)
        std::cout << "Response Message: Not enouhg space.\n";
}
