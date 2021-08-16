#include <iomanip>
#include <iostream>
#include <memory>

#include "alcohol.hpp"
#include "cargo.hpp"
#include "fruit.hpp"
#include "island.hpp"
#include "item.hpp"
#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "store.hpp"

int main() {
    auto cargo1 = std::make_shared<Fruit>("cebula", 40, 2, 20);
    auto cargo2 = std::make_shared<Item>("drewno", 10, 20, Rarity::epic);
    auto cargo3 = std::make_shared<Alcohol>("wino", 10, 100, 15);
    // auto cargo4 = std::make_shared<Cargo>("miedz", 10, 1);
    // auto cargo5 = std::make_shared<Cargo>("rubin", 10, 2);
    // auto cargo6 = std::make_shared<Cargo>("cebula", 3, 10);
    // auto cargo7 = std::make_shared<Cargo>("Woda", 200, 500);

    std::vector<std::shared_ptr<Cargo>> LOAD{cargo1, cargo2, cargo3};

    auto s1 = std::make_shared<Ship>(500, 20, 14, 5, "Black Widow", 1, LOAD);
    Player pla1(s1, 5000, 0);
    std::cout << '\n';

    // pla1.printCargo();
    // std::cout << s1;
    Store s;

    auto car1 = s.getCargoOfStore()[1];
//     std::cout << '\n';

    // std::cout << "\nile miejsca na statku :" << pla1.getAvailableSpace() << '\n';
    std::cout << car1->getName() << " " << car1->getAmount() << " : " << car1->getBasePrice() << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << s;

    // pla1.getShip()->load(car1, 20);
    // pla1.getShip()->load(car1, 20);
    // pla1.getShip()->load(car1, 20);
    // pla1.getShip()->unload(car1, 0);
    
    // std::cout << "Ile miejsca na statku " << pla1.getAvailableSpace() << '\n';

    // pla1.printCargo();    


//     std::cout << "Kasa gracza: " << pla1.getMoney() << '\n';
//     s.sell(car1, 80, &pla1);
//     std::cout << "Kasa gracza: " << pla1.getMoney() << '\n';
    
//     std::cout << '\n';
//     std::cout << '\n';
//     pla1.printCargo();
//     std::cout << '\n';
//     std::cout << '\n';
//     std::cout << s;
//     // s.buy(car1, 20, &pla1);
// std::cout << '\n';
//     std::cout << '\n';
//     pla1.printCargo();
//     // s.sell(car1, 50, &pla1);
//     std::cout << s;
//     std::cout << '\n';
//     std::cout << "\nile miejsca na statku :" << pla1.getAvailableSpace() << '\n';
//     // s.buy(car1, 20, &pla1);
    
    return 0;
}
