
#include <iostream>
#include <memory>
#include "alcohol.hpp"
#include "cargo.hpp"
#include "coordinates.hpp"
#include "dryfruit.hpp"
#include "fruit.hpp"
#include "island.hpp"
#include "item.hpp"
#include "Map.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "Storable.hpp"
#include "Store.hpp"
#include "Time.hpp"

int main()
{
    Time* ptr_time = new Time;
    Store store(100, 500, ptr_time);

    std::cout << "Test Cargo" << '\n';

    Fruit bananas("banany", 15, 150, 20, 0, ptr_time);
    Item kryptonite("krypton", 20, 200, Rarity::common, ptr_time); 
    Item onion("cebula", 250, 1, Rarity::rare, ptr_time); 


    std::cout << (onion == bananas) << " " << (bananas == kryptonite) << " " << (onion == kryptonite) << "\n";
    std::cout << bananas.getAmount() << " " << bananas.getBasePrice() << " " << bananas.getName() << "\n\n";
   
    std::cout << "Test islands" << '\n';

    Coordinates miami(125.f, 174.f);
    Coordinates breslau(180.f, 115.f);
    Coordinates chicago(125.f, 174.f);
    std::cout << (breslau == miami) << " " << (chicago == breslau) << " " << (miami == chicago) << "\n\n";

    std::cout << "Test ship Titanic" << '\n';
     
    Ship Titanic(20, 90, 1, ptr_time);
    //Titanic.addCargo(std::shared_ptr<Cargo>(kryptonite));
    Titanic.load(std::make_shared<Item>(kryptonite));

    std::cout << "Vector size: " << Titanic.getCargo().size() << '\n';
    std::cout << "Titanic cargo: " << Titanic.getCargo()[0]->getName() << '\n';
    std::cout << Titanic.getCargo()[0]->getAmount() << "\n\n";
    
    std::cout << "Test make_unique ptr ship" << '\n';
    auto ship = std::make_unique<Ship>(20, 1, 2, "titanic", 3, ptr_time);
    ship->load(std::make_shared<Fruit>(bananas));
    size_t shipCargoSize = ship->getCargo().size();
    Player player(std::move(ship), 1, 1);
    std::cout << "Vector size: " << shipCargoSize << '\n';
    std::cout << "Player's ship speed: " << player.getShip()->getSpeed() << '\n';
    std::cout << "Player's ship cargo name: " << player.getCargo(0)->getName() << '\n';
    std::cout << "Player's ship cargo (should be 15): " << player.getCargo(0)->getAmount() << '\n';
    std::cout << "Player's ship cargo base price: " << player.getCargo(0)->getBasePrice() << '\n';
    
    std::cout << "Available space: " << player.getAvailableSpace() << "\n\n";

    std::cout << "Random islands positions: X | Y" << '\n';
    Map map;
    map.DebugPrintIsland();

    std::cout << '\n' << "Get miami position: X | Y" << '\n';
    map.addIsland(miami);
    Island *is = map.getIsland(miami);
    std::cout << is->getPosition().GetPositionX() << " " << is->getPosition().GetPositionY() << '\n';

    std::cout << "Test Store" << '\n';
    
    store.cargo_.push_back(std::make_shared<Fruit>(bananas));
    store.cargo_.push_back(std::make_shared<Item>(kryptonite));
    std::cout << store.findMatchCargo(&bananas) << " adres bananas: " << store.cargo_[0].get() <<'\n';
    store.sell(&onion, 5, &player);
    store.sell(&onion, 55, &player);
    std::cout << "Print store cargo" << '\n';
    store.printStoreCargo();
    ptr_time->changeTime();

    Alcohol a("A", 1, 1, 96, ptr_time);
    Fruit f("F", 1, 1, 5000, 1, ptr_time);
    DryFruit* df = new DryFruit("DF", 1, 1, 12, 1, ptr_time);
    Item i("I", 1, 1, Rarity::common, ptr_time);

    std::cout << "Alcohol: " << a.getPrice() << "\n";
    std::cout << "Fruit: " << f.getPrice() << "\n";
    std::cout << "Item: " << i.getPrice() << "\n";

    ptr_time->changeTime();

    //std::cout << "Alcohol: " << a.getPrice() << "\n";
    std::cout << "Fruit: " << f.getPrice() << "\n";
    std::cout << "Item: " << i.getPrice() << "\n";



    store.cargo_.push_back(std::make_shared<Fruit>(bananas));
    store.cargo_.push_back(std::make_shared<Item>(kryptonite));
  
    std::cout << store.findMatchCargo(&bananas) << " adres bananas: " << store.cargo_[0].get() <<'\n';
    store.sell(&onion, 5, &player);
    store.sell(&onion, 55, &player);
    std::cout << "Print store cargo" << '\n';
    store.printStoreCargo();

    auto ship1 = std::make_unique<Ship>(20, 1, 2, "Uboot", 3, ptr_time);
    // ship1->setCrew(50);
    // Player player11 (ship, 1000, 1000);
    // Player* player1 = player11;
    // ship->setOwner(player1);
    // time.HowManyObserver();
    // std::cout << player1->getMoney() << '\n';
    // time.changeTime();
    // std::cout << player1->getMoney() << '\n';
    ptr_time->HowManyObserver();
    ptr_time->changeTime();

    DryFruit fruit ("name", 1, 1, 1, 0, ptr_time);
}