
#include <iostream>
#include <memory>

#include "alcohol.hpp"
#include "cargo.hpp"
#include "coordinates.hpp"
#include "dryfruit.hpp"
#include "fruit.hpp"
#include "island.hpp"
#include "item.hpp"
#include "Map.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "Storable.hpp"
#include "Store.hpp"

//Klasy użytkujące cargo:
//1.Store
//2.Storable
//3.Ship
//4.player


int main()
{
    /*
    std::cout << "Test Cargo" << '\n';

    Fruit banana(150, "banany", 3, 150, 1); // Fruit(size_t amount, const std::string& name, size_t base_price, size_t expiry_date, size_t time_elapsed);
    Alcohol kryptonite(200, "krypton", 20, 69); //  Alcohol(size_t amount, const std::string& name, size_t base_price, size_t percentage);
    Fruit onion(200, "cebula", 1, 100, 1); // Fruit(size_t amount, const std::string& name, size_t base_price, size_t expiry_date, size_t time_elapsed);
    Item hook(5, "Hak", 100, Item::Rarity::common);//(size_t amount, const std::string &name, size_t base_price, Rarity rarity)
    std::cout << (onion == banana) << " " << (banana == kryptonite) << " " << (onion == kryptonite) << "\n";
    std::cout << banana.getAmount() << " " << banana.getBasePrice() << " " << banana.getName() << "\n\n";
    std::cout << hook.getName() << " " << static_cast<int>(hook.getRarity()) << '\n';
   
    std::cout << "Test islands" << '\n';

    Coordinates miami(125.f, 174.f);
    Coordinates breslau(180.f, 115.f);
    Coordinates chicago(125.f, 174.f);
    std::cout << (breslau == miami) << " " << (chicago == breslau) << " " << (miami == chicago) << "\n\n";

    std::cout << "Test ship Titanic" << '\n';
     
    //Ship Titanic(20, 90, 1);// Ship(int maxCrew, int speed, size_t id)
    //std::shared_ptr<Cargo> ptr = static_cast<std::shared_ptr<Cargo>>(&kryptonite);
    //std::shared_ptr<Cargo> ptr = std::make_shared<Alcohol>(100, "Whiskey", 50, 40);
    //Titanic.load(static_cast<std::shared_ptr<Cargo>>(&kryptonite));

    // std::cout << "Vector size: " << Titanic.getCargo().size() << '\n';
    // std::cout << "Titanic cargo: " << Titanic.getCargo()[0]->getName() << '\n';
    // std::cout << Titanic.getCargo()[0]->getAmount() << "\n\n";
    
    std::cout << "Test make_unique ptr ship" << '\n';
    auto ship = std::make_unique<Ship>(20, 1, 2, "titanic", 3);
    ship->load(std::make_shared<Cargo>(banana));
    size_t shipCargoSize = ship->getCargo().size();
    Player player(std::move(ship), 100, 1);
    std::cout << "Vector size: " << shipCargoSize << '\n';
    std::cout << "Player's ship speed: " << player.getShip()->getSpeed() << '\n';
    std::cout << "Player's ship cargo name: " << player.getCargo(0)->getName() << '\n';
    std::cout << "Player's ship cargo (should be 15): " << player.getCargo(0)->getAmount() << '\n';
    std::cout << "Player's ship cargo base price: " << player.getCargo(0)->getBasePrice() << '\n';
    
    std::cout << "Available space: " << player.getAvailableSpace() << "\n\n";

    // std::cout << "Random islands positions: X | Y" << '\n';
    // Map map;
    // map.DebugPrintIsland();

    // std::cout << '\n' << "Get miami position: X | Y" << '\n';
    // map.addIsland(miami);
    // Island *is = map.getIsland(miami);
    // std::cout << is->getPosition().GetPositionX() << " " << is->getPosition().GetPositionY() << '\n';

    // std::cout << "Test Store" << '\n';
    // Store store(100, 500); //(Money, Avalivable space)
    // store.cargo_.push_back(std::make_shared<Cargo>(banana));
    // store.cargo_.push_back(std::make_shared<Cargo>(kryptonite));
    // std::cout << store.findMatchCargo(&banana) << " adres cotton: " << store.cargo_[0].get() <<'\n';
    // store.sell(&onion, 5, &player);
    // store.sell(&onion, 55, &player);
    // std::cout << "Prit store cargo" << '\n';
    // store.printStoreCargo();


    // //ZAD3 NEXT_DAY
    // std::cout << "\n\nZAD3 NEXT_DAY"<< '\n';
    // Ship* ownedShip = new Ship(5, 10, 2, "Special owned ship", 88);
    // ownedShip->setOwner(&player);
    // ownedShip->setCrew(5);
    // std::cout << "Player's money: " << player.getMoney() << '\n';
    // ownedShip->nextDay();
    // std::cout << "Player's money: " << player.getMoney() << '\n';
    // std::cout << "Prit store cargo" << '\n';
    // store.printStoreCargo();
    // store.nextDay();
    // std::cout << "Prit store cargo" << '\n';
    // store.printStoreCargo();
    */
   auto StatekTester = std::make_unique<Ship>(20, 1, 2, "titanic", 3);
   Player Tester(std::move(StatekTester),20,100);
   Store sklep(20, 100);
   std::cout << sklep.getAvailableSpace() << '\n';
   sklep.printStoreCargo();

}