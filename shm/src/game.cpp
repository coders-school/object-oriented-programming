#include "game.hpp"

#include <iostream>

Game::Game() {
    map_ = std::make_unique<Map>();
    time_ = std::make_unique<Time>(game_days_);
    ship_ = generateShip();
    player_ = std::make_unique<Player>(ship_, start_money_);
}

Game::Game(size_t start_money, size_t game_days, size_t final_goal)
        : start_money_(start_money), game_days_(game_days), final_goal_(final_goal) {
        Game();
    };

void Game::startGame() {
    while(time_->getElapsedTime() > 0) {
        if (checkWinCondition()) {
            printWinScreen();
            exit();
        }
        if (checkLooseCondition()) {
            printLooseScreen();
            exit();
        }
        printTopBar();
        printOptions();
        size_t action;
        std::cin.clear();
        std::cin >> action;
        makeAction(static_cast<Action>(action));
    }
}

std::shared_ptr<Ship> generateShip() {
    return std::make_shared<Ship>(1, "Maria", 12, 128, 1200);
}

bool Game::checkWinCondition() const {
    return player_->getMoeny() >= final_goal_;
}

bool Game::checkLooseCondition() const {
    return player_->getMoeny() == 0 || time_->getElapsedTime() == 0;
}

void Game::printTopBar() const {
    std::cout << "Top\n";
}

void Game::printOptions() const {
    std::cout << "Options\n";
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

}

void Game::buy() {

}

void Game::sell() {

}

void  Game::printCargo() {

}

void  Game::exit() {

}
