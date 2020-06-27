#include "cargo.hpp"
#include "coordinates.hpp"
#include "island.hpp"
#include "map.hpp"
//#include "observer.hpp" not ready yet
#include "player.hpp"
#include "ship.hpp"
#include "time.hpp"

#include <iostream>
#include <memory>
#include <string>

void printTrail() {
    const std::string floor(50, '-');
    std::cout << floor << '\n';
}

int main() {
    printTrail();
    std::cout << "Test of SHM in main.cpp\n";
    Ship FD(100, 50, 12, "Flying Dutchman", 1);
    printTrail();
    std::cout << "Ship FD has been created: \n";
    printTrail();
    std::cout << "Capacity: " << FD.getCapacity() << '\n';
    std::cout << "Max crew: " << FD.getMaxCrew() << '\n';
    std::cout << "Speed: " << FD.getSpeed() << '\n';
    std::cout << "Name: " << FD.getName() << '\n';
    std::cout << "Id: " << FD.getId() << '\n';

    //std::unique_ptr<Ship> uPtrFD = std::make_unique<Ship>(FD);
    return 0;
}
