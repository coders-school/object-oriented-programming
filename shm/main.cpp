#include <iostream>

#include "source/Cargo.hpp"
#include "source/Map.hpp"
#include "source/Player.hpp"

int main() {
    Map();
    Player a;
    Player b;
    Player c;

    c.giveAwayShip();

    std::cout << "\n" << a.takeOverShip(b.giveAwayShip())
        << "\n" << b.takeOverShip(a.giveAwayShip());

    std::cout << "\n\n\n";
    return 0;
}
