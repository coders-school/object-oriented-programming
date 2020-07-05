#include "game.hpp"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <memory>

#include "cargo.hpp"
#include "island.hpp"
#include "store.hpp"

Game::Game(size_t money, size_t days, size_t finalGoal)
    : money_(money),
      days_(days),
      finalGoal_(finalGoal),
      currentDay_(1),
      publisher_(std::make_shared<Time>()),
      ship_(std::make_shared<Ship>(150, 50, 13, "Player_ship", 1, publisher_)),
      player_(std::make_shared<Player>(ship_, 500, 200, publisher_)),
      time_(std::make_shared<Time>()),
      map_(std::make_shared<Map>()) {}

void Game::startGame() {
    printTrail();
    printStars();
    printStars();
    std::cout << std::setw(8) << "Welcome" 
              << std::setw(8) << "in" 
              << std::setw(8) << "SHM" 
              << std::setw(8) << "Game"
              << std::setw(8) << "v1.0"
              << std::setw(8);
    printStars();
    printStars();
    std::cout << '\n';
    printTrail();
    printStars();
    std::cout << std::setw(8) << "You have: " << days_ << " days to get: " << finalGoal_ << " gold. Have a nice time!";
    printStars();
    printStars();
    std::cout << "\n\n\n";
    std::cout << "~~~May the force be with you!~~~ \n";
    printTrail();

    while (days_ > time_->getElapsedTime()) {
        if (checkWinConditions()) {
            printWinScreen();
            return;
        } else if (checkLoseConditions()) {
            break;
        }
        printMenu();
        printTrail();
        printOptions();
        printTrail();
        int pickAction;
        std::cin >> pickAction;
        makeAction(static_cast<Action>(pickAction));
        if (pickAction == 0) {
            break;
        }
        printTrail();
    }
    printLoseScreen();
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
    std::cout << "Congratulations, you won! \n"
              << "You have got " << money_ << "money in " << days_ << "!\n";
    printTrail();
}

bool Game::checkLoseConditions() const {
    return currentDay_ > days_ || player_->getMoney() == SIZE_MAX;  // change when -= money in player return Size_max
}

void Game::printLoseScreen() {
    std::cout << "You have lost, good bye. \n"
              << "You have failed to get: " << finalGoal_ - money_ << " more money.\n";
    printTrail();
}

void Game::printMenu() {
    std::cout << "Money: " << player_->getMoney() << " | "
              << "Day: " << time_->getElapsedTime() << " | "
              << "Days left: " << days_ - time_->getElapsedTime() << " | "
              << "Money to earn: " << finalGoal_ - money_ << " | ";
             // << "Current position: " << map_->getCurrentPosition()->getCoordinates() << '\n';
}

void Game::printOptions() {
    std::cout << "What do you want to do? \n"
              << "1. Travel \n"
              << "2. Buy \n"
              << "3. Sell \n"
              << "4. Print cargo \n"
              << "0. Exit game \n";
}

void Game::makeAction(Action pickAction) {
    switch (pickAction) {
    case Action::exit: {
        std::cout << "Bye, bye \n";
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
        showCargo();
        break;
    }
    default: {
        std::cout << "I can't do this! \n";
    }
    }
}

void Game::travel() {
    while (true) {
        std::cout << *map_;
        std::cout << "Where do you want to sail? (posX posY) \n";
        int posX, posY;
        std::cin >> posX >> posY;
        Island* island = map_->getIsland(Coordinates(posX, posY));
        if (island == map_->getCurrentPosition()) {
            std::cout << "You are already here! \n";
        } else if (island != nullptr) {
            const int travelDistance = map_->getDistanceToIsland(island);
            const size_t speed = player_->getSpeed();
            const size_t daysOfTravel = ((travelDistance + speed) / speed);
            std::cout << "Travel will take " << daysOfTravel << " day/s. Do you want to travel Y/N? ";
            char travelDecision;
            std::cin >> travelDecision;
            if (std::toupper(travelDecision) == 'Y') {
                map_->travel(island);
                std::cout << "~~~~" << '\n' << daysOfTravel << " day/s have passed. \n";
                for (size_t i = 0; i < daysOfTravel; i++) {
                    ++*time_;
                }
                break;
            }
        }
        std::cout << "Give me right coordinates! \n";
    }
}

void Game::buy() {
    Store store(gameTime);
    std::cout << "\n" << store << "\n";
}

void Game::sell() {
    Store store(gameTime);
    std::cout << "\n" << store << "\n";
}

void Game::showCargo() {
    std::cout << "You have: \n";
    ship_->printCargo();
}
