#include <iostream>

#include "Command.hpp"
#include "locators.hpp"
#include "Travel.hpp"
#include "alcohol.hpp"
#include "cargo.hpp"
#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"

int main() {
    Player player_one(100);
    Map map_one;
    Travel our_travel(&map_one, TimeServiceLocator::getTime());
    our_travel.execute(&player_one);
    return 0;
}
