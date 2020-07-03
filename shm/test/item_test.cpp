// driver for testing Item class
// please compile with item.cpp

#include <iostream>

#include "../inc/item.hpp"

void ItemClassTest();
void FruitClassTest();
void MapClassTest();

int main() {
    ItemClassTest();

    return 0;
}

void ItemClassTest() {
    Item emerald("emerald", 2, 20, Item::Rarity::rare);
    Item diamond("diamond", 7, 40, Item::Rarity::epic);
    Item item("diamond", 7, 40, Item::Rarity::epic); // name, amount, price, rarity

    std::cout << "Name: " << diamond.getName() << '\n';
    std::cout << "Amount: " << diamond.getAmount() << '\n';
    std::cout << "Base price: " << diamond.getBasePrice() << '\n';
    std::cout << "Price: " << diamond.getPrice() << '\n';
    std::cout << "Base price: " << emerald.getBasePrice() << '\n';
    std::cout << "Price: " << emerald.getPrice() << '\n';
    
    if (item == diamond) {
        std::cout << "Diamond is item" << '\n';
    }
    if (emerald != diamond) {
        std::cout << "Diamond isn't emerald" << '\n';
    }

    diamond += 10;
    std::cout << "Amount inc: " << diamond.getAmount() << '\n';
    diamond -= 10;
    std::cout << "Amount dec: " << diamond.getAmount() << "\n\n";
}
