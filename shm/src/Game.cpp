#include "shm/inc/Game.hpp"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>

#include "shm/inc/Island.hpp"

namespace {
    constexpr size_t FIRST_OPTION_ELEMENT { 1 };
    constexpr size_t LAST_OPTION_ELEMENT { 7 };
}

Game::Game(size_t money, size_t gameDays, size_t finalGoal)
    : money_(money)
    , gameDays_(gameDays)
    , finalGoal_(finalGoal)  
{
    time_ = std::make_unique<Time>();
    map_ = std::make_unique<Map>();
    player_ = std::make_unique<Player>((std::make_unique<Ship>(1, 25, 100, nullptr)), 100, 10000);
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
    std::cout << "#" << std::setfill(' ')  << std::setw (22) << " 3. PRINT CARGO " << std::setw (8) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (19) << " 4. BUY " << std::setw (11) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (19) << " 5. SELL" << std::setw (11) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (21) << " 6. HIRE CREW" << std::setw (9) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (19) << " 7. EXIT" << std::setw (11) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (30) << "#\n";
    std::cout << "#" << std::setfill('-')  << std::setw (31) << "#\n\n";
}

void Game::printHeader() {
    std::cout << std::setw (99) << std::setfill('#') << "\n";
    std::cout << "#" << std::setfill(' ') << std::setw (97) << "#" << "\n";
    std::cout << "#" << std::setfill(' ') << std::setw (15) << "YOUR MONEY: " << std::setw (8) << std::setfill('0') << money_;
    std::cout << std::setfill(' ') << std::setw (30) << "YOUR GOAL: " << std::setw (8) << std::setfill('0') << finalGoal_;
    std::cout << std::setfill(' ') << std::setw (30) << "DAYS LEFT: " << std::setw (3) << std::setfill('0') 
              << gameDays_ - currentDay_ << std::setfill(' ') << std::setw (4) << "#" "\n";
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
    printHeader();
    printMenu();
    size_t option {};
    do {
        std::cout << "Please insert you choice: ";
        std::cin >> option;
    } while (!isChoiceValid(option));
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
        case MenuOption::PrintCargo :
            printCargo();
            break;
        case MenuOption::Buy :
            buy();
            break;
        case MenuOption::Sell :
            sell();
            break;
        case MenuOption::HireCrew :
            hireCrew();
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
    char answer = getchar();
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

void Game::printCargo() {

}

void Game::buy() {
    std::cout << "Cargo to buy in store:\n";
    // TODO: print store cargo
    
    std::string cargoName;
    size_t cargoAmount;
    Store::Response response;
    auto currentStore{ map_->getCurrentPosition()->getStore() };
    
    do {
        std::cout << "Input cargo name: ";
        std::cin >> cargoName;
        std::cout << "Input cargo amount: ";
        std::cin >> cargoAmount;

        if (std::cin.fail()) {
            std::cout << "Invalid amount!\n";
            std::cin.clear();
            continue;
        }

        Cargo* cargo{ currentStore->getCargo(cargoName) };
        if (cargo) {
            response = currentStore->buy(cargo, cargoAmount, player_.get());
            break;
        }
        std::cout << "No such cargo!" << std::endl;
    } while (true);

    switch (response) {
    case Store::Response::done:
        std::cout << "Bought " << cargoAmount << " of " << cargoName << '\n';
        break;
    case Store::Response::lack_of_cargo:
        std::cout << "There is no enough cargo to buy!\n";
        break;
    case Store::Response::lack_of_space:
        std::cout << "You do not have enough space on your ship!\n";
        break;
    case Store::Response::lack_of_money:
        std::cout << "You do not have enough money!\n";
        break;
    }
}

void Game::sell() {
    std::cout << "Cargo to sell:\n";
    // TODO: print ship cargo
        
     std::string cargoName;
     size_t cargoAmount;
     Store::Response response;
     auto currentStore{ map_->getCurrentPosition()->getStore() };

     do {
         std::cout << "Input cargo name: ";
         std::cin >> cargoName;
         std::cout << "Input cargo amount: ";
         std::cin >> cargoAmount;

         if (std::cin.fail()) {
             std::cout << "Invalid amount!\n";
             std::cin.clear();
             continue;
         }

         Cargo* cargo{ player_->getCargo(cargoName) };
         if (cargo) {
             response = currentStore->sell(cargo, cargoAmount, player_.get());
             break;
         }
         std::cout << "No such cargo!" << std::endl;
     } while (true);

    switch (response) {
    case Store::Response::done:
        std::cout << "Sold " << cargoAmount << " of " << cargoName << '\n';
        break;
    case Store::Response::lack_of_cargo:
        std::cout << "There is no enough cargo to sell!\n";
        break;
    case Store::Response::lack_of_space:
        std::cout << "There is no enough space in store!\n";
        break;
    case Store::Response::lack_of_money:
        std::cout << "You do not have enough money!\n";
        break;
    }
}

void Game::hireCrew() {
    size_t crewAmount{};
    std::cout << "Cost of crew is 1 coin\n";
    do {
        std::cout << "How many crew you wanna hire? ";
        std::cin >> crewAmount;
    } while (isCrewNumber(crewAmount));

    if (hasPlayerEnoughMoney(crewAmount)) {
        *(player_->getShip()) += crewAmount;
        std::cout << "You have employed " << crewAmount << " sailors\n";
    } else {
        std::cout << "You don't have enough money\n";
    }
}

bool Game::isCrewNumber(const size_t & crew) { 
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong value please insert number.\n";
        return false;
    }
    return true;
}

bool Game::hasPlayerEnoughMoney(const size_t & crew) {
    if (crew > player_->getMoney()) {
        return false;
    }
    return true;
}