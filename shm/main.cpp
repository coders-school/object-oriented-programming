#include "cargo.hpp"
#include "coordinates.hpp"
#include "island.hpp"
#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"

#include <iostream>
#include <memory>
#include <string>

int main() {
    Ship blackPearl(200, 50, 180, "black pearl", 1);
    std::unique_ptr<Ship> ptr = std::make_unique<Ship>(blackPearl);
    Player pawellos(std::move(ptr), 300, 70);
    std::cout << pawellos.getMoney() << "\n";
    std::cout << pawellos.getAvailableSpace() << "\n";
    std::cout << pawellos.getSpeed() << "\n";
    std::cout << blackPearl.getName() << "\n";
    std::cout << blackPearl.getId() << "\n";
    std::cout << blackPearl.getMaxCrew() << "\n";
    std::cout << blackPearl.getCapacity() << "\n \n";

    std::cout << blackPearl.getCrew() << "\n";
    blackPearl += 6;
    std::cout << blackPearl.getCrew() << "\n";
    blackPearl -= 3;
    std::cout << blackPearl.getCrew() << "\n";
    blackPearl -= 8;
    std::cout << blackPearl.getCrew() << "\n";

    Cargo Chocolate(5, "milka", 3);
    Cargo IceCream(6, "scholler", 8);

    std::cout << Chocolate.getName() << "\n";
    std::cout << Chocolate.getAmount() << "\n";
    std::cout << Chocolate.getBasePrice() << "\n";
    Chocolate += 7;
    std::cout << Chocolate.getAmount() << "\n";
    IceCream -= 4;
    std::cout << IceCream.getAmount() << "\n";

    blackPearl.addToCargo(Chocolate);
    blackPearl.addToCargo(IceCream);
    Cargo* ptr_ = blackPearl.getCargo(1);
    std::cout << ptr_->getName() << "\n";
    std::cout << blackPearl.getCargo(0)->getName() << "\n";

    for (const auto& element : blackPearl.getVectorCargo()) {
        std::cout << element.getName() << "\n";
    }

    Map mainMap;

    Coordinates location(1, 1);

    if (mainMap.getIsland(location)) {
        std::cout << "Island found!\n";
    }

    std::cout << pawellos.getAvailableSpace() << "\n";

    std::cout << pawellos.getShip()->getName() << "\n";
    pawellos.getShip()->addToCargo(Chocolate);
    std::cout << pawellos.getShip()->getCargo(0) << "\n";
    std::cout << pawellos.getCargo(0)->getName() << "\n";
    return 0;
}
