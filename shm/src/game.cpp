#include "game.hpp"

#include <cstdlib> // exit, size_t
#include <ios>
#include <iostream>
#include <limits>

Game::Game() {}

Game::Game(size_t start_money, size_t game_days, size_t final_goal)
    : start_money_(start_money), game_days_(game_days), final_goal_(final_goal) {
    map_ = std::make_unique<Map>();
    time_ = std::make_unique<Time>(game_days_);
    ship_ = generateShip();
    player_ = std::make_unique<Player>(ship_, start_money_);
};

void Game::startGame() {
    std::cout << "Start\n";
    while(time_->getElapsedTime() > 0) {
        if (checkWinCondition()) {
            printWinScreen();
            exit();
        }
        if (checkLooseCondition()) {
            break;
        }
        printTopBar();
        printOptions();
        size_t action;
        std::cout << "Action: ";
        std::cin.clear();
        std::cin >> action;
        makeAction(static_cast<Action>(action));
    }
    printLooseScreen();
    exit();
}

std::shared_ptr<Ship> Game::generateShip() {
    return std::make_shared<Ship>(1, "Maria", 1, 128, 1200);
}

bool Game::checkWinCondition() const {
    return player_->getMoney() >= final_goal_;
}

bool Game::checkLooseCondition() const {
    return player_->getMoney() == 0;
}

void Game::printTopBar() const {
    std::cout << "Top\n";
    std::cout << "Elapsed time " << time_->getElapsedTime() << '\n';
}

void Game::printOptions() const {
    std::cout << "Options:\n";
    std::cout << "1 - Travel\n";
    std::cout << "0 - Exit\n";
}

void Game::printWinScreen() const {
    std::cout << "Win\n";
}

void  Game::printLooseScreen() const {
    std::cout << "Loose\n";
}

void Game::makeAction(Action action) {
    switch(action) {
    case Action::Exit:
        exit();
        break;
    case Action::Travel:
        travel();
        break;
    case Action::Buy:
        buy();
        break; 
    case Action::Sell:
        sell();
        break;
    case Action::PrintCargo:
        printCargo();
        break;
    default:
        std::cout << "Wrong, Sailor!\n";
        break;
    }
}

void Game::travel() {
    std::cout << "Travel\n";
    std::cout << *map_.get();
    std::cout << "Choose island [x y]: ";
    size_t x, y;
    std::cin >> x >> y;
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Wrong data type.  Enter two digits: ";
        std::cin >> x >> y;
    }
    auto destination = map_->getIsland(Coordinates(x, y));
    if (destination != nullptr)
    {
        for (auto i = map_->getDistanceToIsland(destination); i > 0; --i) {
            // one "distance" takes one day
            ++(*time_);
        }
        map_->travel(destination);
     }
     else { std::cout << "Wrong coordinates!" << '\n'; }
}

void Game::buy() {
    std::cout << "Buy\n";
}

void Game::sell() {
    std::cout << "Sell\n";
}

void  Game::printCargo() const {
    std::cout << "Cargo\n";
    player_ -> printCargo();
}

void  Game::exit() {
    std::cout << "Exit\n";
    std::exit(0);
}
