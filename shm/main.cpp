#include "Cargo.hpp"
#include "Item.hpp"
#include "Fruit.hpp"
#include "DryFruit.hpp"
#include "Rarity.hpp"
#include "Ship.hpp"
#include "Player.hpp"
#include "Coordinates.hpp"
#include <iostream>
#include <memory>
#include <utility>


int main(){
    Fruit bananas("bananas",200, 40, 30 );
    Item swords("sword", 1, 40, Rarity::common);
    DryFruit dryApples("dry apples",300, 40, 30 );


    std::unique_ptr<Ship> ship (new Ship(1000, 50, 10, "Karpaty", 1));
    //Player player(ship, 1000, 1000); 
    auto cargo_ptr = std::make_shared<Fruit>(bananas);
    auto cargo_ptr2 = std::make_shared<Item>(swords);

    ship->load(cargo_ptr);
    ship->load(cargo_ptr2);
    //ship->printCargolist();
    //player.printCargo();
    ship->unload(cargo_ptr.get());
    //ship->printCargolist();
/*     constexpr size_t posx1 = 1; 
    constexpr size_t posy1 = 1;
    constexpr size_t posx2 = 5; 
    constexpr size_t posy2 = 5;   */
    constexpr Coordinates point1(1,1);
    constexpr Coordinates point2(5,5);
    std::cout<<Coordinates::distance(point1,point2);
    return 0;
}