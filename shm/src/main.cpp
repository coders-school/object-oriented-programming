#include <iostream>

#include "cargo.hpp"
#include "fruit.hpp"
#include "game.hpp"
#include "map.hpp"
#include "ship.hpp"

int main() {
    std::cout << "Hello world";
    //Cargo* cargo = nullptr;
    Fruit fruit("apple", 10, 2.3, 30);
    std::cout << fruit.getTimeToRotten();
    --fruit;
    std::cout << fruit.getTimeToRotten();
    fruit.nextDay();
    /*
    std::cout << fruit.getTimeToRotten() << '\n';
    auto fruitPtr = std::make_shared<Fruit>(fruit);
    Ship ship(01, "sheeeep", 40, 50, 50);
    ship.load(fruitPtr);
    Fruit fruit2("peer", 10, 2.3, 30);
    fruitPtr = std::make_shared<Fruit>(fruit2);
    ship.load(fruitPtr);
    ship.printCargo();
*/
    std::cout << fruit.getTimeToRotten();
    auto fruitPtr = std::make_shared<Fruit>(fruit);
    Ship ship(01, "sheeeep", 40, 50, 50);
    ship.load(fruitPtr);
    //std::cout << fruit;

    /*
    constexpr size_t start_money = 1'000;
    constexpr size_t game_days = 100;
    constexpr size_t final_goal = 2'000;

    Game game(start_money, game_days, final_goal);
    game.startGame();
*/
    return 0;
}
