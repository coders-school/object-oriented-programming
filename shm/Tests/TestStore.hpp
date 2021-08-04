#pragma once

#include "Store.hpp"

template <typename T>
void fillWithGeneratedData(T* container) {  //use T::load !!! Test it first
    if (!container) {
        return;
    }

    for (size_t i = 0; i < cargoTypes; ++i) {
        auto cargo = generateCargo(i);
        container->load(std::move(cargo));
    }
}

//Store::load tests

TEST_CASE("load will ignore nullptr", "[Store]") {
    Store store;
    auto emptyCargo = std::unique_ptr<Cargo>();

    store.load(std::move(emptyCargo));

    REQUIRE(store.getCargoNum() == 0);
}

TEST_CASE("load will insert cargo", "[Store]") {
    Store store;
    fillWithGeneratedData(&store);

    REQUIRE(store.getCargoNum() == cargoTypes);
}

TEST_CASE("load will increase amount of same cargo", "[Store]") {
    Store store;

    auto cargo = generateCargo(cargoDefaultIndex);
    store.load(std::move(cargo));
    cargo = generateCargo(cargoDefaultIndex);
    store.load(std::move(cargo));

    cargo = generateCargo(cargoDefaultIndex);
    Cargo* cargoIn = store.findCargoInStore(cargo.get());
    REQUIRE(cargoIn->getAmount() == (2 * fullQuantity));
}

Cargo* getStoreCargo(const Store& store, const std::string& cargoName, size_t amount) {  //use Store::findCargoInStore !!! Test it first
    CargoDefault exemplar{cargoName, amount, singleCargoCost};
    auto cargoPtr = store.findCargoInStore(&exemplar);
    if (cargoPtr) {
        std::cout << "Found: " << cargoPtr->getName() << '\n';
        return cargoPtr;
    }
    std::cout << "Not Found: " << cargoName << '\n';
    return nullptr;
}

//Store::findCargoInStore tests

TEST_CASE("findCargoInStore by nullptr", "[Store]") {
    Store store;
    fillWithGeneratedData(&store);
    auto noExisting = store.findCargoInStore(nullptr);
    REQUIRE(!noExisting);
}

TEST_CASE("findCargoInStore by noExistingCargoName", "[Store]") {
    Store store;
    fillWithGeneratedData(&store);
    auto noExisting = getStoreCargo(store, noExistingCargoName, fullQuantity);
    REQUIRE(!noExisting);
}

TEST_CASE("findCargoInStore by existingCargoName", "[Store]") {
    Store store;
    fillWithGeneratedData(&store);
    auto existing = getStoreCargo(store, existingCargoName, fullQuantity);
    REQUIRE(existing);
}

TEST_CASE("findCargoInStore by exemplar Cargo no meter of quantity to search", "[Store]") {
    Store store;
    fillWithGeneratedData(&store);

    auto existing1 = getStoreCargo(store, existingCargoName, moreThanFullQuantity);
    auto existing2 = getStoreCargo(store, existingCargoName, fullQuantity);
    auto existing3 = getStoreCargo(store, existingCargoName, halfQuantity);
    auto existing4 = getStoreCargo(store, existingCargoName, 0);

    REQUIRE(existing1);
    REQUIRE(existing2);
    REQUIRE(existing3);
    REQUIRE(existing4);
}

/*TEST_CASE("findCargoInStore will ignore own Cargo ptr", "[Store]") {
    Store store;
    fillWithGeneratedData(&store);

    auto existing = getStoreCargo(store, existingCargoName, fullQuantity);
    auto selfCargo = store.findCargoInStore(existing);

    REQUIRE(!selfCargo);
}*/

//Store::unload tests

TEST_CASE("unload will ignore nullptr", "[Store]") {
    Store store;
    fillWithGeneratedData(&store);

    REQUIRE_NOTHROW(store.unload(nullptr));
}

TEST_CASE("unload will throw on wrong ptr", "[Store]") {
    Store store;
    fillWithGeneratedData(&store);

    CargoDefault exemplar{noExistingCargoName, fullQuantity, singleCargoCost};

    REQUIRE_THROWS(store.unload(&exemplar));
    REQUIRE_THROWS_AS(store.unload(&exemplar), std::logic_error);
    REQUIRE_THROWS_WITH(store.unload(&exemplar), "Store: Not my Cargo!");
}

TEST_CASE("unload will remove cargo", "[Store]") {
    Store store;
    fillWithGeneratedData(&store);

    auto num_of_cargo_before = store.getCargoNum();

    auto existing = getStoreCargo(store, existingCargoName, fullQuantity);
    store.unload(existing);
    auto noExistNow = getStoreCargo(store, existingCargoName, fullQuantity);

    auto num_of_cargo_after = store.getCargoNum();

    REQUIRE(!noExistNow);
    REQUIRE(num_of_cargo_before == num_of_cargo_after + 1);
}

