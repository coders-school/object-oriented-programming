#include "game.hpp"

constexpr size_t START_MONEY = 500;
constexpr size_t GAME_DAYS = 20;
constexpr size_t FINAL_GOAL = 5000;


int main() {
    Time time;
    std::shared_ptr<Time> time_ptr = std::make_shared<Time>(time);
    Ship ship;
    std::shared_ptr<Ship> ship_ptr = std::make_shared<Ship>(ship);

    Game game(START_MONEY, GAME_DAYS, FINAL_GOAL, time_ptr, ship_ptr);
    game.startGame();
    
    return 0;
}
