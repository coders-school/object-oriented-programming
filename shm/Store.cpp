#include "Store.hpp"

#include <algorithm>

// Temporary added - operator << test
//begin
#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"
//end

Store::Response Store::Buy(Cargo* cargo, size_t amount, Player* player) {
    if (amount > cargo->getAmount()) {
        return Response::lack_of_cargo;
    }
    if (amount > player->getAvailableSpace()) {
        return Response::lack_of_space;
    }
    const size_t price = amount * cargo->getBasePrice();

    if (price > player->getMoney()) {
        return Response::lack_of_money;
    }

    return Response::done;
}

Store::Response Store::Sell(Cargo* cargo, size_t amount, Player* player) {
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

// Temporary added - operator << test
//begin
void Store::CreateTestCargo() {
    _cargo.reserve(3);
    _cargo.push_back(std::make_shared<Alcohol>("whiskey", 10, 20, 90));
    _cargo.push_back(std::make_shared<Fruit>("malina", 30, 40, 50, 60));
    _cargo.push_back(std::make_shared<Item>("sword", 70, 80, Item::Rarity::legendary));
}
//end
