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

std::shared_ptr<Cargo> Store::findProduct(Cargo* cargo) {
    auto it = std::find_if(goodsList_.begin(), goodsList_.end(),
                           [cargo](const auto& product) { return *cargo == *product; });
    if (it != goodsList_.end()) {
        return *it;
    } else {
        return nullptr;
    }
}

Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    auto product = findProduct(cargo);
    if (product) {
        auto price = amount * cargo->getBasePrice();
        if (player->getAvailableSpace() < amount) {
            std::cout << "lack of space";
            return Response::lack_of_space;
        }
        if (cargo->getAmount() < amount) {
            std::cout << "lack of cargo";
            return Response::lack_of_cargo;
        }
        if (player->getMoney() < price) {
            std::cout << "lack of money";
            return Response::lack_of_money;
        }
        player->PurchaseCargo(product, price);
        if (product->getAmount() == amount) {
            removeProduct(product.get());
        } else {
            *product -= amount;
        }
        std::cout << "done!";
        return Response::done;

    } else {
        std::cout << "Product not found";
        return Response::lack_of_cargo;
    }
}

Response Store::sell(Cargo* cargo, size_t amount, Player* player){
    auto price = amount * cargo->getPrice();
    auto product = findProduct(cargo);
    if (product) {

        *product += amount;
        player->SellCargo(cargo, price);
        std::cout << "done!";
        return Response::done;
        

    } else {
        //auto product_ptr = std::make_shared<Cargo>(*cargo);
        //goodsList_.push_back(product_ptr);
        return Response::done;
    }
}

void Store::GenerateGoodsList() {
    goodsList_.push_back(std::make_shared<Fruit>("Bananas", 200, 40, 30));
    goodsList_.push_back(std::make_shared<Fruit>("Apples", 100, 20, 30));
    goodsList_.push_back(std::make_shared<Alcohol>("Wine", 33, 60, 20));
    goodsList_.push_back(std::make_shared<Item>("Swords", 1, 40, Rarity::common));
}

void Store::removeProduct(Cargo* cargo) {
    goodsList_.erase(std::find_if(std::begin(goodsList_), std::end(goodsList_),
                                  [cargo](const auto& el) {
                                      return *el == *cargo;
                                  }));
}

void Store::printGoodsList() const {
    int i {1};
    for (const auto& product : goodsList_) {
        std::cout << i++ << ". Name: " << product->getName()
                  << ", Amount: " << product->getAmount()
                  << ", Base price: " << product->getBasePrice()
                  << '\n';
    }
    std::cout << "\n";
}

/* std::ostream& operator<<(std::ostream& out, const Store& store) {
    for (const auto& product : store.goodsList_) {
        if (product) {
            out << product->getName() << " || "
                << product->getAmount() << " || "
                << product->getPrice() << '\n';
        }
    }
    return out;
} */
