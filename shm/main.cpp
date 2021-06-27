#include "ship.hpp"
#include "cargo.hpp"
#include "player.hpp"
#include "coordinates.hpp"
#include "island.hpp"
#include "Map.hpp"
#include <iostream>

int main()
{
    Cargo bananas("banany", 15, 150);
    Cargo kryptonite("banany", 15, 150);
    Cargo onion("cebula", 250, 1);
    std::cout << (onion == bananas) << " " << (bananas == kryptonite) << " " << (onion == kryptonite) << std::endl;
    std::cout << bananas.getAmount() << " " << bananas.getBasePrice() << " " << onion.getName() << std::endl;

    Coordinates miami(125.f, 174.f);
    Coordinates breslau(180.f, 115.f);
    Coordinates chicago(125.f, 174.f);
    std::cout << (breslau == miami) << " " << (chicago == breslau) << " " << (miami == chicago) << std::endl;

    Ship Titanic(20, 90, 1);
    Titanic.addCargo(&bananas);
    std::cout << "Vector size: " << Titanic.getCargo().size() << '\n';
    std::cout << "Titanic cargo: " << Titanic.getCargo()[0]->getName() << '\n';

    std::cout << Titanic.getCargo()[0]->getAmount() << std::endl;
    // std::unique_ptr<Ship> Rudy102 = std::make_unique<Ship>();
    // Player Zdzichu(Rudy102, 170, 3);
    // std::cout << Zdzichu.getShip()->getId() << "Utonął!";
    auto ship = std::make_unique<Ship>(1, 2, 3);
    ship->addCargo(&bananas);
    Player player (ship, 1, 1);
    std::cout << "Vector size: " << ship->getCargo().size() << '\n';
    // std::cout << "Vector size: " << ship.get()->getCargo().size() << '\n'; //    std::cout << "Vector size: " << ship.get()->getCargo().size() << '\n';
    // std::cout << "Player's ship speed: " <<  player.getShip()->getSpeed() << '\n';
    // std::cout << "Player's ship cargo: " << player.getCargo(0)->getName() << '\n';
    
    Map map;
    map.DebugPrintIsland();
    
    map.addIsland(miami);
    Island* is = map.getIsland(miami);
    std::cout << is->getPosition().GetPositionX() << " " << is->getPosition().GetPositionY();
}