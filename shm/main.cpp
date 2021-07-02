#include <iostream>
#include "cargo.hpp"
#include "ship.hpp"
#include "player.hpp"
#include <memory>
//#include "alcohol.hpp"

int main() {

    
    // Ship testShip(5000, 50, 30, "Lover", 10);
    auto pirateShip = std::make_shared<Ship>(500, 10, 1, "Monica", 2 );
    

    Player Tomek(pirateShip, 40000);

    
    std::cout << Tomek.getAvailableSpace();
    
    
    
   
    return 0;
}