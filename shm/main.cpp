#include <iostream>

#include "coordinates.hpp"
#include "island.hpp"
#include "map.hpp"

void mapClassTest();

int main() {
    mapClassTest();

    return 0;
}

void mapClassTest() {
    Map map;
    map.printMap();

    Island* island = map.getIsland(Coordinates(5, 5));

    if (island) {
        std::cout << "\nIsland found (X, Y): "
                << "(" << island->getPosition().getPositionX() << ", "
                << island->getPosition().getPositionY() << ")\n";
    } else {
        std::cout << "\nIsland not found!\n";
    }
}
