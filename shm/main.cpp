
#include <iostream>
#include <memory>

#include "Time.hpp"
#include "Store.hpp"
#include "player.hpp"
#include "fruit.hpp"
#include "alcohol.hpp"
#include "item.hpp"
#include "cargo.hpp"

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
    Cargo *cargo = new Fruit("Kiwi", 5, 5, time_ptr, 15, 0);
    Response response = store.buy(cargo, 5, captain);
    std::cout << std::to_string(response == Response::lack_of_cargo) << "\n";
    //No available space
    response = store.buy(store.storeCargo.at(0).get(), 1, human1);
    std::cout << std::to_string(response == Response::lack_of_space) << "\n";
    //lack of cargo
    response = store.buy(store.storeCargo.at(0).get(), 1000, captain);
    std::cout << std::to_string(response == Response::lack_of_cargo) << "\n";
    //no money
    response = store.buy(store.storeCargo.at(0).get(), 1, human);
    std::cout << std::to_string(response == Response::lack_of_money) << "\n";
    //correct buy
    std::cout << "pieniążki store przed: " << store.getMoney() << '\n';
    response = store.buy(store.storeCargo.at(0).get(), 1, captain);
    response = store.buy(store.storeCargo.at(0).get(), 1, captain);
    std::cout << std::to_string(response == Response::done) << "\n";
    std::cout << store;
    std::cout << "pieniążki store po: " << store.getMoney() << '\n';
    
    captain->getShip()->printShipCargo();
    
    // sell zad 1

    //TO DO:: poprawic Sell i zrobić unload

    //zad 2
    Alcohol wine = Alcohol("wino", 10, 20, time_ptr, 80);
    Fruit kiwi = Fruit("Kiwi", 15, 14, time_ptr, 20, 0);
    Item hook = Item("Special Hook", 5, 100, time_ptr, Rarity::rare);
    Fruit banan("Banany", 5, 20, time_ptr, 15, 0);
    Fruit banany("Banany", 6, 20, time_ptr, 15, 0);

    std::cout << wine.getName() << " " << wine.getBasePrice() << " " << wine.getPrice() << " " << wine.getAmount() << "\n";
    std::cout << kiwi.getName() << " " << kiwi.getBasePrice() << " " << kiwi.getPrice() << " " << kiwi.getAmount() << "\n";
    std::cout << hook.getName() << " " << hook.getBasePrice() << " " << hook.getPrice() << " " << hook.getAmount() << "\n";

    wine += 4;
    kiwi += 4;
    hook += 4;

    std::cout << wine.getName() << " " << wine.getBasePrice() << " " << wine.getPrice() << " " << wine.getAmount() << "\n";
    std::cout << kiwi.getName() << " " << kiwi.getBasePrice() << " " << kiwi.getPrice() << " " << kiwi.getAmount() << "\n";
    std::cout << hook.getName() << " " << hook.getBasePrice() << " " << hook.getPrice() << " " << hook.getAmount() << "\n";

    wine -= 3;
    kiwi -= 3;
    hook -= 3;

    std::cout << wine.getName() << " " << wine.getBasePrice() << " " << wine.getPrice() << " " << wine.getAmount() << "\n";
    std::cout << kiwi.getName() << " " << kiwi.getBasePrice() << " " << kiwi.getPrice() << " " << kiwi.getAmount() << "\n";
    std::cout << hook.getName() << " " << hook.getBasePrice() << " " << hook.getPrice() << " " << hook.getAmount() << "\n";

    std::cout << std::to_string(wine == kiwi) << "\n";
    std::cout << std::to_string(kiwi == hook) << "\n";
    std::cout << std::to_string(hook == wine) << "\n";
    std::cout << std::to_string(kiwi == kiwi) << "\n";
    std::cout << std::to_string(banan == banany) << '\n';

    //Zad3

    //przed nextDay
    Fruit orange = Fruit("Orange", 15, 140, time_ptr, 1, 0);
    captain->setCrew(5);

    std::cout << captain->getMoney() << "\n";
    std::cout << wine.getName() << " " << wine.getBasePrice() << " " << wine.getPrice() << " " << wine.getAmount() << "\n";
    std::cout << orange.getName() << " " << orange.getBasePrice() << " " << orange.getPrice() << " " << orange.getAmount() << "\n";
    std::cout << hook.getName() << " " << hook.getBasePrice() << " " << hook.getPrice() << " " << hook.getAmount() << "\n";
    std::cout << store;

    time_ptr->changeTime();

    //Po nextDay
    std::cout << captain->getMoney() << "\n";
    std::cout << wine.getName() << " " << wine.getBasePrice() << " " << wine.getPrice() << " " << wine.getAmount() << "\n";
    std::cout << orange.getName() << " " << orange.getBasePrice() << " " << orange.getPrice() << " " << orange.getAmount() << "\n";
    std::cout << hook.getName() << " " << hook.getBasePrice() << " " << hook.getPrice() << " " << hook.getAmount() << "\n";
    std::cout << store;
    
}