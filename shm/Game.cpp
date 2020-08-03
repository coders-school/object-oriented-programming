#include "Game.hpp"

#include <iostream>

constexpr size_t distancePerDay{2};

Game::Game(size_t money, size_t days, size_t final_goal)
    : money_(money), days_(days), final_goal_(final_goal) {}

bool Game::checkWinCondition() const {
    return (player_->getMoney() >= final_goal_);
}

bool Game::checkLoseCondition() const {
    return (player_->getMoney() == 0 || time_->getElapsedTime() == days_);
}

void Game::printTheEnd() const {
    std::cout <<
        "######## ##     ## ########    ######## ##    ## ######## " << "\n" << 
        "   ##    ##     ## ##          ##       ###   ## ##     ##" << "\n" <<  
        "   ##    ##     ## ##          ##       ####  ## ##     ##" << "\n" <<  
        "   ##    ######### ######      ######   ## ## ## ##     ##" << "\n" << 
        "   ##    ##     ## ##          ##       ##  #### ##     ##" << "\n" << 
        "   ##    ##     ## ##          ##       ##   ### ##     ##" << "\n" << 
        "   ##    ##     ## ########    ######## ##    ## ######## " << "\n";
}

void Game::printWinScreen() const {
    std::string horizontalSeparator(59, '=');
    int i = 0;
    std::cout << horizontalSeparator << "\n";
    printTheEnd();
    std::cout << horizontalSeparator << "\n"
              << std::string(4, ' ') 
              << "YOU WIN THE GAME AFTER " 
              << time_->getElapsedTime() 
              << " DAYS WITH SCORE " 
              << player_->getMoney() 
              << "\n"
              << std::string(20, ' ')
              << "CONGRATULATIONS" << "\n"
              << horizontalSeparator << "\n";
}

void Game::printLoseScreen() const {
    std::string horizontalSeparator(59, '=');
    int i = 0;
    std::cout << horizontalSeparator << "\n";
    printTheEnd();
    std::cout << horizontalSeparator << "\n"
              << std::string(4, ' ') 
              << "YOU LOSE THE GAME AFTER "
              << time_->getElapsedTime()
              << " DAYS WITH SCORE " 
              << player_->getMoney() 
              << "\n"
              << std::string(25, ' ')
              << "TRY AGAIN" << "\n"
              << horizontalSeparator << "\n";
}

void Game::Travel() {
    std::cout << *map_;
    auto destination = map_->getIsland(getTravelLocation());
    if (!destination) {
        return;
    }

    auto distance = map_->getDistanceToIsland(destination);
    map_->setCurrentPosition(destination);
    advanceTimeTraveling(distance);
}

Coordinates Game::getTravelLocation() {
    std::cout << "Type position X of an Island to travel to: ";
    size_t X{};
    std::cin >> X;
    std::cout << "\nType position Y of an Island to travel to: ";
    size_t Y{};
    std::cin >> Y;
    std::cout << "\n";

    return Coordinates(X, Y);
}

void Game::advanceTimeTraveling(size_t distance) {
    while (distance > 0) {
        distance -= distancePerDay;
        time_++;
    }
}

void Game::PrintOptions() {
    std::cout << "Ahoy captain! We're waiting for your commands! \n";
    std::cout << "1. Travel \n";
    std::cout << "2. Buy \n";
    std::cout << "3. Sell \n";
    std::cout << "0. Exit \n";
}

void Game::MakeAction(Action choice) {
    switch (choice) {
    case Action::Exit:
        Exit();
        break;
    case Action::Travel:
        Travel();
        break;
    case Action::Buy:
        Buy();
        break;
    case Action::Sell:
        Sell();
        break;
    default:
        break;
    }
}
