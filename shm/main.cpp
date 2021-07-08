#include "Player.hpp"
#include "Cargo.hpp"
#include "Map.hpp"
#include "Island.hpp"
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
    // RVO
    return ptr;
}

void testCargoShipPlayer() {
    constexpr size_t testCases {10};
    constexpr size_t testShipCapacity {100};
    std::vector<std::unique_ptr<Cargo>> cargoVec;
    cargoVec.reserve(testShipCapacity);
    for(size_t i = 0; i < testCases; ++i) {
        size_t cargoAmount = rand() % testShipCapacity;
        for(size_t i = 0; i < cargoAmount; ++i) {
            cargoVec.push_back(generateCargo());
        }
        auto pirateShip = std::make_unique<Ship>(testShipCapacity, 40, 10, "The Adventure Galley Pirate Ship", 0, std::move(cargoVec));
        cargoVec.clear();
        Player pirate(std::move(pirateShip), 1000);
        std::cout << "\n\n--- CARGO/SHIP/PLAYER TEST ---\n";
        pirate.printCargoManifest();
    }
}

void testIslandMap() {
    constexpr size_t testCases {10};
    for(size_t i = 0; i < testCases; ++i) {
        Map map;
        auto mapVec = map.getIslandVec();
        size_t num {1};
        std::cout << "\n\n--- MAP/ISLAND TEST ---\n";
        for(const auto& island : mapVec) {
            std::cout << num++ << ". ";
            std::cout << island->getPosition();
        }
    }
}

int main() {
    srand(time(0));
    testCargoShipPlayer();
    testIslandMap();
    return 0;
}
