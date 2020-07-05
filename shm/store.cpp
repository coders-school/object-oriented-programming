#include <algorithm>
#include <random>

#include "store.hpp"

Store::Store(Time* gameTime):
    timeTracker_(gameTime) {}

Response Store::buys(Cargo* cargo, size_t amount, Player* player,size_t totalPrice){
    if(cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    }
    if(player->getAvailableSpace() < amount){
        return Response::lack_of_space;
    }
    if(player->getMoney() < totalPrice ) {
        return Response::lack_of_money;
    }
    *cargo -= amount;
    player->takeMoney(totalPrice);
    return Response::done;
}

Response Store::buy(Alcohol* alco, size_t amount, Player* player){
    size_t totalPrice = alco->getPrice() * amount;
    Response result = Store::buys(alco,amount,player,totalPrice);
    if(result != Response::done){
        return result;
    }
    Alcohol alcoBought(alco->getName(), amount, alco->getBasePrice(),
                     alco->getPower(),timeTracker_);
    alcosSold_.push_back(std::move(alcoBought));
    player->giveCargo(&alcosSold_.back());
    return result;
}

Response Store::buy(Fruit* fruit, size_t amount, Player* player){
    size_t totalPrice = fruit->getPrice() * amount;
    Response result = Store::buys(fruit,amount,player,totalPrice);
    if(result != Response::done){
        return result;
    }
    Fruit fruitBought(fruit->getName(), amount, fruit->getBasePrice(),
                     fruit->getExpiryDate(),fruit->getTimeElapsed(),timeTracker_);
    fruitsSold_.push_back(std::move(fruitBought));
    player->giveCargo(&fruitsSold_.back());
    return result;
}


Response Store::buy(Item* item, size_t amount, Player* player){
    size_t totalPrice = item->getPrice() * amount;
    Response result = Store::buys(item,amount,player,totalPrice);
    if(result != Response::done){
        return result;
    }
    Item itemBought(item->getName(), amount, item->getBasePrice(),
                     static_cast<int>(item->getRarity()),timeTracker_);
    itemsSold_.push_back(std::move(itemBought));
    player->giveCargo(&itemsSold_.back());
    return result;
}

Response Store::sells(Cargo* item, size_t amount, Player* player,size_t totalPrice){
    if(item->getAmount() < amount) {
        return Response::lack_of_cargo;
    }
    *item -= amount;
    player->giveMoney(item->getPrice() * amount);
    return Response::done;
}

Response Store::sell(Alcohol* alco, size_t amount, Player* player){
    size_t totalPrice = alco->getPrice() * amount;
    Response result = Store::sells(alco,amount,player,totalPrice);
    if(result != Response::done){
        return result;
    }
    if(alco->getAmount() == 0){
        player->removeAlco(alco);
    }
    return Response::done;
}

Response Store::sell(Fruit* fruit, size_t amount, Player* player){
    size_t totalPrice = fruit->getPrice() * amount;
    Response result = Store::sells(fruit,amount,player,totalPrice);
    if(result != Response::done){
        return result;
    }
    if(fruit->getAmount() == 0){
        player->removeFruit(fruit);
    }
    return Response::done;
}

Response Store::sell(Item* item, size_t amount, Player* player){
    size_t totalPrice = item->getPrice() * amount;
    Response result = Store::sells(item,amount,player,totalPrice);
    if(result != Response::done){
        return result;
    }
    if(item->getAmount() == 0){
        player->removeItem(item);
    }
    return Response::done;
}

void Store::generateGoods(){
    cargoToSell_.clear();
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<size_t> itemNumber(1,6);
    std::uniform_int_distribution<size_t> itemQuantity(1,20);
    for(size_t i = 0; i < numerOfItems;i++){
        switch(itemNumber(generator)){
            case 1: 
                cargoToSell_.emplace_back(Item("Sword", itemQuantity(generator), 150 ,static_cast<int>(Rarity::common),timeTracker_));
                break;
            case 2: 
                cargoToSell_.emplace_back(Item("Hat",  itemQuantity(generator), 200 ,static_cast<int>(Rarity::common),timeTracker_));
                break;
            case 3: 
                cargoToSell_.emplace_back(Item("Boots", itemQuantity(generator), 100 ,static_cast<int>(Rarity::common),timeTracker_));
                break;
            case 4: 
                cargoToSell_.emplace_back(Item("Pistol", itemQuantity(generator),500 ,static_cast<int>(Rarity::common),timeTracker_));
                break;
            case 5: 
                cargoToSell_.emplace_back(Item("Cannon", itemQuantity(generator), 2000 ,static_cast<int>(Rarity::common),timeTracker_));
                break;
            case 6: 
                cargoToSell_.emplace_back(Item("Flag", itemQuantity(generator), 65 ,static_cast<int>(Rarity::common),timeTracker_));
                break;
                break;
            default: 
                std::cerr << "RNG error!\n";
                break;
        }
    }
}

std::ostream& operator<<(std::ostream& print, const Store& store) {
    print << "What you want to buy or sell: \n";
    std::for_each(store.cargoToSell_.begin(), store.cargoToSell_.end(),
        [&print, &store, i{0}] (const auto& cargo) mutable {
            print << ++i << " " << cargo.getName() << " || " ;
            
                                
        });
        return print;
}
