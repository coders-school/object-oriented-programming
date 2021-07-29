#include "Game.hpp"

constexpr size_t start_money = 1000;
constexpr size_t game_days = 100;
constexpr size_t final_goal = 2000;

int main()
{
    Game game(start_money, game_days, final_goal);
    game.startGame();

    return 0;
    /*
    Time *time_ptr = new Time();
    //time->changeTime();

    //Show created store via friend method (zad5)
    Store store(2000, 100, time_ptr);

    std::cout << store;

    Player *captain = new Player(std::make_unique<Ship>(20, 300, 2, "Uboot", 3, time_ptr), 1000, 1000); 
    Player *human = new Player(std::make_unique<Ship>(20, 1, 2, "Titanic", 1, time_ptr), 0, 500); // no money
    Player *human1 = new Player(std::make_unique<Ship>(20, 10, 2, "Tweety", 2, time_ptr), 500, 0); // no capacity
    human->getShip()->addCargo(new Fruit("Gruszka", 5, 5, time_ptr, 15, 0));
    human1->getShip()->addCargo(new Fruit("Gruszka", 5, 5, time_ptr, 15, 0));

    // buy zad 1
    //No cargo
    std::cout << "-------------- ZAD 1 BUY -----------------------------------------------------------------\n";
    
    Cargo * cargo = new Fruit("Kiwi", 5, 5, time_ptr, 15, 0);
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

    Cargo * c1 = store.storeCargo.at(0);
    Cargo * c2 = store.storeCargo.at(2);
    Cargo * c3 = store.storeCargo.at(3);

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
    std::cout << std::to_string(response1 == Response::lack_of_cargo) << "lack of cargo" <<"\n";
     //No available space
    Store store2(2000, 0, time_ptr);
    response1 = store2.sell(captain->getShip()->shipCargo.at(0), 1, captain);
    std::cout << std::to_string(response1 == Response::lack_of_space) << " lack of space" << "\n";
    //lack of cargo
    Store store4(10000, 10000, time_ptr);
    response1 = store4.sell(captain->getShip()->shipCargo.at(1), 1000, captain);
    std::cout << std::to_string(response1 == Response::lack_of_cargo) << " lack of cargo" << "\n";
    //no money
    Store store3(0, 100, time_ptr);
    response1 = store3.sell(captain->getShip()->shipCargo.at(1), 1, captain);
    std::cout << std::to_string(response1 == Response::lack_of_money) << " lack of money" << "\n";
    //correct buy
    std::cout << "pieniążki capitan: " << captain->getMoney() << '\n';
    std::cout << "pieniążki store przed: " << store.getMoney() << '\n';
    std::cout << "store przed sprzedaży \n" << store;
    response1 = store.sell(captain->getShip()->shipCargo.at(0), 1, captain);
    std::cout << std::to_string(response1 == Response::done) << "done?" <<"\n";
    std::cout << "store po sprzedaży \n" << store;
    std::cout << "pieniążki store po: " << store.getMoney() << '\n';
    std::cout << "pieniążki capitan: " << captain->getMoney() << '\n';
    captain->getShip()->printShipCargo();
    std::cout << '\n';

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
    */
}