//Store::buy tests

TEST_CASE("no player to sell to empty store", "[Store][buy]") {
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.buy(cargoExample.get(), fullQuantity, nullptr);

    REQUIRE(response == Response::lack_of_cargo);
}

TEST_CASE("player sell without ship to empty store", "[Player][Store][buy]") {  //use Player and Ship
    auto ship = std::unique_ptr<Ship>{};
    Player player(std::move(ship), playerMoney);
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.buy(cargoExample.get(), fullQuantity, &player);

    REQUIRE(response == Response::lack_of_cargo);
}

TEST_CASE("player sell noexisting cargo to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.buy(cargoExample.get(), fullQuantity, &player);

    REQUIRE(response == Response::lack_of_cargo);
}

TEST_CASE("player sell more of single cargo than have to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    fillWithGeneratedData(player.getShip());
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.buy(cargoExample.get(), moreThanFullQuantity, &player);

    REQUIRE(response == Response::lack_of_cargo);
    REQUIRE(player.getAvailableSpace() == 0);
    REQUIRE(store.getCargoNum() == 0);

    for (const auto& cargo : player.getShip()->getCargoVec()) {
        REQUIRE(cargo->getAmount() == fullQuantity);
    }
}

template <typename T>
void printCargo(const T& container) {
    for (const auto& cargo : container) {
        std::cout << std::setw(20) << std::left << cargo->getName()
                  << ":" << std::setw(5) << cargo->getAmount()
                  << ":" << std::setw(5) << cargo->getPrice() << '\n';
    }
}

TEST_CASE("player sell half of single cargo than have to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    fillWithGeneratedData(player.getShip());
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.buy(cargoExample.get(), halfQuantity, &player);

    REQUIRE(response == Response::done);
    REQUIRE(player.getAvailableSpace() == 0);
    REQUIRE(store.getCargoNum() == 1);

    std::cout << "Ship Cargo: \n";
    printCargo(player.getShip()->getCargoVec());
    for (const auto& cargo : player.getShip()->getCargoVec()) {
        if (*cargo == *cargoExample) {
            REQUIRE(cargo->getAmount() == halfQuantity);
            continue;
        }
        REQUIRE(cargo->getAmount() == fullQuantity);
    }
}

TEST_CASE("player sell full of single cargo to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    fillWithGeneratedData(player.getShip());
    Store store;

    auto cargoExample = generateCargo(alcoholIndex);
    auto response = store.buy(cargoExample.get(), fullQuantity, &player);

    REQUIRE(response == Response::done);
    REQUIRE(player.getAvailableSpace() == 1);
    REQUIRE(store.getCargoNum() == 1);

    std::cout << "Ship Cargo: \n";
    printCargo(player.getShip()->getCargoVec());
    for (const auto& cargo : player.getShip()->getCargoVec()) {
        REQUIRE(cargo->getAmount() == fullQuantity);
        REQUIRE_FALSE(*cargo == *cargoExample);
    }

    std::cout << "Store Cargo: \n";
    printCargo(store.getCargoVec());
    for (const auto& cargo : store.getCargoVec()) {
        REQUIRE(cargo->getAmount() == fullQuantity);
        REQUIRE(*cargo == *cargoExample);
    }
}

TEST_CASE("player sell full of all cargo to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    fillWithGeneratedData(player.getShip());

    REQUIRE(player.getAvailableSpace() == 0);

    Store store;

    for (size_t i = 0; i < cargoTypes; ++i) {
        auto cargoExample = generateCargo(i);
        auto response = store.buy(cargoExample.get(), fullQuantity, &player);
        REQUIRE(response == Response::done);
    }

    REQUIRE(player.getAvailableSpace() == fullCappacity);
    REQUIRE(store.getCargoNum() == fullCappacity);

    std::cout << "Store Cargo: \n";
    printCargo(store.getCargoVec());
    for (const auto& cargo : store.getCargoVec()) {
        REQUIRE(cargo->getAmount() == fullQuantity);
    }
}

//Store::sell tests

TEST_CASE("no player to buy from empty store", "[Store][sell]") {  //use Player and Ship
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.sell(cargoExample.get(), fullQuantity, nullptr);

    REQUIRE(response == Response::lack_of_space);
}

TEST_CASE("rich player buy without ship from empty store", "[Player][Store][sell]") {  //use Player and Ship
    auto ship = std::unique_ptr<Ship>{};
    Player player(std::move(ship), playerMoney);
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.sell(cargoExample.get(), fullQuantity, &player);

    REQUIRE(response == Response::lack_of_space);
}

