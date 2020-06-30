#include "Store.hpp"

#include <algorithm>

#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"

Cargo* Store::findCargo(Cargo* cargo) const {
    auto matchCargo = std::find_if(std::begin(_cargo), std::end(_cargo),
                                   [cargo](const auto& el) {
                                       return *el == *cargo;
                                   });
    if (matchCargo != std::end(_cargo)) {
        return matchCargo->get();
    }
    return nullptr;
}

Store::Response Store::Buy(Cargo* cargo, size_t amount, Player* player) {
    if ((amount + cargo->getAmount()) > cargo->getMaxAmount()) {
        std::cout << "cargo, lack of space\n";
        return Response::lack_of_space;
    }
    if (amount > player->getAvailableSpace()) {
        std::cout << "player, lack of space\n";
        return Response::lack_of_space;
    }
    const size_t price = amount * cargo->getPrice();
    if (price > player->getMoney()) {
        std::cout << "player, lack of money\n";
        return Response::lack_of_money;
    }
    if (auto* matchCargo = findCargo(cargo)) {
        if (amount > matchCargo->getAmount()) {
            std::cout << "Store, lack of cargo\n";
            return Response::lack_of_cargo;
        } else {
            *matchCargo -= amount;
        }
    } else {
        std::cout << "Store, lack of cargo\n";
        return Response::lack_of_cargo;
    }
    if (cargo->getAmount() == 0) {
        _cargo.erase(std::find_if(std::begin(_cargo), std::end(_cargo),
                                  [cargo](const auto& el) {
                                      return *el == *cargo;
                                  }));
    }
    *cargo += amount;
    return Response::done;
}

Store::Response Store::Sell(Cargo* cargo, size_t amount, Player* player) {
    const size_t price = amount * cargo->getPrice();
    if (amount > cargo->getAmount()) {
        std::cout << "cargo, lack of cargo\n";
        return Response::lack_of_cargo;
    }
    if (auto* matchCargo = findCargo(cargo)) {
        if (matchCargo->getAmount() + amount > matchCargo->getMaxAmount()) {
            std::cout << "cargo, lack of space\n";
            return Response::lack_of_space;
        } else {
            *matchCargo += amount;
        }
    } else {
        if (auto* alcoholType = dynamic_cast<Alcohol*>(cargo)) {
            _cargo.push_back(std::make_shared<Alcohol>(alcoholType->getName(), amount, alcoholType->getBasePrice(), alcoholType->getPower()));
        } else if (auto* fruitType = dynamic_cast<Fruit*>(cargo)) {
            _cargo.push_back(std::make_shared<Fruit>(fruitType->getName(), amount, fruitType->getBasePrice(), fruitType->getExpiryDate(), fruitType->getTimeToSpoil()));
        } else if (auto* itemType = dynamic_cast<Item*>(cargo)) {
            _cargo.push_back(std::make_shared<Item>(itemType->getName(), amount, itemType->getBasePrice(), itemType->getRarity()));
        }
    }
    *cargo -= amount;
    return Response::done;
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    out << "Cargo available in Store:\n";
    std::for_each(begin(store._cargo), end(store._cargo),
                  [&out, &store, i{0}](const auto& cargo) mutable {
                      out << ++i << ". ";
                      cargo->showCargo(out);
                  });
    return out;
}
