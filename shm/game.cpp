#include "game.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <memory>


Game::Game(size_t money, size_t days, size_t finalGoal)
    : money_(money), 
      days_(days), 
      finalGoal_(finalGoal),
      currentDay_(1) {}

void Game::startGame() {
    printTrail();
    printStars();
    printStars();
    std::cout << std::setw(8) << "Welcome" 
              << std::setw(8) << "in"
              << std::setw(8) << "SHM"
              << std::setw(8) << "Game" << std::setw(8);
    printStars();
    printStars();
    std::cout << '\n';
    printTrail();
    printStars();
    std::cout << std::setw(8) << "You" 
              << std::setw(8) << "have: "
              << std::setw(8) << days_
              << std::setw(8) << "days to get: "
              << std::setw(8) << finalGoal_
              << std::setw(8) << "gold. Have a nice time!"
              << std::setw(8) << "May the force be with you!";            
    printStars();

    while (days_ > time_->getElapsedTime()) {
        if (checkWinConditions()) {
            printWinScreen();
            return;
        } else if (checkLoseConditions()) {
            printLoseScreen();
            break;
        }
        int pickAction;
        printMenu();
        printOptions();
        std::cin.clear();
        std::cin >> pickAction;
        makeAction(static_cast<Action>(pickAction));
        if (pickAction == 0) {
            break;
        }
    }
}

void Game::printTrail() {
    const std::string trail(100, '-');
    std::cout << trail << '\n';
}

void Game::printStars() {
    const std::string stars(15, '*');
    std::cout << stars;
}

bool Game::checkWinConditions() const {
    return player_->getMoney() >= finalGoal_;
}

void Game::printWinScreen() {
    std::cout << "Congratulations, you won! \n";
}

bool Game::checkLoseConditions() const {
    return currentDay_ > days_ || player_->getMoney() == SIZE_MAX; //change when -= money in player return Size_max
}

void Game::printLoseScreen() {
    std::cout << "You have lost, good bye. \n";
}

void Game::printMenu() {
    std::cout << "Money: " << player_->getMoney()
              << " Day: " << time_->getElapsedTime()
              << " Days left: " << days_ - time_->getElapsedTime();
      //        << " Current position: " << map_->getIsland() << '\n';
}

void Game::printOptions() {
    std::cout << "What do you want to do? \n"
              << "1. Travel \n"
              << "2. Buy \n"
              << "3. Sell \n"
              << "0. Exit game \n";
}

void Game::makeAction(Action pickAction) {
    switch (pickAction) {
        case Action::exit: {
            std::cout << "Bye, bye";
            break;
        }
        case Action::travel: {
            travel();
            break;
        }
        case Action::buy: {
            buy();
            break;
        }
        case Action::sell: {
            sell();
            break;
        }
        case Action::printCargo: {
            printCargo();
            break;
        }
    }
}

void Game::travel() {
    //To do
}

void Game::buy() {
    //To do
}

void Game::sell() {
    //To do
}

void Game::printCargo() {
    //To do
}
