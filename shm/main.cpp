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

    Ship blackPearl(200, 50, 180, "black pearl", 1, &gameTime);
    std::shared_ptr<Ship> ptr = std::make_shared<Ship>(200, 50, 180, "black pearl", 1, &gameTime);

    Player pawellos(ptr, 300, 70);

    std::cout << "First\n";
    blackPearl += 10;
    // blackPearl -= 50;
    std::cout << "CREW: " << blackPearl.getCrew() << std::endl;
    pawellos.getShip()->operator+=(10);
    // pawellos->blackPearl += 10;
    std::cout << "CREW2: " << blackPearl.getCrew() << std::endl;
    std::cout << "MONEY: " << pawellos.getMoney() << std::endl;
    ++gameTime;
    std::cout << "MONEY2: " << pawellos.getMoney() << std::endl;

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

    std::cout << "\n**************\n";

}
