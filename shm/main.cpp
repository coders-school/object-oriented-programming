#include "Item.hpp"
#include "Fruit.hpp"
#include "Rarity.hpp"
#include <iostream>

size_t operator+(size_t sum, const std::shared_ptr<Cargo> & cargo){
    return sum + cargo->getAmount();
}

int main(){
    Fruit bananas("bananas",200, 40, 30 );
    ++bananas;
    std::cout<<bananas.gettimeInCargoRoom();
    Item item("sword", 1, 40, Rarity::common);
    std::cout<<static_cast<int>(item.getRarity());
    return 0;
}