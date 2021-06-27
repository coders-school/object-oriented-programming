#include "ship.hpp"
#include "cargo.hpp"
#include "player.hpp"
#include "coordinates.hpp"
#include "island.hpp"
#include "Map.hpp"
#include <iostream>

int main()
{
    std::cout << "Test Cargo" << '\n';

    Cargo bananas("banany", 15, 150);
    Cargo kryptonite("banany", 15, 150);
    Cargo onion("cebula", 250, 1);
    std::cout << (onion == bananas) << " " << (bananas == kryptonite) << " " << (onion == kryptonite) << '\n';
    std::cout << bananas.getAmount() << " " << bananas.getBasePrice() << " " << bananas.getName() << "\n\n";

    std::cout << "Test islands" << '\n';

    Coordinates miami(125.f, 174.f);
    Coordinates breslau(180.f, 115.f);
    Coordinates chicago(125.f, 174.f);
    std::cout << (breslau == miami) << " " << (chicago == breslau) << " " << (miami == chicago) << "\n\n";

    std::cout << "Test ship" << '\n';

    Ship Titanic(20, 90, 1);
    Titanic.addCargo(&bananas);
    std::cout << "Vector size: " << Titanic.getCargo().size() << '\n';
    std::cout << "Titanic cargo: " << Titanic.getCargo()[0]->getName() << '\n';
    std::cout << Titanic.getCargo()[0]->getAmount() << '\n';

    auto ship = std::make_unique<Ship>(20, 1, 2, "titanic", 3);
    ship->addCargo(&bananas);
    size_t shipCargoSize = ship->getCargo().size();
    Player player(ship, 1, 1);
    
    std::cout << "Vector size: " << shipCargoSize << '\n';
    std::cout << "Player's ship speed: " << player.getShip()->getSpeed() << '\n';
    std::cout << "Player's ship cargo: " << player.getCargo(0)->getName() << '\n';
    std::cout << "Available space: " << player.getAvailableSpace() << "\n\n";

    std::cout << "Random islands positions: X | Y" << '\n';
    Map map;
    map.DebugPrintIsland();

    std::cout << '\n' << "Get miami position: X | Y" << '\n';
    map.addIsland(miami);
    Island *is = map.getIsland(miami);
    std::cout << is->getPosition().GetPositionX() << " | " << is->getPosition().GetPositionY();
    std::cout << '\n';
}
