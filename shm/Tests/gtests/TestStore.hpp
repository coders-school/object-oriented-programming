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

// SCENARIO("load store should ignore empty pointer") {
//     GIVEN("empty store and empty pointer") {
//         Store store;
//         auto emptyCargo = std::unique_ptr<Cargo>();
//         WHEN("load store with pointer") {
//             store.load(std::move(emptyCargo));
//             THEN("store dont change number of cargo") {
//                 EXPECT_TRUE(store.getAssortmentSize() == 0);
//             }
//         }
//     }
// }

// SCENARIO("load store will insert cargo") {
//     GIVEN("empty store") {
//         Store store;
//         WHEN("load store with cargo") {
//             fillWithGeneratedData(&store);
//             THEN("store change number of cargo") {
//                 EXPECT_TRUE(store.getAssortmentSize() == cargoTypes);
//             }
//         }
//     }
// }

// SCENARIO("load store will increase amount of same cargo") {
//     GIVEN("empty store and two same cargos") {
//         Store store;
//         auto cargo1 = generateCargo(cargoDefaultIndex);
//         auto cargo2 = generateCargo(cargoDefaultIndex);
//         WHEN("load store with both cargos") {
//             store.load(std::move(cargo1));
//             store.load(std::move(cargo2));
//             THEN("cargo exist in store and have accumulated amount") {
//                 auto cargo = generateCargo(cargoDefaultIndex);
//                 Cargo* cargoIn = store.findCargo(cargo.get());
//                 EXPECT_TRUE(cargoIn);
//                 EXPECT_TRUE(cargoIn->getAmount() == (2 * fullQuantity));
//             }
//         }
//     }
// }

//Store::findCargo tests

Cargo* getStoreCargo(const Store& store, const std::string& cargoName, size_t amount) {  //use Store::findCargo !!! Test it first
    CargoDefault exemplar{cargoName, amount, singleCargoCost};
    auto cargoPtr = store.findCargo(&exemplar);
    if (cargoPtr) {
        return cargoPtr;
    }
    return nullptr;
}

// SCENARIO("search cargo will ignore nullptr", "[Store][findCargo]") {
//     GIVEN("store with cargo") {
//         Store store;
//         fillWithGeneratedData(&store);
//         WHEN("search for nullptr") {
//             auto noExisting = store.findCargo(nullptr);
//             THEN("return nullptr") {
//                 EXPECT_TRUE(!noExisting);
//             }
//         }
//     }
// }

// SCENARIO("search cargo that not exist in store", "[Store][findCargo]") {
//     GIVEN("store with cargo and new cargo") {
//         Store store;
//         fillWithGeneratedData(&store);
//         auto amount = GENERATE(0, halfQuantity, fullQuantity, moreThanFullQuantity);
//         CargoDefault noExistingCargo(noExistingCargoName, amount, singleCargoCost);
//         WHEN("search for new cargo of amount " << amount) {
//             auto noExisting = store.findCargo(&noExistingCargo);
//             THEN("cargo not find") {
//                 EXPECT_TRUE(!noExisting);
//             }
//         }
//     }
// }

// SCENARIO("search cargo that exist in store", "[Store][findCargo]") {
//     GIVEN("store with cargo and cargo that exist in store") {
//         Store store;
//         fillWithGeneratedData(&store);
//         auto amount = GENERATE(0, halfQuantity, fullQuantity, moreThanFullQuantity);
//         CargoDefault existingCargo(existingCargoName, amount, singleCargoCost);
//         WHEN("search for cargo of amount " << amount) {
//             auto existing = store.findCargo(&existingCargo);
//             THEN("cargo find") {
//                 EXPECT_TRUE(existing);
//             }
//         }
//     }
// }

// //Store::unload tests

// SCENARIO("unload store should ignore empty pointer", "[Store][unload]") {
//     GIVEN("store with cargo and empty pointer") {
//         Store store;
//         fillWithGeneratedData(&store);
//         auto emptyCargo = std::unique_ptr<Cargo>();
//         WHEN("unload store with pointer") {
//             EXPECT_TRUE_NOTHROW(store.unload(nullptr));
//             THEN("store dont change number of cargo") {
//                 EXPECT_TRUE(store.getAssortmentSize() == cargoTypes);
//             }
//         }
//     }
// }

// SCENARIO("unload store should throw when cargo not exist in", "[Store][unload]") {
//     GIVEN("store with cargo and pointer to not existing cargo") {
//         Store store;
//         fillWithGeneratedData(&store);
//         auto amount = GENERATE(0, halfQuantity, fullQuantity, moreThanFullQuantity);
//         CargoDefault noExistingCargo(noExistingCargoName, amount, singleCargoCost);
//         WHEN("unload store with other cargo of amount " << amount) {
//             EXPECT_TRUE_THROWS(store.unload(&noExistingCargo));
//             THEN("store dont change number of cargo") {
//                 EXPECT_TRUE_THROWS_AS(store.unload(&noExistingCargo), std::logic_error);
//                 EXPECT_TRUE_THROWS_WITH(store.unload(&noExistingCargo), "Store: Not my Cargo!");
//             }
//         }
//     }
// }

