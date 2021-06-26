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

    std::cout << Titanic.getCargo()[0]->getAmount() << std::endl;
    /*std::unique_ptr<Ship> Rudy102 = std::make_unique<Ship>(Titanic);
    Player Zdzichu(Rudy102, 170, 3);
    std::cout << Zdzichu.getShip()->getId() << "Utonął!";*/
}