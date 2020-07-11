#include "Game.hpp"
#include <iostream>

Game::Game(size_t money, size_t days, size_t final_goal)
    : money_(money), days_(days), final_goal_(final_goal) {}

bool Game::checkWinCondition() const {
    return (player_->getMoney() >= final_goal_);
}

bool Game::checkLoseCondition() const {
    return (player_->getMoney() == 0);
}

void Game::PrintOptions() {
    std::cout << "Ahoy captain! We're waiting for your commands! \n";
    std::cout << "0. Exit \n";
    std::cout << "1. Travel \n";
    std::cout << "2. Buy \n";
    std::cout << "3. Sell \n";
}

// void Game::MakeAction(Action choice) {
//     switch (choice) {
//         case Action::Exit:
//             Exit();
//             break;
//         case Action::Travel:
//             Travel();
//             break;
//         case Action::Buy:
//             Buy();
//             break;
//         case Action::Sell:
//             Sell();
//             break;
//         default:
//         break;        
//     }
// }
