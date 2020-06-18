#include "cargo.hpp"
#include "coordinates.hpp" 
#include "island.hpp" 
#include "map.hpp" 
#include "ship.hpp"
#include "player.hpp"

#include <iostream>
#include <string>

int main() {
    std::cout<<"SHM\n";
    Map mainMap;

    Coordinates location(1,1);

    if(mainMap.getIsland(location)){
        std::cout<<"Island found!\n";   
    }

    


    return 0;
}
