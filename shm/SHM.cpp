#include <cassert>

#include "Ship.hpp"
#include "Cargo.hpp"

int main() {
    Ship ship1;
    Ship ship2(10, 100, 500);
    Ship ship3(10, "Ala", 200, 600, 300);

    ship1 += 15;
    ship2 -= 40;

    Cargo flowerCargo, fruitCargo;

    assert(flowerCargo != fruitCargo);


    return 0;
}
