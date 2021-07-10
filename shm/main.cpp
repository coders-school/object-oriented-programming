#include <iostream>
#include <memory>

#include "cargo.hpp"
#include "player.hpp"
#include "ship.hpp"

int main() {
    auto cargo1 = std::make_shared<Cargo>("cebula", 30, 2);
    auto cargo2 = std::make_shared<Cargo>("drewno", 10, 20);
    auto cargo3 = std::make_shared<Cargo>("wino", 10, 100);
    auto cargo4 = std::make_shared<Cargo>("miedz", 10, 1);
    auto cargo5 = std::make_shared<Cargo>("rubin", 10, 2);
    auto cargo6 = std::make_shared<Cargo>("cebula", 3, 10);
    auto cargo7 = std::make_shared<Cargo>("Woda", 200, 500);
    
    std::vector<std::shared_ptr<Cargo>> LOAD {cargo1, cargo2 , cargo3, cargo4, cargo5, cargo6, cargo7};  
    
    
    auto s1 = std::make_shared<Ship>(500, 20, 14, 5, "Black Widow", 1, LOAD);
    Player pla1(s1, 5000);
    std::cout << '\n';
    
    pla1.printCargo();

    return 0;
}