#include <iomanip>
#include <iostream>
#include <memory>

#include "alcohol.hpp"
#include "cargo.hpp"
#include "game.hpp"
#include "fruit.hpp"
#include "island.hpp"
#include "item.hpp"
#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "store.hpp"
#include "time.hpp"

constexpr size_t start_money = 1'000'000;
constexpr size_t game_days = 100;
constexpr size_t final_goal = 2'000'000;

int main() {
   
    Game game(start_money, game_days, final_goal);
    game.startGame();
    
    return 0;
}
