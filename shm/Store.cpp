#include "Store.hpp"
#include "player.hpp"
#include "cargo.hpp"

//enum class Response {done, lack_of_money, lack_of_cargo, lack_of_space};
Store::Store(int money, size_t availableSpace) : Storable(money, availableSpace) {}
Store::~Store(){}

Cargo* Store::findMatchCargo(Cargo* cargo) {
    for (auto& el : cargo_) {
        if(*el == *cargo) {
            return el.get();
        }
    }
    return nullptr;
}



Response Store::buy(Cargo *cargo, size_t amount, Player *player)//Buying cargo from store to player
{
    if (player->getAvailableSpace() < amount)
    {
        return Response::lack_of_space;
    }
    if (cargo->getAmount() < amount)
    {
        return Response::lack_of_cargo;
    }
    if (player->getMoney() < amount * cargo->getBasePrice())
    {
        return Response::lack_of_money;
    }
    //player->load(cargo);
    player->getMoney() - amount * cargo->getBasePrice();
    return Response::done;
}


Response Store::sell(Cargo *cargo, size_t amount, Player *player) // Selling cargo from Player to Store
{
    // if (player->getAvailableSpace() < amount)
    // {
    //     return Response::lack_of_space;
    // }
    if (cargo->getAmount() < amount)
    {
        return Response::lack_of_cargo;
    }
    // if (player->getMoney() < amount * cargo->getBasePrice())
    // {
    //     return Response::lack_of_money;
    // }
    //TO DO BUY - add cargo to store, remove cargo from player
    
    if(Cargo * ptr = findMatchCargo(cargo)) {
        *ptr += amount;
    }
    //else {
        
        //cargo_.push_back(static_cast<std::shared_ptr<Cargo>> (cargo));    
       // cargo_.push_back(std::make_shared<Cargo>(cargo -> getName(), amount, cargo->getBasePrice())); 
   // }
    

    return Response::done;
}

std::shared_ptr<Cargo> Store::getCargo(size_t index) const
{
    return nullptr;
}

void Store::nextDay(){
    for (auto el : cargo_) {
        el.get()->reduceAmount();
    }
}

