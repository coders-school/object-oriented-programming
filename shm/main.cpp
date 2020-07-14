#include "Cargo.hpp"
#include "Ship.hpp"

#include <iostream>

int main() {
    Ship ship1(10, 15, 20, "ship1", 1);
    std::cout << "ship1 capacity: " << ship1.getCapacity() << '\n';

    Cargo cargo1("banany", 100, 20);
    std::cout << "cargo1 name: " << cargo1.getName() << '\n';

    return 0;
}