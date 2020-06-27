#include <iostream>

#include "Game.hpp"

constexpr size_t startMoney = 1'000;
constexpr size_t gameDays = 100;
constexpr size_t finalGoal = 2'000;

// Temporary added 
#include "Alcohol.hpp"
#include "Cargo.hpp"
#include "Fruit.hpp"

void SampleTest1() {
    Alcohol alcohol{"bushmills", 8, 240, 68};
    Fruit fruit{"truskawka", 15, 7, 2, 5};

    const Cargo& lhs = alcohol;
    const Cargo& rhs = fruit;

    if (lhs == rhs) {
        std::cout << "the same\n";
    } else {
        std::cout << "different\n";
    }

    // const Cargo* pRHS = new Alcohol("wodka", 4, 35, 42);
    const Cargo* pRHS = new Alcohol("bushmills", 8, 240, 68);

    if (lhs == *pRHS) {
        std::cout << "the same\n";
    } else {
        std::cout << "different\n";
    }

    delete pRHS;
}
// Temporary added 

int main() {
    SampleTest1();

    Game game(startMoney, gameDays, finalGoal);
    game.StartGame();

    return 0;
}
