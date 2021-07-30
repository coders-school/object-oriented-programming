#include "Game.hpp"

void testCargoShipPlayer();
void testIslandMap();
void testGetIsland();
void testDryFruit();
void testTime();
void timePassTest();

int main() {
    srand(static_cast<unsigned int>(time(0)));
    /*testCargoShipPlayer();
    testIslandMap();
    testGetIsland(),
    testDryFruit();
    testTime();
    timePassTest();*/

    Game game(start_money, game_days, final_goal);
    game.startGame();

    return 0;
}

void testCargoShipPlayer() {
    auto time = Time::getInstance();
    constexpr size_t testCases{10};
    constexpr Capacity testShipCapacity{100};
    std::vector<std::unique_ptr<Cargo>> cargoVec;
    cargoVec.reserve(testShipCapacity.value);
    for (size_t i = 0; i < testCases; ++i) {
        size_t cargoAmount = rand() % testShipCapacity.value;
        for (size_t i = 0; i < cargoAmount; ++i) {
            cargoVec.push_back(generateCargo());
        }
        auto pirateShip = std::make_unique<Ship>(std::move(cargoVec), testShipCapacity, Crew{40}, Speed{10}, "The Adventure Galley Pirate Ship");
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
        const auto& mapVec = map.getIslandVec();
        size_t num{1};
        std::cout << "\n\n--- MAP/ISLAND TEST ---\n";
        for (const auto& island : mapVec) {
            std::cout << num++ << ". ";
            std::cout << island->getPosition();
            if (map.getIsland(island->getPosition()) != nullptr) {
                std::cout << "^-Island exists\n";
            } else {
                std::cout << "^-Island does not exist\n";
            }
        }
    }
}

void testGetIsland() {
    Map map;
    Island::Coordinates FakeIsland = generatePosition();
    std::cout << "Island [0]:" << map.getIslandVec()[0]->getPosition();
    if (map.getIsland(map.getIslandVec()[0]->getPosition()) != nullptr) {
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

void testDryFruit() {
    DryFruit dryMango("mango", 10, 10, 10, 10);
    std::cout << dryMango.getName() << '\n';
}

void testTime() {
    auto time = Time::getInstance();
    CargoDefault cargo1{"Cargo1", 100, 100};
    CargoDefault cargo2{"Cargo2", 100, 100};
    CargoDefault cargo3{"Cargo2", 100, 100};
    Ship ship1{Capacity{100}, Crew{100}, Speed{100}, "Ship1"};
    Ship ship2{Capacity{100}, Crew{100}, Speed{100}, "Ship2"};
    Ship ship3{Capacity{100}, Crew{100}, Speed{100}, "Ship3"};
    Store store;
    time->nextDay();
}

void timePassTest() {
    auto time = Time::getInstance();
    CargoDefault cargo1{"Cargo1", 100, 100};
    CargoDefault cargo2{"Cargo2", 100, 100};
    DryFruit cargo3{"Mango", 100, 100, 3};
    Ship ship1{Capacity{100}, Crew{100}, Speed{100}, "Ship1"};
    Ship ship2{Capacity{100}, Crew{100}, Speed{100}, "Ship2"};
    Ship ship3{Capacity{100}, Crew{100}, Speed{100}, "Ship3"};
    Store store;
    time->nextDay();
}
