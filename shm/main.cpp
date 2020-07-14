#include "Ship.hpp"

#include <iostream>

int main() {
    Ship ship1(10, 15, 20, "ship1", 1);
    std::cout << "ship1 capacity: " << ship1.getCapacity() << '\n';
    return 0;
}