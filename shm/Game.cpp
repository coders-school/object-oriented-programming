#include "Game.hpp"
#include <iostream>
#include "Map.hpp"

Game::Game(size_t money, size_t days, size_t finalGoal)
    : money_(money), days_(days), finalGoal_(finalGoal) {
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
        makeAction(printMenu());
        checkWinCondition();
        checkLooseCodition();
        ++(*time_);
    }
};

Action Game::printMenu() {
    system("cls");
    std::cout << "    >>> MAIN  MENU <<<"
              << "\n";
    std::cout << "---------------------------"
              << "\n";
    std::cout << "1. Buy"
              << "\n";
    std::cout << "2. Sell"
              << "\n";
    std::cout << "3. Travel"
              << "\n";
    std::cout << "9. Options"
              << "\n";
    std::cout << "---------------------------"
              << "\n";
    std::cout << "Please choose action: ";
    auto action = readCharacter();

    return action;
}

void Game::makeAction(const Action& action) {
    switch (action) {
    case Action::buy:
        //buy();
        std::cout << "Buy";
        break;
    case Action::sell:
        //sell();
        std::cout << "Sell";
        break;
    case Action::travel:
        //travel();
        std::cout << "Travel";
        break;
    }
}

void Game::buy() {
}

void Game::sell() {
}

void Game::travel() {
}

Action Game::readCharacter() {
    Action action;
    std::cin >> action;
    return action;
    /* while (true)
    {
        std::cin >> action;

        if (action == ( Action::buy or Action::sell or Action::travel )
        {
            return action;
        }
        cout << "Invalid number. Please enter again." << endl;
    } */
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
    system("cls");
    std::cout << "---------------------------" 
              << "\n";
    std::cout << "    >>> YOU WON! <<<"
              << "\n";
    std::cout << "---------------------------";
}

void Game::printLooseScreen(){
    system("cls");
    std::cout << "---------------------------" 
              << "\n";
    std::cout << "    >>> YOU LOST! <<<"
              << "\n";
    std::cout << "---------------------------";
}