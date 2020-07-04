#include "cargo.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "store.hpp"
#include "time.hpp"

#include <iostream>
#include <memory>
#include <string>

int main() {
    Time gameTime;

    Map gameMap(&gameTime);

    gameMap.showIslands();
    std::cout << "Where should we swim?\n";
    unsigned int x;
    unsigned int y;
    std::cin >> x >> y;

    Island* island = gameMap.getIsland(Coordinates(x, y));

    if (island) {
        std::cout << "Island founded!\n";
    } else {
        std::cout << "Sth goes wrong!\n";
    }

    std::cout << "FIRST\n";

    island->getStore()->printCargo();

    std::cout << "SECOND\n";
    island->getStore()->printCargo();

    std::cout << "THIRD + nextDay\n";
    island->getStore()->nextDay();
    island->getStore()->printCargo();

    std::cout << "FOURTH + ++GAMETIME\n";
    ++gameTime;
    island->getStore()->printCargo();

    /*
    Store bieda (&gameTime);


    std::cout << "Co tam w biedzie w promocji\n";
    bieda.generateCargo();
    bieda.printCargo();
    std::cout << "++GameTime\n";
    ++gameTime;
    bieda.printCargo();
    */

    std::cout << "\n**************\n";
}
