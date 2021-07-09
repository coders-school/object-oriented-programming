#include "shm/inc/Game.hpp"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>

#include "shm/inc/Ship.hpp"
#include "shm/inc/Island.hpp"

constexpr size_t FIRST_OPTION_ELEMENT { 1 };
constexpr size_t LAST_OPTION_ELEMENT { 6 };

Game::Game(size_t money, size_t gameDays, size_t finalGoal)
    : money_(money)
    , gameDays_(gameDays)
    , finalGoal_(finalGoal)
    , time_(std::make_unique<Time>())
    , map_(std::make_unique<Map>())
{
    ship_ = std::make_unique<Ship>(1, 25, 100, nullptr);
    player_ = std::make_unique<Player>(std::move(ship_), 100, 10000);
    //std::cout << *map_->getIslands()[0].getStore();

}

void Game::startGame() {
    printWelcomeScreen();
    while (isGameWon() == false && isGameLost() == false) {
        if (selectOption() == MenuOption::Exit) {
            break;
        }
    }
}

bool Game::isGameWon() {
    if (player_->getMoney() >= finalGoal_) {
        printWinScreen();
        return true;
    }
    return false;
}

void Game::printWinScreen() {
    std::cout << "############################################################\n";
    std::cout << "#                                                          #\n";
    std::cout << "#                  CONGRATULATION YOU WIN                  #\n";
    std::cout << "#                                                          #\n";
    std::cout << "############################################################";
    std::cin.get();
}

bool Game::isGameLost() {
    if (player_->getMoney() == 0 || (gameDays_ - time_->getElapsedTime()) == 0) {
        printLoseScreen();
        return true;
    }
    return false;
}

void Game::printLoseScreen() {
    std::cout << "############################################################\n";
    std::cout << "#                                                          #\n";
    std::cout << "#                 UNFORTUNATELY YOU LOST                   #\n";
    std::cout << "#                                                          #\n";
    std::cout << "############################################################";
    std::cin.get();
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
    std::cout << "#" << std::setfill(' ')  << std::setw (21) << " 6. HIRE CREW" << std::setw (9) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (19) << " 7. EXIT" << std::setw (11) << "#\n";
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
    } while (isChoiceValid(option) == false);
    menuOption_ = static_cast<MenuOption>(option);
    return actionMenu(menuOption_);
}

Game::MenuOption Game::actionMenu(Game::MenuOption userAnswer) {
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
            menuOption_ = exitGame();
            break;
        default:
            std::cout << "Option doesn't exists\n";
    }
    return menuOption_;
}

bool Game::isChoiceValid(const size_t & option) { 

    if (std::cin.fail() || option < FIRST_OPTION_ELEMENT || option > LAST_OPTION_ELEMENT) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong value please insert number between " 
                  << FIRST_OPTION_ELEMENT << " and " << LAST_OPTION_ELEMENT << ".\n";
        return false;
    }
    return true;
}

Game::CheckAnswer Game::checkAnswer(const std::string & announcemen) {
    std::cout << announcemen << '\n';
    char answer;
    std::cin >> answer;
    if (answer == 'Y' || answer == 'y') {
        return CheckAnswer::Yes;
    }
    if (answer == 'N' || answer == 'n') {
        return CheckAnswer::No;
    }
    std::cout << "Wrong answer, you must choose Y or N\n";
    return CheckAnswer::Error;   
}

Game::MenuOption Game::exitGame() {
    while (true) {
        CheckAnswer exitAnswer = checkAnswer("Are you sure you wanna exit game? Y/N");
        if (exitAnswer == CheckAnswer::Yes) {
            return Game::MenuOption::Exit;
        }
        if (exitAnswer == CheckAnswer::No) {
            return Game::MenuOption::NoChoice;
        }
    }
}

void Game::travel() {
    /* 1. PRINT MAP AND SHOW POSITION
       2. PROMPT TO CHOOSE AN ISLAND IN LOOP
          - by number and return coordinates
          - or by coordinates
    */
    size_t coordX{};
    size_t coordY{};

    Island* destinationIsland = map_->getIsland(Island::Coordinates(coordX, coordY));
    if (destinationIsland) {
        const size_t distance{
            Island::Coordinates::distance(map_->getCurrentPosition()->getCoordinates(),
                                          destinationIsland->getCoordinates())
        };
        
        const size_t playerSpeed = player_->getSpeed();
        const size_t travelTime = (distance * 10) / playerSpeed;    // temporary magic value


        // TRAVEL INFO HERE (distance, speed)
        
        map_->setCurrentPosition(destinationIsland);

        // DESTINATION REACHED INFO HERE (island number, coordinates, travel time)
        
        for (size_t i = 0; i < travelTime; i++) {
            ++(*time_);
        }
        currentDay_ = time_->getElapsedTime();
    } else {
        // WRONG COORDINATES - LOOP CONTINUES
    }
    // LOOP EXITS
}

void Game::checkCargo() {

}

void Game::buy() {

}

void Game::sell() {

}
