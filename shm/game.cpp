#include "game.hpp"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>

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
      map_(std::make_shared<Map>(publisher_.get())) {
          ship_->fillInCrew();
      }

void Game::startGame() {
    printWelcomePage();
    gameLoop();
    printLoseScreen();
}

void Game::gameLoop() {
    while (days_ > publisher_->getElapsedTime()) {
        if (checkWinConditions()) {
            printWinScreen();
            return;
        } else if (checkLoseConditions()) {
            break;
        }
        printStats();
        printOptions();
        int pickAction;
        std::cin >> pickAction;
        inputValidator();
        makeAction(static_cast<Action>(pickAction));
        if (pickAction == 0) {
            break;
        }
    }
}

void Game::inputValidator() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Something went wrong, try to type it one more time.\n";
    }
}

void Game::printTrail(char sign) {
    const std::string trail(100, sign);
    std::cout << trail << '\n';
}

void Game::printStars(size_t amountOfGalaxy) {
    constexpr size_t galaxy = 15;
    const std::string stars(amountOfGalaxy * galaxy, '*');
    std::cout << stars;
}

void Game::printHeader() {
    printTrail('-');
    printStars(2);
    std::cout << std::setw(8) << "Welcome" 
              << std::setw(8) << "in" 
              << std::setw(8) << "SHM" 
              << std::setw(8) << "Game"
              << std::setw(8) << "v1.0";
    printStars(2);
    std::cout << '\n';
    printTrail('-');
}

void Game::printWelcomePage() {
    printHeader();
    printStars(1);
    std::cout << std::setw(8) << "You have: " << days_ << " days to get: " << finalGoal_ << " gold. Have a nice time!";
    printStars(2);
    std::cout << "\n\n\n";
    std::cout << "~~~May the force be with you!~~~ \n";
    printTrail('-');
    std::cout << "\n\n\n";
}

bool Game::checkWinConditions() const {
    return player_->getMoney() >= finalGoal_;
}

void Game::printWinScreen() {
    printTrail('+');
    std::cout << "Congratulations, you won! \n"
              << "You have got " << money_ << "money in " << days_ << "!\n";
    printTrail('+');
}

bool Game::checkLoseConditions() const {
    return currentDay_ > days_ || player_->getMoney() == SIZE_MAX;  // change when -= money in player return Size_max
}

void Game::printLoseScreen() {
    printTrail('-');
    std::cout << "You have lost, good bye. \n"
              << "You have failed to get: " << finalGoal_ - player_->getMoney() << " more money.\n";
    printTrail('-');
}

void Game::printStats() {
    printTrail('=');
    std::cout << "Money: " << player_->getMoney() << " | "
              << "Day: " << publisher_->getElapsedTime() << " | "
              << "Days left: " << days_ - publisher_->getElapsedTime() << " | "
              << "Money to earn: " << finalGoal_ - player_->getMoney() << " | "
              << "Current position: " << map_->getCurrentPosition()->getCoordinates() << '\n';
    printTrail('=');
}

