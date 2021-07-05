#include <exception>
#include <iostream>

#include "shm/inc/Alcohol.hpp"
#include "shm/inc/Fruit.hpp"
#include "shm/inc/Item.hpp"

int main() {
    Alcohol alcohol("Beer", 5, 19, 5);
    std::cout << "name: " << alcohol.getName() << '\n'
              << "amount: " << alcohol.getAmount() << '\n'
              << "base price: " << alcohol.getBasePrice() << '\n'
              << "price: " << alcohol.getPrice() << '\n'
              << "percentage: " << alcohol.getPercentage() << "\n\n";

    Item item("Diamond", 9, 99, Item::Rarity::epic);
    std::cout << "name: " << item.getName() << '\n'
              << "amount: " << item.getAmount() << '\n'
              << "base price: " << item.getBasePrice() << '\n'
              << "price: " << item.getPrice() << "\n\n";

    Fruit fruit("Apple", 7, 11);
    std::cout << "name: " << fruit.getName() << '\n'
              << "amount: " << fruit.getAmount() << '\n'
              << "base price: " << fruit.getBasePrice() << '\n'
              << "price: " << fruit.getPrice() << "\n\n";

    try {
        alcohol += 1000;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        item += 1000;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        fruit += 1000;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
