#include <iostream>

#include "player.hpp"
#include "ship.hpp"

int main() {
    Ship ship(100, 20, 5, "Black Perl", 200, nullptr);
    Player Stefan(ship, 1000, 400);
    ship.setDelegate(&Stefan);

    std::cout << Stefan.getMoney() << '\n';

    ship += 10;  // add some crew
    ship.nextDay();
    std::cout << Stefan.getMoney() << '\n';

    return 0;
}
