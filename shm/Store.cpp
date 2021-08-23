#include "Store.hpp"
#include <algorithm>
#include <iostream>
#include "Alcohol.hpp"
#include "Cargo.hpp"
#include "Fruit.hpp"
#include "Item.hpp"
#include "Player.hpp"

Store::Store(Time* time) : time_(time) {
    GenerateGoodsList();
}

Cargo* Store::findProduct(Cargo* cargo) {
    auto it = std::find_if(goodsList_.begin(), goodsList_.end(),
                           [cargo](const auto& product) { return *cargo == *product; });
    if (it != goodsList_.end()) {
        return (*it).get();
    } else {
        return nullptr;
    }
}

Response Store::buy(Cargo* product, size_t amount, Player* player) {
    if (product) {
        auto price = amount * product->getBasePrice();
        if (player->getAvailableSpace() < amount) {
            return Response::lack_of_space;
        }
        if (product->getAmount() < amount) {
            return Response::lack_of_cargo;
        }
        if (player->getMoney() < price) {
            return Response::lack_of_money;
        }

        auto cargo = product->clone(amount);
        time_->AddObserver(cargo.get());
        player->purchaseCargo(std::move(cargo), price);
        
        if (product->getAmount() == amount) {
            removeProduct(product);
        } else {
            *product -= amount;
        }
        return Response::done;
    } else {
        std::cout << "Product not found";
        return Response::lack_of_cargo;
    }
}

Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    auto price = amount * cargo->getPrice();
    auto product = findProduct(cargo);
    if (product) {
        *product += amount;
        time_->RemoveObserver(cargo);
        player->sellCargo(cargo, price);
        return Response::done;
    } else {
        auto product = cargo->clone(amount);
        goodsList_.push_back(std::move(product));
        return Response::done;
    }
}

void Store::GenerateGoodsList() {
    goodsList_.push_back(std::make_unique<Fruit>("Bananas", 200, 40, 30));
    goodsList_.push_back(std::make_unique<Fruit>("Apples", 100, 20, 30));
    goodsList_.push_back(std::make_unique<Alcohol>("Wine", 33, 60, 20));
}

void Store::removeProduct(Cargo* cargo) {
    goodsList_.erase(std::find_if(std::begin(goodsList_), std::end(goodsList_),
                                  [cargo](const auto& product) {
                                      return *product == *cargo;
                                  }));
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    std::cout << "Goods in the local store:"
              << "\n"
              << "\n";
    int i{1};
    for (const auto& product : store.goodsList_) {
        if (product) {
            out << i++ << ". Name: " << product->getName()
                << ", Amount: " << product->getAmount()
                << ", Base price: " << product->getBasePrice()
                << '\n';
        }
    }
    std::cout << "\n";
    return out;
}

void Store::nextDay(){
    //regenerate goods
}
