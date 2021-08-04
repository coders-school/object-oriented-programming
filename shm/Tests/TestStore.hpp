#pragma once

#include <iomanip>
#include "Store.hpp"
#include "Warehouse.hpp"

//Store::load tests

void fillWithGeneratedData(Warehouse* container) {  //use T::load !!! Test it first
    if (!container) {
        return;
    }

    for (size_t i = 0; i < cargoTypes; ++i) {
        auto cargo = generateCargo(i);
        container->load(std::move(cargo));
    }
}

SCENARIO("load store should ignore empty pointer", "[Store][load]") {
    GIVEN("empty store and empty pointer") {
        Store store;
        auto emptyCargo = std::unique_ptr<Cargo>();
        WHEN("load store with pointer") {
            store.load(std::move(emptyCargo));
            THEN("store dont change number of cargo") {
                REQUIRE(store.getAssortmentSize() == 0);
            }
        }
    }
}

SCENARIO("load store will insert cargo", "[Store][load]") {
    GIVEN("empty store") {
        Store store;
        WHEN("load store with cargo") {
            fillWithGeneratedData(&store);
            THEN("store change number of cargo") {
                REQUIRE(store.getAssortmentSize() == cargoTypes);
            }
        }
    }
}

SCENARIO("load store will increase amount of same cargo", "[Store][load]") {
    GIVEN("empty store and two same cargos") {
        Store store;
        auto cargo1 = generateCargo(cargoDefaultIndex);
        auto cargo2 = generateCargo(cargoDefaultIndex);
        WHEN("load store with both cargos") {
            store.load(std::move(cargo1));
            store.load(std::move(cargo2));
            THEN("cargo exist in store and have accumulated amount") {
                auto cargo = generateCargo(cargoDefaultIndex);
                Cargo* cargoIn = store.findCargo(cargo.get());
                REQUIRE(cargoIn);
                REQUIRE(cargoIn->getAmount() == (2 * fullQuantity));
            }
        }
    }
}

//Store::findCargo tests

Cargo* getStoreCargo(const Store& store, const std::string& cargoName, size_t amount) {  //use Store::findCargo !!! Test it first
    CargoDefault exemplar{cargoName, amount, singleCargoCost};
    auto cargoPtr = store.findCargo(&exemplar);
    if (cargoPtr) {
        return cargoPtr;
    }
    return nullptr;
}

SCENARIO("search cargo will ignore nullptr", "[Store][findCargo]") {
    GIVEN("store with cargo") {
        Store store;
        fillWithGeneratedData(&store);
        WHEN("search for nullptr") {
            auto noExisting = store.findCargo(nullptr);
            THEN("return nullptr") {
                REQUIRE(!noExisting);
            }
        }
    }
}

SCENARIO("search cargo that not exist in store", "[Store][findCargo]") {
    GIVEN("store with cargo and new cargo") {
        Store store;
        fillWithGeneratedData(&store);
        auto amount = GENERATE(0, halfQuantity, fullQuantity, moreThanFullQuantity);
        CargoDefault noExistingCargo(noExistingCargoName, amount, singleCargoCost);
        WHEN("search for new cargo of amount " << amount) {
            auto noExisting = store.findCargo(&noExistingCargo);
            THEN("cargo not find") {
                REQUIRE(!noExisting);
            }
        }
    }
}

SCENARIO("search cargo that exist in store", "[Store][findCargo]") {
    GIVEN("store with cargo and cargo that exist in store") {
        Store store;
        fillWithGeneratedData(&store);
        auto amount = GENERATE(0, halfQuantity, fullQuantity, moreThanFullQuantity);
        CargoDefault existingCargo(existingCargoName, amount, singleCargoCost);
        WHEN("search for cargo of amount " << amount) {
            auto existing = store.findCargo(&existingCargo);
            THEN("cargo find") {
                REQUIRE(existing);
            }
        }
    }
}

//Store::unload tests

SCENARIO("unload store should ignore empty pointer", "[Store][unload]") {
    GIVEN("store with cargo and empty pointer") {
        Store store;
        fillWithGeneratedData(&store);
        auto emptyCargo = std::unique_ptr<Cargo>();
        WHEN("unload store with pointer") {
            REQUIRE_NOTHROW(store.unload(nullptr));
            THEN("store dont change number of cargo") {
                REQUIRE(store.getAssortmentSize() == cargoTypes);
            }
        }
    }
}

SCENARIO("unload store should throw when cargo not exist in", "[Store][unload]") {
    GIVEN("store with cargo and pointer to not existing cargo") {
        Store store;
        fillWithGeneratedData(&store);
        auto amount = GENERATE(0, halfQuantity, fullQuantity, moreThanFullQuantity);
        CargoDefault noExistingCargo(noExistingCargoName, amount, singleCargoCost);
        WHEN("unload store with other cargo of amount " << amount) {
            REQUIRE_THROWS(store.unload(&noExistingCargo));
            THEN("store dont change number of cargo") {
                REQUIRE_THROWS_AS(store.unload(&noExistingCargo), std::logic_error);
                REQUIRE_THROWS_WITH(store.unload(&noExistingCargo), "Store: Not my Cargo!");
            }
        }
    }
}

