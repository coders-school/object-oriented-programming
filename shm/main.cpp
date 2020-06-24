#include "cargo.hpp"
#include "coordinates.hpp"
#include "island.hpp"
#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "time.hpp"

#include <iostream>
#include <memory>
#include <string>

int main() {

    Time gameTime;

    Cargo bananas (10, "Bananas", 100, &gameTime);
    Cargo oranges (50, "Oranges", 10, &gameTime);
    Cargo apples (200, "Apples", 50, &gameTime);

    std::cout << "\n**************\n";

    Ship ship01 (100,20,20.5,"Ship #1", 1, &gameTime);

    ship01.addToCargo(bananas);
    ship01.addToCargo(bananas);
    ship01.addToCargo(bananas);

    ++gameTime;
    {
    Ship ship02 (100,20,20.5,"Ship #2", 1, &gameTime);
    ship02.addToCargo(oranges);

     ++gameTime;
     ++gameTime;
    }
     std::cout << "\n**************\n";

    Ship ship03 (100,20,20.5,"Ship #3", 1, &gameTime);
    ship03.addToCargo(apples);

     ++gameTime;
     ++gameTime;

    return 0;
}
