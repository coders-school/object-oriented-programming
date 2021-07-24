#include "cargo.hpp"
#include "player.hpp"
#include "Time.hpp"
#include "Store.hpp"

//enum class Response {done, lack_of_money, lack_of_cargo, lack_of_space};


Store::Store(int money, size_t availableSpace, Time* time) 
    : Storable(money, availableSpace, time)
    {
        storeCargo.push_back(std::make_shared<Fruit>(10, "Banana", 10, 100, 0));// Fruit(size_t amount, const std::string& name, size_t base_price, size_t expiry_date, size_t time_elapsed)
        storeCargo.push_back(std::make_shared<Fruit>(10, "Apple", 10, 100, 0));
        storeCargo.push_back(std::make_shared<Alcohol>(10, "Wodka", 30, 70));// Alcohol(size_t amount, const std::string& name, size_t base_price, size_t percentage);
        storeCargo.push_back(std::make_shared<Item>(1, "Hook", 50, Item::Rarity::common));//Item(size_t amount, const std::string &name, size_t base_price, Rarity rarity);

    }
 Store::~Store(){}

Cargo* Store::findMatchCargo(Cargo* cargo) {
    for (auto& el : storeCargo) {
        if(*el == *cargo) {
            return el.get();
        }
    }
    return nullptr;
}

Response Store::buy(Cargo* cargo, size_t amount, Player *player)//Buying cargo from store to player
{
    if(findMatchCargo(cargo))
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


Response Store::sell(Cargo* cargo, size_t amount, Player *player) // Selling cargo from Player to Store
{
    if(findMatchCargo(cargo))
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

        player->unload(cargo, amount);
        player->EarnMoney(price);

        return Response::done;
    }
    else
    {
        std::cout << "ni ma cargo" << '\n';
        return Response::lack_of_cargo;
    }
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
    for (auto el : storeCargo) {
        //el.get()->reduceAmount();
    }
}

void Store::printStoreCargo(){
    for(auto el : storeCargo) {
        std::cout << '\n';
        el -> printCargo();
    }
}

