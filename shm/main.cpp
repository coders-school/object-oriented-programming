#include "Alcohol.hpp"
#include "Fruit.hpp"
#include <iostream>

size_t operator+(size_t sum, const std::shared_ptr<Cargo> & cargo){
    return sum + cargo->getAmount();
}

int main(){
    Fruit bananas("bananas",200, 40, 30 );
    ++bananas;
    std::cout<<bananas.gettimeInCargoRoom();
    return 0;
}