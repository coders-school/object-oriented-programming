#include <time.h>
#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "Cargo.hpp"
#include "DefaultCargo.hpp"
#include "Island.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Store.hpp"
#include "Time.hpp"
#include "Warehouse.hpp"

struct GoodsData {
    constexpr GoodsData(const char* name)
        : name(name) {}
    constexpr GoodsData(const char* name, size_t value)
        : name(name), value(value) {}

    const char* name;
    size_t value = 0;
};

// Return by value to give up ownership
std::unique_ptr<Cargo> generateCargo() {
    // https://portroyale3.fandom.com/wiki/Goods
    constexpr std::array goods{
        GoodsData{"Wood", 33},
        GoodsData{"Adobe Bricks", 33},
        GoodsData{"Wheat", 33},
        GoodsData{"Fruits", 50},
        GoodsData{"Corn", 50},
        GoodsData{"Sugar", 50},
        GoodsData{"Hemp", 50},
        GoodsData{"Textiles", 150},
        GoodsData{"Metal", 83},
        GoodsData{"Cotton", 50},
        GoodsData{"Metal Goods", 200},
        GoodsData{"Dyes", 100},
        GoodsData{"Coffee", 140},
        GoodsData{"Cocao", 140},
        GoodsData{"Tobacco", 100},
        GoodsData{"Meat", 300},
        GoodsData{"Clothing", 450},
        GoodsData{"Ropes", 150},
        GoodsData{"Rum", 267},
        GoodsData{"Bread", 142},
    };
    auto randomCargo = rand() % goods.size();
    auto randomAmount = rand() % 99 + 1;
    auto good = goods[randomCargo];
    auto ptr = std::make_unique<CargoDefault>(good.name, randomAmount, good.value);
    return ptr;  // RVO
}

void testCargoShipPlayer() {
    Time* time = Time::getInstance();
    constexpr size_t testCases{10};
    constexpr size_t testShipCapacity{100};
    std::vector<std::unique_ptr<Cargo>> cargoVec;
    cargoVec.reserve(testShipCapacity);
    for (size_t i = 0; i < testCases; ++i) {
        size_t cargoAmount = rand() % testShipCapacity;
        for (size_t i = 0; i < cargoAmount; ++i) {
            cargoVec.push_back(generateCargo());
        }
        auto pirateShip = std::make_unique<Ship>(testShipCapacity, 40, 10, "The Adventure Galley Pirate Ship", 0, std::move(cargoVec));
        cargoVec.clear();
        Player pirate(std::move(pirateShip), 1000);
        std::cout << "\n\n--- CARGO/SHIP/PLAYER TEST ---\n";
        pirate.printCargoManifest();
        time->nextDay();
    }
}

void testIslandMap() {
    constexpr size_t testCases{10};
    for (size_t i = 0; i < testCases; ++i) {
        Map map;
        auto mapVec = map.getIslandVec();
        size_t num{1};
        std::cout << "\n\n--- MAP/ISLAND TEST ---\n";
        for (const auto& island : mapVec) {
            std::cout << num++ << ". ";
            std::cout << island.getPosition();
            if (map.getIsland(island.getPosition()) != nullptr) {
                std::cout << "^-Island exists\n";
            } else {
                std::cout << "^-Island does not exist\n";
            }
        }
    }
}
void testGetIsland(){
    Map map;
    Island::Coordinates FakeIsland(generatePosition(), generatePosition());
    std::cout << "Island [0]:" << map.getIslandVec()[0].getPosition();
    if (map.getIsland(map.getIslandVec()[0].getPosition()) != nullptr) {
        std::cout << "^-First Island exists\n";
    } else {
        std::cout << "^-First Island does not exist\n";
    }
    std::cout << "FakeIsland:" << FakeIsland;
    if (map.getIsland(FakeIsland) != nullptr) {
        std::cout << "^-Fake Island exists\n";
    } else {
        std::cout << "^-Fake Island does not exist\n";
    }
}

void testTime() {
    Time* time = Time::getInstance();
    CargoDefault cargo1{"Cargo1", 100, 100};
    CargoDefault cargo2{"Cargo2", 100, 100};
    CargoDefault cargo3{"Cargo2", 100, 100};
    Ship ship1{100, 100, 100, "Ship1", 1, {}};
    Ship ship2{100, 100, 100, "Ship2", 2, {}};
    Ship ship3{100, 100, 100, "Ship3", 3, {}};
    Store store;
    time->nextDay();
}

void timePassTest() {
    Time* time = Time::getInstance();
    CargoDefault cargo1{"Cargo1", 100, 100};
    CargoDefault cargo2{"Cargo2", 100, 100};
    CargoDefault cargo3{"Cargo2", 100, 100};
    Ship ship1{100, 100, 100, "Ship1", 1, {}};
    Ship ship2{100, 100, 100, "Ship2", 2, {}};
    Ship ship3{100, 100, 100, "Ship3", 3, {}};
    Store store;
    time->update();
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    testCargoShipPlayer();
    testIslandMap();
    testGetIsland(),
    testTime();
    timePassTest();
    return 0;
}
