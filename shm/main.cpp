#include <cassert>

#include "Cargo.hpp"
#include "Ship.hpp"

int main() {
    Ship ship1;
    Ship ship2(10, 100, 500);
    Ship ship3(10, "Ala", 200, 600, 300);

    ship1 += 15;
    ship2 -= 40;

    Cargo flowerCargo{"Tulipan", 7, 50}, fruitCargo{"Truskawka", 5, 40};

    assert(flowerCargo != fruitCargo);

    return 0;
}
