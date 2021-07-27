
#include <iostream>
#include <memory>
#include <vector>

#include "Time.hpp"
#include "Store.hpp"
#include "player.hpp"
#include "fruit.hpp"
#include "alcohol.hpp"
#include "item.hpp"
#include "cargo.hpp"
#include "ship.hpp"


int main()
{
    Time *time_ptr = new Time();
    //time->changeTime();

    //Show created store via friend method (zad5)
    Store store(2000, 100, time_ptr);

    std::cout << store;

    Player *captain = new Player(std::make_unique<Ship>(20, 300, 2, "Uboot", 3, time_ptr), 1000, 1000);
    Player *human = new Player(std::make_unique<Ship>(20, 1, 2, "Titanic", 1, time_ptr), 0, 500);
    Player *human1 = new Player(std::make_unique<Ship>(20, 10, 2, "Tweety", 2, time_ptr), 500, 0);
    
    // buy zad 1
    //No cargo
    std::cout << "-------------- ZAD 1 BUY -----------------------------------------------------------------\n";

    //tutaj
    std::vector<Cargo*> storeA;
    Fruit banany("Banany", 10, 20, time_ptr, 15, 0); 
    Alcohol vodka("Vodka", 33, 60, time_ptr, 70);
    Item hook("Hook", 5, 100, time_ptr, Rarity::common);//push_back
    storeA.push_back(&banany);
    storeA.push_back(&vodka);
    storeA.push_back(&hook);
    std::vector<Cargo*> shipA;
    Fruit cytryny("Cytryny", 10, 20, time_ptr, 15, 0); 
    Alcohol whiskey("Whiskey", 33, 60, time_ptr, 70);
    Item nail("Nail", 5, 100, time_ptr, Rarity::common);
    shipA.push_back(&cytryny);
    shipA.push_back(&whiskey);
    shipA.push_back(&nail);
 
    std::cout << "PRZED ZAKUPEM\n";
    std::cout << "SKLEP\n";
    for(auto a: storeA){
        std::cout << a->getName() << " " << a->getAmount() << " \n"; 
    }
    std::cout << "STATEK\n";
    for(auto a: shipA){
        std::cout << a->getName() << " " << a->getAmount() << " \n"; 
    }

    //Cargo, amount
    //chcemy kupic 7 bananow
    //store:3, ship:7
    Cargo c = *storeA[0];
    Cargo* toAdd = &c;
    //amount do kupienia == amount mamy w sklepie
    //Cargo* toAdd = storeA[0];

    toAdd->setAmount(7);
    storeA[0]->reduceAmount(7);
    shipA.push_back(toAdd);

    std::cout << "\n\nPO ZAKUPIE\n";
    std::cout << "SKLEP\n";
    for(auto a: storeA){
        std::cout << a->getName() << " " << a->getAmount() << " \n"; 
    }
    std::cout << "STATEK\n";
    for(auto a: shipA){
        std::cout << a->getName() << " " << a->getAmount() << " \n"; 
    }
    
  /*  std::shared_ptr<Cargo> cargo = std::make_shared<Fruit>("Kiwi", 5, 5, time_ptr, 15, 0);
    Response response = store.buy(cargo, 5, captain);
    std::cout << std::to_string(response == Response::lack_of_cargo) << "\n";
    //No available space
    response = store.buy(store.storeCargo.at(0), 1, human1);
    std::cout << std::to_string(response == Response::lack_of_space) << "\n";
    //lack of cargo
    response = store.buy(store.storeCargo.at(0), 1000, captain);
    std::cout << std::to_string(response == Response::lack_of_cargo) << "\n";
    //no money
    response = store.buy(store.storeCargo.at(0), 1, human);
    std::cout << std::to_string(response == Response::lack_of_money) << "\n";
    //correct buy
    std::cout << "Store money: " << store.getMoney() << '\n';
    std::cout << "Store size: " << store.storeCargo.size() << '\n';

    std::shared_ptr<Cargo> c1 = store.storeCargo.at(0);
    std::shared_ptr<Cargo> c2 = store.storeCargo.at(2);
    std::shared_ptr<Cargo> c3 = store.storeCargo.at(3);

    response = store.buy(c3, 1, captain);
    response = store.buy(c1, 1, captain);
    response = store.buy(c2, 1, captain);

    std::cout << std::to_string(response == Response::done) << "\n";
    std::cout << store;
    std::cout << "Store money: " << store.getMoney() << '\n'; 
    std::cout <<  "size:" <<captain->getShip()->shipCargo.size() << '\n'; //TO DO
    captain->getShip()->printShipCargo(); 
    std::cout << "-------------- ZAD 1 SELL -----------------------------------------------------------------\n";
    // sell zad 1
    Response response1 = store.sell(cargo, 2, captain);
    std::cout << std::to_string(response1 == Response::lack_of_cargo) << "lack of cargo" <<"\n";*/
    // //No available space
    // response1 = store.sell(captain->getShip()->shipCargo.at(1), 1, human1);
    // std::cout << std::to_string(response1 == Response::lack_of_space) << "lack of space" << "\n";
    // //lack of cargo
    // response1 = store.sell(captain->getShip()->shipCargo.at(1), 1000, captain);
    // std::cout << std::to_string(response1 == Response::lack_of_cargo) << "lack of cargo" << "\n";
    // //no money
    // response1 = store.sell(captain->getShip()->shipCargo.at(1), 1, human);
    // std::cout << std::to_string(response1 == Response::lack_of_money) << "lack of money" << "\n";
    // //correct buy
 /*   std::cout << "pieniążki store przed: " << store.getMoney() << '\n';
    std::cout << "store przed sprzedaży \n" << store;
    response1 = store.sell(captain->getShip()->shipCargo.at(0), 1, captain);
    // response1 = store.sell(captain->getShip()->shipCargo.at(0), 2, captain);
    // std::cout << std::to_string(response1 == Response::done) << "done?" <<"\n";
    std::cout << "store po sprzedaży \n" << store;
    std::cout << "pieniążki store po: " << store.getMoney() << '\n';
    
    captain->getShip()->printShipCargo();
    std::cout << '\n';*/

    //zad 2
    // std::cout << "-------------- ZAD 2 -----------------------------------------------------------------\n";
    // Alcohol wine = Alcohol("wino", 10, 20, time_ptr, 80);
    // Fruit kiwi = Fruit("Kiwi", 15, 14, time_ptr, 20, 0);
    // Item hook = Item("Special Hook", 5, 100, time_ptr, Rarity::rare);
    // Fruit banan("Banany", 5, 20, time_ptr, 15, 0);
    // Fruit banany("Banany", 6, 20, time_ptr, 15, 0);

    // std::cout << wine.getName() << " " << wine.getBasePrice() << " " << wine.getPrice() << " " << wine.getAmount() << "\n";
    // std::cout << kiwi.getName() << " " << kiwi.getBasePrice() << " " << kiwi.getPrice() << " " << kiwi.getAmount() << "\n";
    // std::cout << hook.getName() << " " << hook.getBasePrice() << " " << hook.getPrice() << " " << hook.getAmount() << "\n";

    // wine += 4;
    // kiwi += 4;
    // hook += 4;

    // std::cout << wine.getName() << " " << wine.getBasePrice() << " " << wine.getPrice() << " " << wine.getAmount() << "\n";
    // std::cout << kiwi.getName() << " " << kiwi.getBasePrice() << " " << kiwi.getPrice() << " " << kiwi.getAmount() << "\n";
    // std::cout << hook.getName() << " " << hook.getBasePrice() << " " << hook.getPrice() << " " << hook.getAmount() << "\n";

    // wine -= 3;
    // kiwi -= 3;
    // hook -= 3;

    // std::cout << wine.getName() << " " << wine.getBasePrice() << " " << wine.getPrice() << " " << wine.getAmount() << "\n";
    // std::cout << kiwi.getName() << " " << kiwi.getBasePrice() << " " << kiwi.getPrice() << " " << kiwi.getAmount() << "\n";
    // std::cout << hook.getName() << " " << hook.getBasePrice() << " " << hook.getPrice() << " " << hook.getAmount() << "\n";

    // std::cout << std::to_string(wine == kiwi) << "\n";
    // std::cout << std::to_string(kiwi == hook) << "\n";
    // std::cout << std::to_string(hook == wine) << "\n";
    // std::cout << std::to_string(kiwi == kiwi) << "\n";
    // std::cout << std::to_string(banan == banany) << '\n';

    //Zad3
    // std::cout << "-------------- ZAD 3 -----------------------------------------------------------------\n";
    // //przed nextDay
    // Fruit orange = Fruit("Orange", 15, 140, time_ptr, 1, 0);
    // captain->setCrew(5);

    // std::cout << captain->getMoney() << "\n";
    // std::cout << wine.getName() << " " << wine.getBasePrice() << " " << wine.getPrice() << " " << wine.getAmount() << "\n";
    // std::cout << orange.getName() << " " << orange.getBasePrice() << " " << orange.getPrice() << " " << orange.getAmount() << "\n";
    // std::cout << hook.getName() << " " << hook.getBasePrice() << " " << hook.getPrice() << " " << hook.getAmount() << "\n";
    // std::cout << store;

    // time_ptr->changeTime();

    // //Po nextDay
    // std::cout << captain->getMoney() << "\n";
    // std::cout << wine.getName() << " " << wine.getBasePrice() << " " << wine.getPrice() << " " << wine.getAmount() << "\n";
    // std::cout << orange.getName() << " " << orange.getBasePrice() << " " << orange.getPrice() << " " << orange.getAmount() << "\n";
    // std::cout << hook.getName() << " " << hook.getBasePrice() << " " << hook.getPrice() << " " << hook.getAmount() << "\n";
    // std::cout << store;
    
}