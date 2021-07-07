#include "shm/inc/Game.hpp"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>

#include "shm/inc/Ship.hpp"
#include "shm/inc/Island.hpp"

Game::Game(size_t money, size_t game_days, size_t final_goal)
    : money_(money)
    , game_days_(game_days)
    , final_goal_(final_goal)
    , time_(std::make_unique<Time>())
    , map_(std::make_unique<Map>())
{
    current_day_ = time_->getElapsedTime();
    ship_ = std::make_unique<Ship>(1, 25, 100, nullptr);
    player_ = std::make_unique<Player>(std::move(ship_), 100, 10000);
}

void Game::startGame() {
    printWelcomeScreen();
    printMap();
    // while (game_days_ > current_day_) {
    //     printMenu();  
    //     if (isGameWon()) {
    //         // YOU WON!
    //         return;
    //     }
    //     std::cin.get();
    //     // CONTUNUE GAME
    // }
    // YOU LOST!
}

bool Game::isGameWon() const {
    return player_->getMoney() >= final_goal_;
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


void Game::printMap() {
    int i{};
    for (const auto& island : map_->getIslands()) {
        std::cout << "Island no " << ++i 
                  << " ---- Coordinates [" << island.getCoordinates().getPositionX() 
                  << "][" << island.getCoordinates().getPositionY() << "]\n";
    }
}

void Game::selectOption() {
    printWelcomeScreen();
    printMenu();
    size_t option {};
    std::cin >> option;
    switch(option) {
    case 1:
        showMap();
        break;
    case 2:
        travel();
        break;
    case 3:
        checkCargo();
        break;
    case 4:
        buy();
        break;
    case 5:
        sell();
        break;
    case 6:
        exit(0);
    }
}

void Game::showMap() {

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
        current_day_ = time_->getElapsedTime();
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