SCENARIO("unload store should remove cargo", "[Store][unload]") {
    GIVEN("store with cargo, number of holded cargo and pointer to cargo") {
        Store store;
        fillWithGeneratedData(&store);
        auto num_of_cargo_before = store.getAssortmentSize();
        auto amount = GENERATE(0, halfQuantity, fullQuantity, moreThanFullQuantity);
        auto existingCargo = getStoreCargo(store, existingCargoName, amount);
        WHEN("unload store with cargo of amount " << amount) {
            store.unload(existingCargo);
            THEN("store change number of cargo holded no meter of amount given") {
                REQUIRE_FALSE(getStoreCargo(store, existingCargoName, amount));
                REQUIRE(store.getAssortmentSize() < num_of_cargo_before);
            }
        }
    }
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

TEST_CASE("player sell zero or more than have of cargo to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    fillWithGeneratedData(player.getShip());
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    size_t amount = GENERATE(0, moreThanFullQuantity, std::numeric_limits<size_t>::max());
    auto response = store.buy(cargoExample.get(), amount, &player);

    REQUIRE(response == Response::lack_of_cargo);
    REQUIRE(player.getAvailableSpace() == 0);
    REQUIRE(store.getAssortmentSize() == 0);

    for (const auto& cargo : player.getShip()->getCargoVec()) {
        REQUIRE(cargo->getAmount() == fullQuantity);
    }
}

TEST_CASE("player sell less than have cargo to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    fillWithGeneratedData(player.getShip());
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    size_t amount = GENERATE(1, halfQuantity, fullQuantity - 1);
    auto response = store.buy(cargoExample.get(), amount, &player);

    REQUIRE(response == Response::done);
    REQUIRE(player.getAvailableSpace() == 0);
    REQUIRE(store.getAssortmentSize() == 1);

    for (const auto& cargo : player.getShip()->getCargoVec()) {
        if (*cargo == *cargoExample) {
            REQUIRE(cargo->getAmount() + amount == fullQuantity);
            continue;
        }
        REQUIRE(cargo->getAmount() == fullQuantity);
    }
}

TEST_CASE("player sell full amount of cargo to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    fillWithGeneratedData(player.getShip());
    Store store;

    auto cargoExample = generateCargo(alcoholIndex);
    auto response = store.buy(cargoExample.get(), fullQuantity, &player);

    REQUIRE(response == Response::done);
    REQUIRE(player.getAvailableSpace() == 1);
    REQUIRE(store.getAssortmentSize() == 1);

    for (const auto& cargo : player.getShip()->getCargoVec()) {
        REQUIRE(cargo->getAmount() == fullQuantity);
        REQUIRE_FALSE(*cargo == *cargoExample);
    }

    for (const auto& cargo : store.getCargoVec()) {
        REQUIRE(cargo->getAmount() == fullQuantity);
        REQUIRE(*cargo == *cargoExample);
    }
}

TEST_CASE("player sell full amount of all cargos to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
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
    REQUIRE(store.getAssortmentSize() == fullCappacity);

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

TEST_CASE("rich player with empty ship buy cargo from empty store", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto amount = GENERATE(0, 1, halfQuantity, fullQuantity - 1, fullQuantity, moreThanFullQuantity, std::numeric_limits<size_t>::max());
    auto response = store.sell(cargoExample.get(), amount, &player);

    REQUIRE(response == Response::lack_of_cargo);
}

TEST_CASE("rich player with empty ship buy from store zero or more than it have", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    Store store;
    fillWithGeneratedData(&store);

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto amount = GENERATE(0, moreThanFullQuantity, std::numeric_limits<size_t>::max());
    auto response = store.sell(cargoExample.get(), amount, &player);

    REQUIRE(response == Response::lack_of_cargo);
}

TEST_CASE("rich player with empty ship buy some amount of cargo from store", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    Store store;
    fillWithGeneratedData(&store);

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto amount = GENERATE(1, halfQuantity, fullQuantity - 1);
    auto response = store.sell(cargoExample.get(), amount, &player);

    REQUIRE(response == Response::done);
    REQUIRE(player.getAvailableSpace() == fullCappacity - 1);
    REQUIRE(store.getAssortmentSize() == cargoTypes);
}

TEST_CASE("rich player with empty ship buy full amount of cargo from store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    Store store;
    fillWithGeneratedData(&store);

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.sell(cargoExample.get(), fullQuantity, &player);

    REQUIRE(response == Response::done);
    REQUIRE(player.getAvailableSpace() == fullCappacity - 1);
    REQUIRE(store.getAssortmentSize() == cargoTypes - 1);
}

TEST_CASE("rich player with empty ship buy full amount of all cargos from store", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);

    REQUIRE(player.getAvailableSpace() == fullCappacity);

    Store store;
    fillWithGeneratedData(&store);

    for (size_t i = 0; i < cargoTypes; ++i) {
        auto cargoExample = generateCargo(i);
        auto response = store.sell(cargoExample.get(), fullQuantity, &player);
        REQUIRE(response == Response::done);
        player.income(fullQuantity * cargoExample->getPrice());  //give back money that player pay for cargo
    }

    REQUIRE(player.getAvailableSpace() == 0);
    REQUIRE(store.getAssortmentSize() == 0);
}

TEST_CASE("rich player with empty ship buy some amount of all cargos from store", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);

    REQUIRE(player.getAvailableSpace() == fullCappacity);

    Store store;
    fillWithGeneratedData(&store);

    auto amount = GENERATE(1, halfQuantity, fullQuantity - 1);
    for (size_t i = 0; i < cargoTypes; ++i) {
        auto cargoExample = generateCargo(i);
        auto response = store.sell(cargoExample.get(), amount, &player);
        REQUIRE(response == Response::done);
        player.income(amount * cargoExample->getPrice());  //give back money that player pay for cargo
    }

    REQUIRE(player.getAvailableSpace() == 0);
    REQUIRE(store.getAssortmentSize() == fullCappacity);
}
