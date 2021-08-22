#include "Game.hpp"
#include "Coordinates.hpp"
#include <cstdio>
#include <iomanip>
#include <iostream>
#include "Map.hpp"

Game::Game(size_t money, size_t days, size_t finalGoal)
    : money_(money), days_(days), finalGoal_(finalGoal), currentDay_(1) {
    std::unique_ptr<Map> map(new Map());
    map_ = std::move(map);
    std::unique_ptr<Ship> ship(new Ship(1000, 50, 15, "HMS Terror", 1));
    std::unique_ptr<Player> player(new Player(ship, money_));
    player_ = std::move(player);
    player_->getShip()->setDelegate(player_.get());
    std::unique_ptr<Time> time(new Time());
    time_ = std::move(time);
    time_->AddObserver(player_->getShip());
}

void Game::startGame() {
    while (true) {
        checkWinCondition();
        checkLooseCodition();
        printStats();
        printMenu();
        makeAction(readCharacter());
    }
};

void Game::printStats() {
    std::cout << std::setw(99) << std::setfill('-') << "\n";
    std::cout << "|" << std::setfill(' ') << std::setw(97) << "|" << "\n";
    std::cout << "|" << std::setfill(' ') << std::setw(15) << "YOUR MONEY: " << std::setw(8) << std::setfill('0') << money_;
    std::cout << std::setfill(' ') << std::setw(30) << "YOUR GOAL: " << std::setw(8) << std::setfill('0') << finalGoal_;
    std::cout << std::setfill(' ') << std::setw(30) << "DAYS LEFT: " << std::setw(3) << std::setfill('0') << days_ - currentDay_ << std::setfill(' ') << std::setw(3) << "|" << "\n";
    std::cout << "|" << std::setfill(' ') << std::setw(97) << "|" << "\n";
    std::cout << std::setw(99) << std::setfill('-') << "\n" << "\n";
    std::cout << (*map_) << "\n";
    auto island = map_->getCurrentIsland();
    std::cout << "Island coordinates" << island->getPosition() << "\n";
    auto store = map_->getCurrentIsland()->getStore();
    std::cout << (*store);

    player_->printCargo();
}

void Game::printMenu() {
    std::cout << std::setw(99) << std::setfill('-') << "\n";
    std::cout << "|" << std::setfill(' ') << std::setw(56) << "ACTION  MENU" << std::setfill(' ') << std::setw(41) << "|"
              << "\n";
    std::cout << std::setw(99) << std::setfill('-') << "\n";
    std::cout << "1. Buy"
              << "\n";
    std::cout << "2. Sell"
              << "\n";
    std::cout << "3. Travel"
              << "\n"
              << "\n";
    std::cout << "9. Options"
              << "\n";
    std::cout << "10. Exit Game"
              << "\n";
    std::cout << std::setw(99) << std::setfill('-') << "\n";

    return;
}

void Game::makeAction(const Action& action) {
    switch (action) {
    case Action::buy:
        buy();
        break;
    case Action::sell:
        sell();
        break;
    case Action::travel:
        travel();
        break;
    case Action::options:
        //printOptions();
        break;
    case Action::exit:
        exit(0);
        break;
    }
}

void Game::buy() {
    std::cout << "Which product would you like tu buy? Choose number: ";
    size_t productNumber;
    std::cin >> productNumber;
    std::cout << "Choose amount: ";
    size_t productAmount;
    std::cin >> productAmount;
    Store* store = map_->getCurrentIsland()->getStore();
    Cargo* product = store->GetCargo(productNumber);
    store->buy(product, productAmount, player_.get());
    money_ = player_ -> getMoney();
}

void Game::sell() {
    std::cout << "Which cargo would you like tu sell? Choose number: ";
    size_t cargoNumber;
    std::cin >> cargoNumber;
    std::cout << "Choose amount: ";
    size_t cargoAmount;
    std::cin >> cargoAmount;
    Store* store = map_->getCurrentIsland()->getStore();
    Ship* ship = player_->getShip();
    Cargo* cargo = ship->getCargo(cargoNumber);
    store->sell(cargo, cargoAmount, player_.get());
    money_ = player_ -> getMoney();
}

void Game::travel() {
    std::cout << "What is you destination. Choose number: ";
    size_t destinationNumber;
    std::cin >> destinationNumber;
    Ship* ship = player_->getShip();
    Island* destination = map_->getIsland(destinationNumber);
    Island* curentIsland = map_ -> getCurrentIsland(); 
    size_t travelTime = Coordinates::distance(curentIsland -> getPosition(), destination -> getPosition()) / ship -> getSpeed();
    elapseTime(travelTime);
    map_-> setCurrentPos(destination);
}

Action Game::readCharacter() {
    int userInput = 0;
    std::cout << "Please choose your action: ";

    std::cin >> userInput;
    //std::cin.clear(); std::cin.sync();

    while (!(((userInput >= 1) && (userInput <= 3)) || ((userInput >= 9) && (userInput <= 10)))) {
        std::cout << "Invalid character. Please choose again: ";
        std::cin.ignore(1000, '\n');
        std::cin >> userInput;
    }
    Action action = static_cast<Action>(userInput);
    return action;
}

void Game::checkWinCondition() {
    if (player_->getMoney() >= finalGoal_) {
        printWinScreen();
    }
    return;
}

bool Game::checkLooseCodition() {
    if (time_->GetElapsedTime() >= days_) {
        printLooseScreen();
        return true;
    }
    return false;
}

void Game::printWinScreen() {
    std::cout << std::setw(99) << std::setfill('-') << "\n";
    std::cout << "|" << std::setfill(' ') << std::setw(56) << "YOU WON!" << std::setfill(' ') << std::setw(41) << "|"
              << "\n";
    std::cout << std::setw(99) << std::setfill('-') << "\n";
}

void Game::printLooseScreen() {
    std::cout << std::setw(99) << std::setfill('-') << "\n";
    std::cout << "|" << std::setfill(' ') << std::setw(56) << "YOU LOST!" << std::setfill(' ') << std::setw(41) << "|"
              << "\n";
    std::cout << std::setw(99) << std::setfill('-') << "\n";
}

void Game::elapseTime(size_t days){
    for(int i = 0; i < days; ++i){
        ++(*time_);
    }
    currentDay_ = time_ -> GetElapsedTime();
    money_ = player_ -> getMoney();    
}