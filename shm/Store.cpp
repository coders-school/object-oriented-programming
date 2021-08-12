#include "Store.hpp"
#include <algorithm>
#include <iostream>
#include "Alcohol.hpp"
#include "Cargo.hpp"
#include "Fruit.hpp"
#include "Item.hpp"
#include "Player.hpp"

Store::Store() {
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

Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    std::cout<< cargo->getAmount()<<"\n";
        if (cargo) {
        auto price = amount * cargo->getBasePrice();
        if (player->getAvailableSpace() < amount) {
            //std::cout << "lack of space";
            return Response::lack_of_space;
        }
        if (cargo->getAmount() < amount) {
            //std::cout << "lack of cargo";
            return Response::lack_of_cargo;
        }
        if (player->getMoney() < price) {
            //std::cout << "lack of money";
            return Response::lack_of_money;
        }

        Cargo product = (*cargo);
        auto product_ptr = std::make_unique<Cargo>(product); 

        player->PurchaseCargo(product_ptr, price);
        if (cargo->getAmount() == amount) {
            removeProduct(cargo);
        } else {
            *cargo -= amount;
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
        player->SellCargo(product, price);
        return Response::done;
    } else {
        goodsList_.push_back(std::move(product));
        return Response::done;
    }
}

void Store::GenerateGoodsList() {
    goodsList_.push_back(std::make_unique<Fruit>("Bananas", 200, 40, 30));
    goodsList_.push_back(std::make_unique<Fruit>("Apples", 100, 20, 30));
    goodsList_.push_back(std::make_unique<Alcohol>("Wine", 33, 60, 20));
    //goodsList_.push_back(std::make_shared<Item>("Swords", 1, 40, Rarity::common));
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
