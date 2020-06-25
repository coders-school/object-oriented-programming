#include <iostream>
#include "cargo.hpp"

int main() {
    Cargo c1("cargo", 100, 100);

    std::cout << c1.getAmount() << '\n';

    c1 -= 80;
    std::cout << c1.getAmount() << '\n';
    return 0;
}