// SCENARIO("unload store should remove cargo", "[Store][unload]") {
//     GIVEN("store with cargo, number of holded cargo and pointer to cargo") {
//         Store store;
//         fillWithGeneratedData(&store);
//         auto num_of_cargo_before = store.getAssortmentSize();
//         auto amount = GENERATE(0, halfQuantity, fullQuantity, moreThanFullQuantity);
//         auto existingCargo = getStoreCargo(store, existingCargoName, amount);
//         WHEN("unload store with cargo of amount " << amount) {
//             store.unload(existingCargo);
//             THEN("store change number of cargo holded no meter of amount given") {
//                 EXPECT_TRUE_FALSE(getStoreCargo(store, existingCargoName, amount));
//                 EXPECT_TRUE(store.getAssortmentSize() < num_of_cargo_before);
//             }
//         }
//     }
// }

//Store::buy tests

TEST(Store, no_player_to_sell_to_empty_store) {
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.buy(cargoExample.get(), fullQuantity, nullptr);

    EXPECT_TRUE(response == Response::lack_of_cargo);
}

TEST(Player_Store, player_sell_without_ship_to_empty_store) {  //use Player and Ship
    auto ship = std::unique_ptr<Ship>{};
    Player player(std::move(ship), playerMoney);
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.buy(cargoExample.get(), fullQuantity, &player);

    EXPECT_TRUE(response == Response::lack_of_cargo);
}

TEST(Player_Ship_Store, player_sell_noexisting_cargo_to_empty_store) {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.buy(cargoExample.get(), fullQuantity, &player);

    EXPECT_TRUE(response == Response::lack_of_cargo);
}

// TEST(Player_Ship_Store, player_sell_zero_or_more_than_have_of_cargo_to_empty_store) {  //use Player and Ship
//     auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
//     Player player(std::move(ship), playerMoney);
//     fillWithGeneratedData(player.getShip());
//     Store store;

//     auto cargoExample = generateCargo(cargoDefaultIndex);
//     size_t amount = GENERATE(0, moreThanFullQuantity, std::numeric_limits<size_t>::max());
//     auto response = store.buy(cargoExample.get(), amount, &player);

//     EXPECT_TRUE(response == Response::lack_of_cargo);
//     EXPECT_TRUE(player.getAvailableSpace() == 0);
//     EXPECT_TRUE(store.getAssortmentSize() == 0);

//     for (const auto& cargo : player.getShip()->getCargoVec()) {
//         EXPECT_TRUE(cargo->getAmount() == fullQuantity);
//     }
// }

// TEST(Player_Ship_Store, player_sell_less_than_have_cargo_to_empty_store) {  //use Player and Ship
//     auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
//     Player player(std::move(ship), playerMoney);
//     fillWithGeneratedData(player.getShip());
//     Store store;

//     auto cargoExample = generateCargo(cargoDefaultIndex);
//     size_t amount = GENERATE(1, halfQuantity, fullQuantity - 1);
//     auto response = store.buy(cargoExample.get(), amount, &player);

//     EXPECT_TRUE(response == Response::done);
//     EXPECT_TRUE(player.getAvailableSpace() == 0);
//     EXPECT_TRUE(store.getAssortmentSize() == 1);

//     for (const auto& cargo : player.getShip()->getCargoVec()) {
//         if (*cargo == *cargoExample) {
//             EXPECT_TRUE(cargo->getAmount() + amount == fullQuantity);
//             continue;
//         }
//         EXPECT_TRUE(cargo->getAmount() == fullQuantity);
//     }
// }

TEST(Player_Ship_Store, player_sell_full_amount_of_cargo_to_empty_store) {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    fillWithGeneratedData(player.getShip());
    Store store;

    auto cargoExample = generateCargo(alcoholIndex);
    auto response = store.buy(cargoExample.get(), fullQuantity, &player);

    EXPECT_TRUE(response == Response::done);
    EXPECT_TRUE(player.getAvailableSpace() == 1);
    EXPECT_TRUE(store.getAssortmentSize() == 1);

    for (const auto& cargo : player.getShip()->getCargoVec()) {
        EXPECT_TRUE(cargo->getAmount() == fullQuantity);
        EXPECT_FALSE(*cargo == *cargoExample);
    }

    for (const auto& cargo : store.getCargoVec()) {
        EXPECT_TRUE(cargo->getAmount() == fullQuantity);
        EXPECT_TRUE(*cargo == *cargoExample);
    }
}

TEST(Player_Ship_Store, player_sell_full_amount_of_all_cargos_to_empty_store) {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    fillWithGeneratedData(player.getShip());

    EXPECT_TRUE(player.getAvailableSpace() == 0);

    Store store;

    for (size_t i = 0; i < cargoTypes; ++i) {
        auto cargoExample = generateCargo(i);
        auto response = store.buy(cargoExample.get(), fullQuantity, &player);
        EXPECT_TRUE(response == Response::done);
    }

    EXPECT_TRUE(player.getAvailableSpace() == fullCappacity);
    EXPECT_TRUE(store.getAssortmentSize() == fullCappacity);

    for (const auto& cargo : store.getCargoVec()) {
        EXPECT_TRUE(cargo->getAmount() == fullQuantity);
    }
}

