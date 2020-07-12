#include "Game.hpp"
#include <iostream>

constexpr size_t distancePerDay{2};

Game::Game(size_t money, size_t days, size_t final_goal)
    : money_(money), days_(days), final_goal_(final_goal) {}

bool Game::checkWinCondition() const {
    return (player_->getMoney() >= final_goal_);
}

bool Game::checkLoseCondition() const {
    return (player_->getMoney() == 0);
}

void Game::Travel() {
    std::cout << *map_; //unimplemented << operator for map
    auto destination = map_->getIsland(getTravelLocation());
    if(!destination) {
        return;
    }

    map_->setCurrentPosition(destination);
    auto distance = map_->getDistanceToIsland(destination);
    advanceTimeTraveling(distance);

}

Coordinates Game::getTravelLocation() {
    std::cout << "Type position X of an Island to travel to: "; //we assume that << operator will give Islands coords
    size_t X{};
    std::cin >> X;
    std::cout << "\nType position Y of an Island to travel to: ";
    size_t Y{};
    std::cin >> Y;
    std::cout <<"\n";

    return Coordinates(X, Y);
}

void Game::advanceTimeTraveling(size_t distance) {
    while(distance > 0) {
        distance -= distancePerDay;
        time_++;
        days_++;
    }
}