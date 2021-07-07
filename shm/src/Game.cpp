#include "shm/inc/Game.hpp"
#include "shm/inc/Ship.hpp"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>

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
    // mapGenerate();
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

// void Game::mapGenerate() {
//     size_t index = 1;
//     for (size_t i = 0; i <= COORDINATE_MAX; i++) {
//         for (size_t j = 0; j <= COORDINATE_MAX; j++) {
//             if (map_->getIsland(Island::Coordinates(i, j)) != nullptr) {
//                 island.insert({index, std::make_pair(i, j)});
//                 index++;
//             }
//         }
//     }
// }

void Game::printMap() {
    int i{};
    for (const auto& island : map_->getIslands()) {
        std::cout << "Island no " << ++i 
                  << " ---- Coordinates [" << island.getCoordinates().getPositionX() 
                  << "][" << island.getCoordinates().getPositionY() << "]\n";
    }
}
