#include <iostream>
#include "cargo.hpp"
#include "ship.hpp"
#include "player.hpp"

int main() {

    Cargo testCargo("test cargo", 12, 13);
    Ship testShip(5000, 50, 30, "Lover", 10);
    
    Player Wojtek(testShip, 10, 20000);
   

    

    return 0;
}