void Game::printOptions() {
    printTrail('-');
    std::cout << "What do you want to do? \n"
              << "1. Travel \n"
              << "2. Buy \n"
              << "3. Sell \n"
              << "4. Print cargo \n"
              << "0. Exit game \n";
    printTrail('-');
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

Island* Game::pickTargetIsland() {
    std::cout << *map_;
    std::cout << "Where do you want to sail? (posX posY) \n";
    int posX, posY;
    std::cin >> posX >> posY;
    inputValidator();
    Island* island = map_->getIsland(Coordinates(posX, posY));
    return island;
}

size_t Game::countDaysOfTravel(Island* island) {
    const int travelDistance = map_->getDistanceToIsland(island);
    const size_t speed = player_->getSpeed();
    const size_t daysOfTravel = ((travelDistance + speed) / speed);
    return daysOfTravel;
}

char Game::userTravelDecision(size_t daysOfTravel) {
    std::cout << "Travel will take " << daysOfTravel << " day/s. Do you still want to travel Y/N? ";
    char travelDecision;
    std::cin >> travelDecision;
    inputValidator();
    return static_cast<char>(std::toupper(travelDecision));
}

void Game::travel() {
    while (true) {
        Island* island = pickTargetIsland();
        if (island == map_->getCurrentPosition()) {
            std::cout << "You are already here! \n";
        } else if (island != nullptr) {
            size_t daysOfTravel = countDaysOfTravel(island);
            char travelDecision = userTravelDecision(daysOfTravel);
            if (travelDecision == 'Y') {
                makeTravel(island, daysOfTravel);
                break;
            }
            if (travelDecision == 'N') {
                break;
            }
        }
        std::cout << "Give me right coordinates! \n";
    }
}

void Game::makeTravel(Island* island, size_t daysOfTravel) {
    map_->travel(island);
    std::cout << "~~~~ " << daysOfTravel << " day/s have passed: \n";
    for (size_t i = 0; i < daysOfTravel; i++) {
        std::cout << i + 1 << ". ";
        ++*publisher_;
    }
}

void Game::buy() {
    while (true) {
        Island* currentIsland = map_->getCurrentPosition();
        Store* store = currentIsland->getStore().get();
        std::cout << "\n" << *store << "\n";
        printTrail('-');
        std::cout << "Select product name and amount: (0 0 to exit)";
        std::string name;
        size_t amount = 0;
        std::cin >> name >> amount;

        if (amount == 0 && name == "0") {
            return;
        }

        std::shared_ptr<Cargo> cargo = store->getCargo(name);
        printTrail('-');

        if (!cargo) {
            std::cout << "Wrong cargo name. Try again.\n";
            continue;
        }

        while (true) {
            std::cout << "Total price is: " << store->getTotalBuyPrice(cargo, amount) << '\n';
            std::cout << "Do you want to make a purchase? (Y/N) ";
            char answer;
            std::cin >> answer;
            if (std::tolower(answer) == 'n')
                return;
            else if (std::tolower(answer) == 'y')
                break;

            std::cin.clear();
            std::cout << "Wrong answer! Operation interrupted.\n";
        }

        switch (store->buy(cargo, amount, player_.get())) {
        case Response::done:
            std::cout << "Buy " << amount << " " << name << '\n';
            return;
            break;
        case Response::lack_of_cargo:
            std::cout << "There is no enough cargo to buy!\n";
            break;
        case Response::lack_of_money:
            std::cout << "You dont have enough money to buy cargo!\n";
            break;
        case Response::lack_of_space:
            std::cout << "You dont have enough space to store cargo\n";
            break;
        default:
            break;
        }
    }
}

void Game::sell() {
    showCargo();
    while (true) {
        Island* currentIsland = map_->getCurrentPosition();
        Store* store = currentIsland->getStore().get();
        std::cout << "\n" << *store << "\n";
        printTrail('-');
        std::cout << "Select product name and amount: (0 0 to exit)";
        std::string name;
        size_t amount = 0;
        std::cin >> name >> amount;

        if (amount == 0 && name == "0") {
            return;
        }

        std::shared_ptr<Cargo> cargo = store->getCargo(name);
        printTrail('-');

        if (!cargo) {
            std::cout << "Wrong cargo name. Try again.\n";
            continue;
        }

        auto foundedCargo = ship_->findCargoByName(name);

        if (!foundedCargo) {
            std::cout << "You don't have " << name << " on ship. Select another product.\n";
            continue;
        }

        if (foundedCargo->getAmount() < amount) {
            std::cout << "You have only " << foundedCargo->getAmount() << " " << name 
            << ". Try to sell less product.\n";
            continue;
        }

        while (true) {
            std::cout << "Total price is: " << store->getTotalSellPrice(cargo, amount) << '\n';
            std::cout << "Do you want to sell cargo? (Y/N) ";
            char answer;
            std::cin >> answer;
            if (std::tolower(answer) == 'n')
                return;
            else if (std::tolower(answer) == 'y')
                break;

            std::cin.clear();
            std::cout << "Wrong answer! Operation interrupted.\n";
        }

        switch (store->sell(cargo, amount, player_.get())) {
        case Response::done:
            std::cout << "Sell " << amount << " " << name << '\n';
            return;
            break;
        case Response::lack_of_space:
            std::cout << "There is no enough space in store. Try to sell less product.\n";
            break;
        default:
            break;
        }
    }
}

void Game::showCargo() {
    std::cout << "You have: \n";
    ship_->printCargo();
}
