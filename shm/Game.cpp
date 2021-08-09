#include "Game.hpp"
#include <iostream>
#include <iomanip>
#include <cstdio>
#include "Map.hpp"

Game::Game(size_t money, size_t days, size_t finalGoal)
    : money_(money), days_(days), finalGoal_(finalGoal), currentDay_(1) {
    std::unique_ptr<Map> map(new Map());
    map_ = std::move(map);
    std::unique_ptr<Ship> ship(new Ship(1000, 50, 10, "HMS Terror", 1));
    std::unique_ptr<Player> player(new Player(ship, money_));
    player_ = std::move(player);
    std::unique_ptr<Time> time(new Time());
    time_ = std::move(time);
}

void Game::startGame() {
    while (true) {

        checkWinCondition();
        checkLooseCodition();
        printStats();
        printMenu();
        makeAction(readCharacter());
        ++(*time_);
    }
};

void Game::printStats() {
    std::cout << std::setw (99) << std::setfill('-') << "\n";
    std::cout << "|" << std::setfill(' ') << std::setw (97) << "|" << "\n";
    std::cout << "|" << std::setfill(' ') << std::setw (15) << "YOUR MONEY: " << std::setw (8) << std::setfill('0') << money_;
    std::cout << std::setfill(' ') << std::setw (30) << "YOUR GOAL: " << std::setw (8) << std::setfill('0') << finalGoal_;
    std::cout << std::setfill(' ') << std::setw (30) << "DAYS LEFT: " << std::setw (3) << std::setfill('0') 
              << days_ - currentDay_ << std::setfill(' ') << std::setw (4) << "|" "\n";
    std::cout << "|" << std::setfill(' ') << std::setw (97) << "|" << "\n";
    std::cout << std::setw (99) << std::setfill('-') << "\n" << "\n";

    auto island = map_-> GetCurrentPosition();
    std::cout <<"Island coordinates"<< island->getPosition() << "\n";
    auto store = map_-> GetCurrentPosition()->getStore();
    std::cout << (*store);

    player_-> printCargo();

}

void Game::printMenu() {
    std::cout << std::setw (99) << std::setfill('-') << "\n";
    std::cout << "|" << std::setfill(' ') << std::setw (56)  << "MAIN  MENU" << std::setfill(' ') << std::setw (41) << "|" << "\n";
    std::cout << std::setw (99) << std::setfill('-') << "\n";
    std::cout << "1. Buy" << "\n";
    std::cout << "2. Sell" << "\n";
    std::cout << "3. Travel" << "\n" << "\n";
    std::cout << "9. Options" << "\n";
    std::cout << "10. Exit Game" << "\n";
    std::cout << std::setw (99) << std::setfill('-') << "\n";

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
    Store* store = map_-> GetCurrentPosition()->getStore();
    Cargo* product = store->GetCargo(1);
    std::cout<<product->getName();
    store->buy(product, 10, player_.get());
    getchar();
}

void Game::sell() {

    std::cout << "Selling.." << "\n";
    getchar();
}

void Game::travel() {
    std::cout << "Traveling.." << "\n";
    getchar();
}

Action Game::readCharacter() {
    
    int userInput = 0;
    std::cout << "Please choose your action: ";
    
    std::cin >> userInput;
    //std::cin.clear(); std::cin.sync();

    while (!(((userInput >= 1) && (userInput <= 3)) || ((userInput >= 9) && (userInput <= 10))) ){
        std::cout << "Invalid character. Please choose again: ";
        std::cin.ignore(1000,'\n');
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

bool Game::checkLooseCodition()  {
    if (time_->GetElapsedTime() >= days_) {
        printLooseScreen();
        return true;}
    return false;
    }
    
    

void Game::printWinScreen(){

    std::cout << "---------------------------" 
              << "\n";
    std::cout << "    >>> YOU WON! <<<"
              << "\n";
    std::cout << "---------------------------";
}

void Game::printLooseScreen(){

    std::cout << "---------------------------" 
              << "\n";
    std::cout << "    >>> YOU LOST! <<<"
              << "\n";
    std::cout << "---------------------------";
}