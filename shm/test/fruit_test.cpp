#include <iostream>

#include "../inc/fruit.hpp"
#include "../inc/island.hpp"
#include "../inc/map.hpp"

void ItemClassTest();
void FruitClassTest();
void MapClassTest();

int main() {
    FruitClassTest();

    return 0;
}

void FruitClassTest() {
    Fruit orange("orange", 3, 5, 10);
    Fruit apple("apple", 2, 5, 20);
    Fruit fruit("apple", 2, 5, 20); // name, amount, base price, time to spoil

    std::cout << "Name: " << apple.getName() << '\n';
    std::cout << "Amount: " << apple.getAmount() << '\n';
    std::cout << "Base price: " << apple.getBasePrice() << '\n';
    std::cout << "Price: " << apple.getPrice() << '\n';
    
    if (fruit == apple) {
        std::cout << "Apple is fruit" << '\n';
    }
    if (orange != apple) {
        std::cout << "Apple isn't orange" << '\n';
    }

    apple += 10;
    std::cout << "Amount inc: " << apple.getAmount() << '\n';
    apple -= 10;
    std::cout << "Amount dec: " << apple.getAmount() << '\n';
    
    --apple;
    apple--;
    std::cout << "Spoil: " << apple.getTimeToSpoilLeft() << '\n';
    std::cout << "Price: " << apple.getPrice() << "\n\n";
}
