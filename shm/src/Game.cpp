#include "shm/inc/Game.hpp"
#include "shm/inc/Ship.hpp"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>

Game::Game(size_t money, size_t gameDays, size_t finalGoal)
    : money_(money)
    , gameDays_(gameDays)
    , finalGoal_(finalGoal)
    , time_(std::make_unique<Time>())
    , map_(std::make_unique<Map>())
{
    ship_ = std::make_unique<Ship>(1, 25, 100, nullptr);
    player_ = std::make_unique<Player>(std::move(ship_), 100, 10000);
}

void Game::startGame() {
    printWelcomeScreen();
    while (selectOption() != MenuOption::Exit && isGameWon() == false && isGameLost() == false) {
    }
}

bool Game::isGameWon() const {
    return player_->getMoney() >= finalGoal_;
}

bool Game::isGameLost() const {
    // probably not needed (any suggestions?)
    return false;
}

void Game::printWelcomeScreen() {
    std::cout << "############################################################\n";
    std::cout << "#                                                          #\n";
    std::cout << "#         WELCOME TO TRADE SHIP SIMULATOR 1.0.0.0          #\n";
    std::cout << "#                                                          #\n";
    std::cout << "############################################################\n";
    std::cin.get();
}

void Game::printMenu() {
    std::cout << "#" << std::setfill('-')  << std::setw (30) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (22) << " CHOOSE ACTION: " << std::setw (8) << "#\n";
    std::cout << "#" << std::setfill('-')  << std::setw (30) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (30) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (21) << " 1. SHOW MAP " << std::setw (9) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (20) << " 2. TRAVEL " << std::setw (10) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (22) << " 3. CHECK CARGO " << std::setw (8) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (19) << " 4. BUY " << std::setw (11) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (19) << " 5. SELL" << std::setw (11) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (19) << " 6. EXIT" << std::setw (11) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (30) << "#\n";
    std::cout << "#" << std::setfill('-')  << std::setw (31) << "#\n\n";
}

void Game::printIntenface() {
    std::cout << std::setw (99) << std::setfill('#') << "\n";
    std::cout << "#" << std::setfill(' ') << std::setw (97) << "#" << "\n";
    std::cout << "#" << std::setfill(' ') << std::setw (15) << "YOUR MONEY: " << std::setw (8) << std::setfill('0') << money_;
    std::cout << std::setfill(' ') << std::setw (30) << "YOUR GOAL: " << std::setw (8) << std::setfill('0') << finalGoal_;
    std::cout << std::setfill(' ') << std::setw (30) << "DAYS LEFT: " << std::setw (3) << std::setfill('0') << gameDays_ - currentDay_ << std::setfill(' ') << std::setw (4) << "#" "\n";
    std::cout << "#" << std::setfill(' ') << std::setw (97) << "#" << "\n";
    std::cout << std::setw (99) << std::setfill('#') << "\n";
}

void Game::printMap() {
    int i{};
    for (const auto& island : map_->getIslands()) {
        std::cout << "Island no " << ++i 
                  << " ---- Coordinates [" << island.getCoordinates().getPositionX() 
                  << "][" << island.getCoordinates().getPositionY() << "]\n";
    }
}

Game::MenuOption Game::selectOption() {
    printIntenface();
    printMenu();
    size_t option {};
    do {
        std::cout << "Please insert you choice: ";
        std::cin >> option;
    } while (validatingMenuChoose(option) == false);
    menuOption_ = static_cast<MenuOption>(option);
    switch(menuOption_) {
        case MenuOption::printMap :
            printMap();
            break;
        case MenuOption::Travel :
            travel();
            break;
        case MenuOption::CheckCargo :
            checkCargo();
            break;
        case MenuOption::Buy :
            buy();
            break;
        case MenuOption::Sell :
            sell();
            break;
        case MenuOption::Exit :
            if (exitGame() == false) {
                menuOption_ = MenuOption::NoChoose;
            }
            break;
        default:
            std::cout << "Option doesn't exists\n";
    }
    return menuOption_;
}

bool Game::validatingMenuChoose(size_t option) {
    size_t firstOptionElement { 1 };
    size_t lastOptionElement { 6 };
    if (std::cin.fail() || option < firstOptionElement || option > lastOptionElement) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong value please insert number between " << firstOptionElement << " and " << lastOptionElement << ".\n";
        return false;
    }
    return true;
}

Game::ConfirmOption Game::confirmOption(std::string announcemen) {
    std::cout << announcemen << '\n';
    char answer;
    std::cin >> answer;
    if (answer == 'Y' || answer == 'y') {
        return ConfirmOption::Yes;
    }
    if (answer == 'N' || answer == 'n') {
        return ConfirmOption::No;
    }
    std::cout << "Wrong answer, you must choose Y or N\n";
    return ConfirmOption::Error;   
}

bool Game::exitGame() {
    while (true) {
        ConfirmOption exitAnswer = confirmOption("Are you sure you wanna exit game? Y/N");
        if (exitAnswer == ConfirmOption::Yes) {
            return true;
        }
        if (exitAnswer == ConfirmOption::No) {
            return false;
        }
    }
}

void Game::travel() {

}

void Game::checkCargo() {

}

void Game::buy() {

}

void Game::sell() {

}
