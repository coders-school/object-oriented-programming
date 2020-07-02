#include <iostream>
#include <typeinfo>

#include "cargo.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"

#include "player.hpp"
#include "ship.hpp"

int main() {
    Fruit bananas("Bananas", 200, 10, 8);
    Fruit oranges("Oranges", 150, 12, 8);
    Fruit otherBananas("Bananas", 120, 10, 7);

    Item sword1("Excalibur", 1, 12000, Item::Rarity::legendary);
    Item sword2("Excalibur", 1, 12000, Item::Rarity::legendary);

    if (sword1 == sword2) {
        std::cout << "Same\n";
    } else {
        std::cout << "Different\n";
    }
    if (bananas == otherBananas) {
        std::cout << "Same\n";
    } else {
        std::cout << "Different\n";
    }
    if (bananas == oranges) {
        std::cout << "Same\n";

    } else {
        std::cout << "Different\n";
    }

    Ship ship(1, 2, 3, "a", 2, nullptr);
    Player player(ship, 10000, 100);
    ship.setDelegate(&player);
    ship.nextDay();
    std::cout << player.getMoney();
    return 0;
}
