#include <algorithm>

#include "store.hpp"

Store::Store(Time* gameTime):
    timeTracker_(gameTime) {}

Response Store::buy(Cargo* cargo, size_t amount, Player* player){
    if(cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    }
    if(player->getAvailableSpace() < amount){
        return Response::lack_of_space;
    }
    if(player->getMoney() < (cargo->getBasePrice() * amount) ) {
        return Response::lack_of_money;
    }
    *cargo -= amount;
    player->takeMoney(cargo->getBasePrice() * amount);
    Item cargoBought(cargo->getName(), amount, cargo->getBasePrice(),static_cast<int>(Rarity::common),timeTracker_);
    cargoSold_.push_back(std::move(cargoBought));
    player->giveCargo(&cargoSold_.back());
    return Response::done;
}

Response Store::sell(Cargo* cargo, size_t amount, Player* player){
    if(cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    }
    *cargo -= amount;
    if(cargo->getAmount() == 0){
        player->removeCargo(cargo);
    }
    player->giveMoney(cargo->getBasePrice() * amount);
    return Response::done;
}

std::ostream& operator<<(std::ostream& print, const Store& store) {
    print << "What you want to buy or sell: \n";
    std::for_each(store.cargoToSell_.begin(), store.cargoToSell_.end(),
        [&print, &store, i{0}] (const auto& cargo) mutable {
            print << ++i << " || ";
            
                                
        });
        return print;
}
