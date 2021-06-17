#include "Player.hpp"
#include "Cargo.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <time.h>

// Return by value to give up ownership
std::unique_ptr<Cargo> generateCargo() {
    // https://portroyale3.fandom.com/wiki/Goods
    const std::vector<std::pair<std::string, size_t>> goods {
        {"Wood", 33},
        {"Adobe Bricks", 33},
        {"Wheat", 33},
        {"Fruits", 50},
        {"Corn", 50},
        {"Sugar", 50},
        {"Hemp", 50},
        {"Textiles", 150},
        {"Metal", 83},
        {"Cotton", 50},
        {"Metal Goods", 200},
        {"Dyes", 100},
        {"Coffee", 140},
        {"Cocao", 140},
        {"Tobacco", 100},
        {"Meat", 300},
        {"Clothing", 450},
        {"Ropes", 150},
        {"Rum", 267},
        {"Bread", 142},
    };
    auto randomNumber = rand() % goods.size();
    auto anotherRandomNumber = rand() % 99 + 1;
    auto ptr = std::make_unique<Cargo>(goods.at(randomNumber).first, anotherRandomNumber, goods.at(randomNumber).second);
    return std::move(ptr);
}

int main() {
    srand(time(0));
    constexpr size_t testCases {10};
    std::vector<std::unique_ptr<Cargo>> cargoVec;
    cargoVec.reserve(100);
    for(size_t i = 0; i < testCases; ++i) {
        for(size_t i = 0; i < rand() % 100; ++i) {
            cargoVec.push_back(generateCargo());
        }
        auto pirateShip = std::make_unique<Ship>(100, 40, 10, "The Adventure Galley Pirate Ship", 0, std::move(cargoVec));
        Player pirate(std::move(pirateShip), 1000);
        std::cout << "\n\n--- TEST CASE ---\n";
        pirate.printCargoManifest();
    }
    return 0;
}