#include "cargo.hpp"
#include "fruit.hpp"
#include "player.hpp"
#include "item.hpp"
#include "map.hpp"
#include "ship.hpp"
#include "store.hpp"
#include "time.hpp"

#include <iostream>
#include <memory>
#include <string>

int main() {

    Time gameTime;

    Ship blackPearl(200, 50, 180, "black pearl", 1, &gameTime);
    std::shared_ptr<Ship> ptr = std::make_shared<Ship>(200, 50, 180, "black pearl", 1, &gameTime);

    Player pawellos(ptr, 300, 70);

    Map gameMap(&gameTime);
    gameMap.showIslands();
    std::cout << "Where should we swim?\n";
    unsigned int x;
    unsigned int y;
    std::cin >> x >> y;

    Island* island = gameMap.getIsland(Coordinates(x, y));
    std::cout << "First\n";
    island->getStore().printCargo();
    std::cout << "Second\n";
    island->getStore().printCargo();
    std::cout << "++GAMETIME!!!\n";
    ++gameTime;
    island->getStore().printCargo();

    Store bieda (&gameTime);
    std::cout << "Co tam w biedzie w promocji\n";
    bieda.generateCargo();
    bieda.printCargo();
    std::cout << "++GameTime\n";
    ++gameTime;
    bieda.printCargo();


    std::cout << "\n**************\n";


}
