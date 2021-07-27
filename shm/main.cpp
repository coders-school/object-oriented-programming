#include "Cargo.hpp"
#include "Item.hpp"
#include "Fruit.hpp"
#include "DryFruit.hpp"
#include "Rarity.hpp"
#include "Ship.hpp"
#include "Player.hpp"
#include "Store.hpp"
#include "Coordinates.hpp"
#include <iostream>
#include <memory>
#include <utility>


int main(){
    Fruit bananas("Bananas",200, 40, 30 );
    Item swords("Sword", 1, 40, Rarity::common);
    DryFruit dryApples("dry apples",300, 40, 30 );


    std::unique_ptr<Ship> ship (new Ship(1000, 50, 10, "Karpaty", 1));
    Player player(ship, 40000); 
    auto player_ptr = &player;
    Store store; 
    store.printGoodsList();
    auto cargo_ptr = std::make_shared<Fruit>(bananas);
    auto cargo_ptr2 = std::make_shared<Item>(swords);
    store.buy(cargo_ptr.get(),100,player_ptr);
    //player.PurchaseCargo(cargo_ptr, 100 );
    //player.PurchaseCargo(cargo_ptr2, 100 );
    //ship->load(cargo_ptr);
    //ship->load(cargo_ptr2);
    //ship->printCargolist();
    player.printCargo();
    //std::cout<<player.getMoney();
    store.printGoodsList();

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