//Store::sell tests

TEST(Player_Store, no_player_to_buy_from_empty_store) {  //use Player and Ship
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.sell(cargoExample.get(), fullQuantity, nullptr);

    EXPECT_TRUE(response == Response::lack_of_space);
}

TEST(Player_Store, rich_player_buy_without_ship_from_empty_store) {  //use Player and Ship
    auto ship = std::unique_ptr<Ship>{};
    Player player(std::move(ship), playerMoney);
    Store store;

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.sell(cargoExample.get(), fullQuantity, &player);

    EXPECT_TRUE(response == Response::lack_of_space);
}

// TEST(Player_Ship_Store, rich_player_with_empty_ship_buy_cargo_from_empty_store) {  //use Player and Ship
//     auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
//     Player player(std::move(ship), playerMoney);
//     Store store;

//     auto cargoExample = generateCargo(cargoDefaultIndex);
//     auto amount = GENERATE(0, 1, halfQuantity, fullQuantity - 1, fullQuantity, moreThanFullQuantity, std::numeric_limits<size_t>::max());
//     auto response = store.sell(cargoExample.get(), amount, &player);

//     EXPECT_TRUE(response == Response::lack_of_cargo);
// }

// TEST(Player_Ship_Store, rich_player_with_empty_ship_buy_from_store_zero_or_more_than_it_have) {  //use Player and Ship
//     auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
//     Player player(std::move(ship), playerMoney);
//     Store store;
//     fillWithGeneratedData(&store);

//     auto cargoExample = generateCargo(cargoDefaultIndex);
//     auto amount = GENERATE(0, moreThanFullQuantity, std::numeric_limits<size_t>::max());
//     auto response = store.sell(cargoExample.get(), amount, &player);

//     EXPECT_TRUE(response == Response::lack_of_cargo);
// }

// TEST(Player_Ship_Store, rich_player_with_empty_ship_buy_some_amount_of_cargo_from_store) {  //use Player and Ship
//     auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
//     Player player(std::move(ship), playerMoney);
//     Store store;
//     fillWithGeneratedData(&store);

//     auto cargoExample = generateCargo(cargoDefaultIndex);
//     auto amount = GENERATE(1, halfQuantity, fullQuantity - 1);
//     auto response = store.sell(cargoExample.get(), amount, &player);

//     EXPECT_TRUE(response == Response::done);
//     EXPECT_TRUE(player.getAvailableSpace() == fullCappacity - 1);
//     EXPECT_TRUE(store.getAssortmentSize() == cargoTypes);
// }

TEST(Player_Ship_Store, rich_player_with_empty_ship_buy_full_amount_of_cargo_from_store) {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);
    Store store;
    fillWithGeneratedData(&store);

    auto cargoExample = generateCargo(cargoDefaultIndex);
    auto response = store.sell(cargoExample.get(), fullQuantity, &player);

    EXPECT_TRUE(response == Response::done);
    EXPECT_TRUE(player.getAvailableSpace() == fullCappacity - 1);
    EXPECT_TRUE(store.getAssortmentSize() == cargoTypes - 1);
}

TEST(Player_Ship_Store, rich_player_with_empty_ship_buy_full_amount_of_all_cargos_from_store) {  //use Player and Ship
    auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
    Player player(std::move(ship), playerMoney);

    EXPECT_TRUE(player.getAvailableSpace() == fullCappacity);

    Store store;
    fillWithGeneratedData(&store);

    for (size_t i = 0; i < cargoTypes; ++i) {
        auto cargoExample = generateCargo(i);
        auto response = store.sell(cargoExample.get(), fullQuantity, &player);
        EXPECT_TRUE(response == Response::done);
        player.income(fullQuantity * cargoExample->getPrice());  //give back money that player pay for cargo
    }

    EXPECT_TRUE(player.getAvailableSpace() == 0);
    EXPECT_TRUE(store.getAssortmentSize() == 0);
}

// TEST(Player_Ship_Store, rich_player_with_empty_ship_buy_some_amount_of_all_cargos_from_store) {  //use Player and Ship
//     auto ship = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, "Ship");
//     Player player(std::move(ship), playerMoney);

//     EXPECT_TRUE(player.getAvailableSpace() == fullCappacity);

//     Store store;
//     fillWithGeneratedData(&store);

//     auto amount = GENERATE(1, halfQuantity, fullQuantity - 1);
//     for (size_t i = 0; i < cargoTypes; ++i) {
//         auto cargoExample = generateCargo(i);
//         auto response = store.sell(cargoExample.get(), amount, &player);
//         EXPECT_TRUE(response == Response::done);
//         player.income(amount * cargoExample->getPrice());  //give back money that player pay for cargo
//     }

//     EXPECT_TRUE(player.getAvailableSpace() == 0);
//     EXPECT_TRUE(store.getAssortmentSize() == fullCappacity);
// }
