#include "Cargo.hpp"
#include "Item.hpp"
#include "Fruit.hpp"
#include "Alcohol.hpp"
#include "DryFruit.hpp"
#include "Rarity.hpp"
#include "Ship.hpp"
#include "Player.hpp"
#include "Store.hpp"
#include "Coordinates.hpp"
#include <iostream>
#include <memory>
#include <utility>
#include "Time.hpp"


int main(){
    Fruit bananas("Bananas",200, 40, 30 );
    Item swords("Sword", 1, 40, Rarity::common);
    Alcohol rum("Rum", 50, 30, 96);
    DryFruit dryApples("dry apples",300, 40, 30 );


    std::unique_ptr<Ship> ship (new Ship(1000, 50, 10, "Karpaty", 1));
    Player player(ship, 40000); 
    auto player_ptr = &player;
    Store store; 
    //std::cout<< store;
    auto cargo_ptr = std::make_shared<Fruit>(bananas);
    auto cargo_ptr2 = std::make_shared<Item>(swords);
    auto cargo_ptr3 = std::make_shared<Alcohol>(rum);
    auto cargo_ptr4 = std::make_shared<DryFruit>(dryApples);
    //store.buy(cargo_ptr,100,player_ptr);
    //player.PurchaseCargo(cargo_ptr, 100 );
    //player.PurchaseCargo(cargo_ptr2, 100 );
    //ship->load(cargo_ptr);
    //ship->load(cargo_ptr2);
    //ship->printCargolist();
    //player.printCargo();
    //std::cout<<player.getMoney();
    //std::cout<< store;
    //store.sell(cargo_ptr,100,player_ptr);
    //player.printCargo();
    //std::cout<< store << "\n";
    std::cout<<cargo_ptr->gettimeInCargoRoom()<<"\n";
    std::cout<<cargo_ptr4->gettimeInCargoRoom()<<"\n";
    std::cout<<cargo_ptr3->getPrice()<<"\n";
    Time time;
    time.AddObserver(cargo_ptr);
    time.AddObserver(cargo_ptr2);
    time.AddObserver(cargo_ptr3);
    time.AddObserver(cargo_ptr4);
    ++time;
    ++time;
    ++time;
    ++time;
    ++time;
    ++time;
    std::cout<<cargo_ptr->gettimeInCargoRoom()<<"\n";
    std::cout<<cargo_ptr4->gettimeInCargoRoom()<<"\n";
    std::cout<<cargo_ptr3->getPrice()<<"\n";
    time.RemoveObserver(cargo_ptr);
    time.RemoveObserver(cargo_ptr2);
    time.RemoveObserver(cargo_ptr3);
    ++time;
    ++time;
    ++time;
    std::cout<<cargo_ptr->gettimeInCargoRoom()<<"\n";
    //std::cout<<player.getMoney();
    //ship->unload(cargo_ptr.get());
    //ship->printCargolist();
/*     constexpr size_t posx1 = 1; 
    constexpr size_t posy1 = 1;
    constexpr size_t posx2 = 5; 
    constexpr size_t posy2 = 5;   */
    //constexpr Coordinates point1(1,1);
    //constexpr Coordinates point2(5,5);
    //std::cout<<Coordinates::distance(point1,point2);
    return 0;
}