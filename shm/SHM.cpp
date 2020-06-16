#include "Ship.hpp"

int main() {
    Ship ship1;
    Ship ship2(10, 100, 500);
    Ship ship3(10, "Ala", 200, 600, 300);

    ship1 += 15;
    ship2 -= 40;

    return 0;
}
