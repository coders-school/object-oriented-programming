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
    auto cargo3 = std::make_shared<Alcohol>(Alcohol("wino", 10, 100, 15));
    // auto cargo4 = std::make_shared<Cargo>("miedz", 10, 1);
    // auto cargo5 = std::make_shared<Cargo>("rubin", 10, 2);
    // auto cargo6 = std::make_shared<Cargo>("cebula", 3, 10);
    // auto cargo7 = std::make_shared<Cargo>("Woda", 200, 500);

    std::vector<std::shared_ptr<Cargo>> LOAD{cargo1, cargo2, cargo3};

    auto s1 = std::make_shared<Ship>(500, 20, 14, 5, "Black Widow", 1, LOAD);
    Player pla1(s1, 5000);
    std::cout << '\n';

    pla1.printCargo();

    // s1->removeFromShip(cargo1, 45);
    s1->addAmountToShip(cargo1, 50);
    

    pla1.printCargo();

    

    Store s;
    std::cout << s;

    // // std::cout << "Pieniadze Store: " << stor1.getMoney() << '\n';

    // // std::cout << stor1;
    // auto cargo4 = std::make_shared<Alcohol>(Alcohol("Pina Colada", 0, 10, 15));
    // auto cargo5 = std::make_shared<Fruit>(Fruit("Peach", 0, 50, 10));

    // std::cout << "Przed załdunkeim: \n\n\n";
    // std::cout << stor1;

    //  auto cargo6 = std::make_shared<Item>(Item("Noz", 0, 50, Rarity::common));
    // //  stor1.addCargo(cargo4, 20);
    // // stor1.addCargo(cargo4, 20);
    // // stor1.addCargo(cargo4, 20);
    // stor1.addCargo(cargo5, 1);
    // std::cout << "po załądunku'\n\n\n" << stor1;
    return 0;
}
