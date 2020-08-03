#include "Game.hpp"
#include "Ship.hpp"

#include <iostream>

constexpr size_t distancePerDay{2};

Game::Game(size_t money, size_t days, size_t final_goal)
    : money_(money), days_(days), final_goal_(final_goal) {}

bool Game::checkWinCondition() const {
    return (player_->getMoney() >= final_goal_);
}

bool Game::checkLoseCondition() const {
    return (player_->getMoney() == 0);
}

void Game::Travel() {
    std::cout << *map_;
    auto destination = map_->getIsland(getTravelLocation());
    if (!destination) {
        return;
    }

    auto distance = map_->getDistanceToIsland(destination);
    map_->setCurrentPosition(destination);
    advanceTimeTraveling(distance);
}

Coordinates Game::getTravelLocation() {
    std::cout << "Type position X of an Island to travel to: ";
    size_t X{};
    std::cin >> X;
    std::cout << "\nType position Y of an Island to travel to: ";
    size_t Y{};
    std::cin >> Y;
    std::cout << "\n";

    return Coordinates(X, Y);
}

void Game::advanceTimeTraveling(size_t distance) {
    while (distance > 0) {
        distance -= distancePerDay;
        time_++;
        days_++;
    }
}

void Game::PrintOptions() {
    std::cout << "Ahoy captain! We're waiting for your commands! \n";
    std::cout << "1. Travel \n";
    std::cout << "2. Buy \n";
    std::cout << "3. Sell \n";
    std::cout << "0. Exit \n";
}

void Game::MakeAction(Action choice) {
    switch (choice) {
    case Action::Exit:
        Exit();
        break;
    case Action::Travel:
        Travel();
        break;
    case Action::Buy:
        Buy();
        break;
    case Action::Sell:
        Sell();
        break;
    default:
        std::cout << "Incorrect choice! Try again!\n";
        break;
    }
}

void Game::startGame() {
    size_t decision{};

    Time time;
    auto timePtr = std::make_shared<Time>(time);

    Map map(timePtr);
    map_ = &map;

    Ship ship(100, 100, 10, "tratwa", 42, timePtr);
    auto shipPtr = std::make_shared<Ship>(ship);

    Player player(shipPtr, money_);
    auto playerPtr = std::make_shared<Player>(player);


    while (1) {
        printOptions();
        std::cin >> decision;
        makeAction(Action(decision));
    }
}
