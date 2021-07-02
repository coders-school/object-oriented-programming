#include <iostream>
#include "cargo.hpp"
#include "ship.hpp"
#include "player.hpp"
#include <memory>
#include "alcohol.hpp"

int main() {

    Alcohol whisky(50, "wisky", 12, 13);
    // Ship testShip(5000, 50, 30, "Lover", 10);
    Ship Adam{};
    auto it = std::make_shared<Ship> (Adam);

    Player(it, 40000, 50000);

    
    
    
    
    
   
    return 0;
}