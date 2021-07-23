#include "Store.hpp"
#include "player.hpp"
#include "cargo.hpp"

//enum class Response {done, lack_of_money, lack_of_cargo, lack_of_space};


Store::Store(int money, size_t availableSpace) : Storable(money, availableSpace) 
    {
        cargo_.push_back(std::make_shared<Fruit>(10, "Banana", 10, 100, 0));// Fruit(size_t amount, const std::string& name, size_t base_price, size_t expiry_date, size_t time_elapsed)
        cargo_.push_back(std::make_shared<Fruit>(10, "Apple", 10, 100, 0));
        cargo_.push_back(std::make_shared<Alcohol>(10, "Wodka", 30, 70));// Alcohol(size_t amount, const std::string& name, size_t base_price, size_t percentage);
        cargo_.push_back(std::make_shared<Item>(1, "Hook", 50, Item::Rarity::common));//Item(size_t amount, const std::string &name, size_t base_price, Rarity rarity);

    }
 Store::~Store(){}

Cargo* Store::findMatchCargo(Cargo* cargo) {
    for (auto& el : cargo_) {
        if(*el == *cargo) {
            return el.get();
        }
    }
    return nullptr;
}

Response Store::buy(std::shared_ptr<Cargo> cargo, size_t amount, Player *player)//Buying cargo from store to player
{
    if(findMatchCargo(cargo.get()))
    {
        auto price = amount * cargo->getBasePrice();

        std::cout << "There is cargo" << '\n';

        if (player->getAvailableSpace() < amount)
        {
            std::cout << "getAvailbleSpace" << '\n';
            return Response::lack_of_space;
        }
        if  (cargo->getAmount() < amount)
        {
            std::cout << "getAmount" << '\n';
            return Response::lack_of_cargo;
        }
        if  (player->getMoney() < price)
        {
            std::cout << "getMoney" << '\n';
            return Response::lack_of_money;
        }

        player->SpendMoney(price);
        player->load(cargo, amount);


        return Response::done;
    }
    else
    {
        std::cout << "there isn`t cargo" << '\n';
        return Response::lack_of_cargo;
    }
    
}


Response Store::sell(std::shared_ptr<Cargo> cargo, size_t amount, Player *player) // Selling cargo from Player to Store
{
    if(findMatchCargo(cargo.get()))
    {
        std::cout << "There is cargo" << '\n';
        auto price = amount * cargo->getBasePrice();

        if (player->getAvailableSpace() < amount)
        {
            std::cout << "getAvailbleSpace" << '\n';
            return Response::lack_of_space;
        }
        if  (cargo->getAmount() < amount)
        {
            std::cout << "getAmount" << '\n';
            return Response::lack_of_cargo;
        }
        if  (player->getMoney() < amount * cargo->getBasePrice())
        {
            std::cout << "getMoney" << '\n';
            return Response::lack_of_money;
        }

        player->unload(cargo);
        player->EarnMoney(price);

        return Response::done;
    }
    else
    {
        std::cout << "ni ma cargo" << '\n';
        return Response::lack_of_cargo;
    }
    //TO DO BUY - add cargo to store, remove cargo from player
    
    
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

void Store::printStoreCargo(){
    for(auto el : cargo_) {
        std::cout << '\n';
        el -> printCargo();
    }
}