TEST_CASE("rich player with empty ship buy noexisting cargo from empty store", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.sell(cargoExample.get(), fullQuantity, &player);

    REQUIRE(response == Response::lack_of_cargo);
}

TEST_CASE("rich player with empty ship buy more of single cargo than store have", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    Store store;
    fillWithGeneratedData(&store);

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.sell(cargoExample.get(), moreThanFullQuantity, &player);

    std::cout << "\nShip Cargo: \n";
    printCargo(player.getShip()->getCargoVec());
    std::cout << "Store Cargo: \n";
    printCargo(store.getCargoVec());

    REQUIRE(response == Response::lack_of_cargo);
}

TEST_CASE("rich player with empty ship buy half of single cargo than store have", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    Store store;
    fillWithGeneratedData(&store);

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.sell(cargoExample.get(), halfQuantity, &player);

    std::cout << "\nShip Cargo: \n";
    printCargo(player.getShip()->getCargoVec());
    std::cout << "Store Cargo: \n";
    printCargo(store.getCargoVec());

    REQUIRE(response == Response::done);
    REQUIRE(player.getAvailableSpace() == fullCappacity - 1);
    REQUIRE(store.getCargoNum() == cargoTypes);
}

TEST_CASE("rich player with empty ship buy full of single cargo from empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    Store store;
    fillWithGeneratedData(&store);

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.sell(cargoExample.get(), fullQuantity, &player);

    std::cout << "\nShip Cargo: \n";
    printCargo(player.getShip()->getCargoVec());
    std::cout << "Store Cargo: \n";
    printCargo(store.getCargoVec());

    REQUIRE(response == Response::done);
    REQUIRE(player.getAvailableSpace() == fullCappacity - 1);
    REQUIRE(store.getCargoNum() == cargoTypes - 1);
}

TEST_CASE("rich player with empty ship with enough capacity buy full of all cargo from store", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);

    REQUIRE(player.getAvailableSpace() == fullCappacity);

    Store store;
    fillWithGeneratedData(&store);

    for (size_t i = 0; i < cargoTypes; ++i) {
        auto cargoExample = generateCargo(i);
        auto response = store.sell(cargoExample.get(), fullQuantity, &player);
        REQUIRE(response == Response::done);
        player.income(fullQuantity * cargoExample->getPrice());//give back money that player pay for cargo
    }

    std::cout << "\nShip Cargo: \n";
    printCargo(player.getShip()->getCargoVec());
    std::cout << "Store Cargo: \n";
    printCargo(store.getCargoVec());

    REQUIRE(player.getAvailableSpace() == 0);
    REQUIRE(store.getCargoNum() == 0);
}

TEST_CASE("rich player with empty ship with enough capacity buy half of all cargo from store", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);

    REQUIRE(player.getAvailableSpace() == fullCappacity);

    Store store;
    fillWithGeneratedData(&store);

    for (size_t i = 0; i < cargoTypes; ++i) {
        auto cargoExample = generateCargo(i);
        auto response = store.sell(cargoExample.get(), halfQuantity, &player);
        REQUIRE(response == Response::done);
    }

    std::cout << "\nShip Cargo: \n";
    printCargo(player.getShip()->getCargoVec());
    std::cout << "Store Cargo: \n";
    printCargo(store.getCargoVec());

    REQUIRE(player.getAvailableSpace() == 0);
    REQUIRE(store.getCargoNum() == fullCappacity);
}

TEST_CASE("rich player with empty ship with enough capacity buy random of all cargo from store", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);

    REQUIRE(player.getAvailableSpace() == fullCappacity);

    Store store;
    fillWithGeneratedData(&store);

    std::array<size_t, cargoTypes> randomQuantity;

    for (size_t i = 0; i < cargoTypes; ++i) {
        randomQuantity[i] = rand() % 100 + 1;
        auto cargoExample = generateCargo(i);
        auto response = store.sell(cargoExample.get(), randomQuantity[i], &player);
        REQUIRE(response == Response::done);
    }

    std::cout << "\nShip Cargo: \n";
    printCargo(player.getShip()->getCargoVec());
    std::cout << "Store Cargo: \n";
    printCargo(store.getCargoVec());

    const auto& shipCargo = player.getShip()->getCargoVec();
    const auto& storeCargo = store.getCargoVec();
    REQUIRE(shipCargo.size() == storeCargo.size());
    for (size_t i = 0; i < cargoTypes; ++i) {
        REQUIRE(storeCargo[i]->getAmount() == fullQuantity - randomQuantity[i]);
        REQUIRE(shipCargo[i]->getAmount() == randomQuantity[i]);
    }

    REQUIRE(player.getAvailableSpace() == 0);
    REQUIRE(store.getCargoNum() == fullCappacity);
}
