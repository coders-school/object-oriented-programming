#include "game.hpp"

#include <cstdlib>  // exit, size_t
#include <ios>
#include <iostream>
#include <limits>

Game::Game() {}

Game::Game(size_t start_money, size_t game_days, size_t final_goal)
    : start_money_(start_money), game_days_(game_days), final_goal_(final_goal) {
    time_ = std::make_shared<Time>(game_days_);
    map_ = std::make_unique<Map>(time_);
    player_ = std::make_unique<Player>(start_money, time_);
}

void Game::startGame() {
    std::cout << "Start\n";
    while (time_->getElapsedTime() > 0) {
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

bool Game::checkWinCondition() const {
    return player_->getMoney() >= final_goal_;
}

bool Game::checkLooseCondition() const {
    return player_->getMoney() == 0;
}

void Game::printTopBar() const {
    std::cout << "  ~~~~    SHM version 1.0   ~~~~" << '\n';
    std::cout << "Elapsed time " << time_->getElapsedTime() << '\n';
    std::cout << "Elapsed money " << player_->getMoney() << '\n';
    std::cout << "Actual position x: " << map_->getCurrentPosition()->getPosition().getPositionX()
              << " y: " << map_->getCurrentPosition()->getPosition().getPositionY() << '\n';
}

void Game::printOptions() const {
    std::cout << "Options:\n";
    std::cout << "1 - Travel\n";
    std::cout << "2 - Buy\n";
    std::cout << "3 - Sell\n";
    std::cout << "4 - Print cargo\n";
    std::cout << "0 - Exit\n";
}

void Game::printWinScreen() const {
    std::cout << "You won!\n";
    std::cout << "You've done it in "
              << game_days_ - time_->getElapsedTime()
              << " days,\n You've earned "
              << player_->getMoney()
              << " coins.\n";
}

void Game::printLooseScreen() const {
    std::cout << "You loose\n";
    if (player_->getMoney() == 0) {
        std::cout << "You've run out of money in "
                  << time_->getElapsedTime()
                  << " days\n";
    } else {
        std::cout << "You didn't get "
                  << final_goal_
                  << " coins in "
                  << game_days_ << ".\n";
    }
}

void Game::makeAction(Action action) {
    switch (action) {
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
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong data type.  Enter two digits: ";
        std::cin >> x >> y;
    }
    auto destination = map_->getIsland(Coordinates(x, y));
    if (destination != nullptr) {
        for (auto i = map_->getDistanceToIsland(destination); i > 0; --i) {
            // one "distance" takes one day
            ++(*time_);
            if (time_->getElapsedTime() == 0) {
                break;
            }
            // player_->nextDay();
        }
        map_->travel(destination);
    } else {
        std::cout << "Wrong coordinates!" << '\n';
    }
}

void Game::buy() {
    std::cout << "Buy\n";
    auto actualIslandStore = map_->getCurrentPosition()->getStore();
    std::cout << actualIslandStore << '\n';
    size_t cargoNr, amountNr;
    std::cout << "Please, write cargo number: ";
    std::cin >> cargoNr;
    std::cout << "Please, write amount: ";
    std::cin >> amountNr;
    while (std::cin.fail() || cargoNr < 0 || cargoNr > actualIslandStore.getCargoContainer().size()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong data. First digit from 0 to " << actualIslandStore.getCargoContainer().size() << ": ";
        std::cin >> cargoNr;
    }
    --cargoNr;
    Response response = actualIslandStore.buy(actualIslandStore.GetCargo(cargoNr), amountNr, player_);

    switch (response) {
    case Response::done:
        std::cout << "Done! \n";
        break;
    case Response::lack_of_cargo:
        std::cout << "Lack of cargo ! \n";
        break;
    case Response::lack_of_money:
        std::cout << "Lack of money! \n";
        break;
    case Response::lack_of_space:
        std::cout << "Lack of space! \n";
        break;
    default:
        std::cout << "I shouldn't be here ;_; \n";
        break;
    }
}

void Game::sell() {
    std::cout << "Sell\n";
    auto actualIslandStore = map_->getCurrentPosition()->getStore();
    //std::cout << actualIslandStore << '\n';
    player_ -> printCargo();
    size_t cargoNr, amountNr;
    std::cout << "Please, write cargo number: ";
    std::cin >> cargoNr;
    std::cout << "Please, write amount: ";
    std::cin >> amountNr;
    while (std::cin.fail() || cargoNr < 0 || cargoNr > player_ -> getCargoAmount()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong data. First digit from 0 to " << player_ -> getCargoAmount() << ": ";
        std::cin >> cargoNr;
    }
    --cargoNr;
    Response response = actualIslandStore.sell(actualIslandStore.GetCargo(cargoNr), amountNr, player_);

    switch (response) {
    case Response::done:
        std::cout << "Done! \n";
        break;
    case Response::lack_of_cargo:
        std::cout << "Lack of cargo ! \n";
        break;
    default:
        std::cout << "I shouldn't be here ;_; \n";
        break;
    }
}

void Game::printCargo() const {
    std::cout << "Cargo\n";
    player_->printCargo();
}

void Game::exit() {
    std::cout << "Exit\n";
    std::exit(0);
}
