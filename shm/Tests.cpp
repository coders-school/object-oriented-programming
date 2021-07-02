
#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>

#include "Store.hpp"

constexpr auto moreThanFullQuantity = 101;
constexpr auto fullQuantity = 100;
constexpr auto halfQuantity = 50;
constexpr auto basePrice = 10;
constexpr auto cargoTypes = 7;

constexpr auto noExistingCargoName = "Dyes";
constexpr auto existingCargoName = "Wheat";

// Return by value to give up ownership
std::unique_ptr<Cargo> generateCargo() {
    // https://portroyale3.fandom.com/wiki/Goods
    const std::vector<std::pair<std::string, size_t>> goods{
        {"Wood", 33},
        {"Adobe Bricks", 33},
        {"Wheat", 33},
        {"Fruits", 50},
        {"Corn", 50},
        {"Sugar", 50},
        {"Hemp", 50}
    };
    static auto index = 0;
    index = index % goods.size();
    auto ptr = std::make_unique<Cargo>(goods[index].first, fullQuantity, goods[index].second);
    ++index;
    // RVO
    return ptr;
}

//return pointer to existing cargo
Cargo* getStoreCargo(const Store& store, const std::string& cargoName, size_t amount){
    Cargo exemplar{cargoName, amount, basePrice};
    auto cargoPtr = store.findCargoInStore(&exemplar);
    if(cargoPtr){
        std::cout <<"Found: "<< cargoPtr->getName() << '\n';
        return cargoPtr;
    }
    std::cout << "Not Found: "<< cargoName << '\n';
    return nullptr;
}

TEST_CASE("findCargoInStore by nullptr", "[Store]") {
    Store myStore;
    for (int i = 0; i < cargoTypes; ++i) {
        auto cargo = generateCargo();
        myStore.load(std::move(cargo));
    }
    auto noExisting = myStore.findCargoInStore(nullptr);
    REQUIRE(!noExisting);
}

TEST_CASE("findCargoInStore by noExistingCargoName", "[Store]") {
    Store myStore;
    for (int i = 0; i < cargoTypes; ++i) {
        auto cargo = generateCargo();
        myStore.load(std::move(cargo));
    }
    auto noExisting = getStoreCargo(myStore, noExistingCargoName, fullQuantity);
    REQUIRE(!noExisting);
}

TEST_CASE("findCargoInStore by existingCargoName", "[Store]") {
    Store myStore;
    for (int i = 0; i < cargoTypes; ++i) {
        auto cargo = generateCargo();
        myStore.load(std::move(cargo));
    }
    auto existing = getStoreCargo(myStore, existingCargoName, fullQuantity);
    REQUIRE(existing);
}

TEST_CASE("findCargoInStore by exemplar Cargo no meter of quantity to search", "[Store]") {
    Store myStore;
    for (int i = 0; i < cargoTypes; ++i) {
        auto cargo = generateCargo();
        myStore.load(std::move(cargo));
    }

    auto existing1 = getStoreCargo(myStore, existingCargoName, moreThanFullQuantity);
    auto existing2 = getStoreCargo(myStore, existingCargoName, fullQuantity);
    auto existing3 = getStoreCargo(myStore, existingCargoName, halfQuantity);
    auto existing4 = getStoreCargo(myStore, existingCargoName, 0);

    REQUIRE(existing1);
    REQUIRE(existing2);
    REQUIRE(existing3);
    REQUIRE(existing4);
}

TEST_CASE("findCargoInStore will ignore own Cargo ptr", "[Store]") {
    Store myStore;
    for (int i = 0; i < cargoTypes; ++i) {
        auto cargo = generateCargo();
        myStore.load(std::move(cargo));
    }

    auto existing = getStoreCargo(myStore, existingCargoName, fullQuantity);
    auto selfCargo = myStore.findCargoInStore(existing);

    REQUIRE(!selfCargo);
}

TEST_CASE("unload will ignore nullptr", "[Store]") {
    Store myStore;
    for (int i = 0; i < cargoTypes; ++i) {
        auto cargo = generateCargo();
        myStore.load(std::move(cargo));
    }
    
    REQUIRE_NOTHROW(myStore.unload(nullptr));
}

TEST_CASE("unload will throw on wrong ptr", "[Store]") {
    Store myStore;
    for (int i = 0; i < cargoTypes; ++i) {
        auto cargo = generateCargo();
        myStore.load(std::move(cargo));
    }
    Cargo exemplar{noExistingCargoName, fullQuantity, basePrice};
    
    REQUIRE_THROWS(myStore.unload(&exemplar));
    REQUIRE_THROWS_AS(myStore.unload(&exemplar), std::logic_error);
    REQUIRE_THROWS_WITH(myStore.unload(&exemplar), "Store: Not my Cargo!");
}

TEST_CASE("unload will remove cargo", "[Store]") {
    Store myStore;
    for (int i = 0; i < cargoTypes; ++i) {
        auto cargo = generateCargo();
        myStore.load(std::move(cargo));
    }
    auto num_of_cargo_before = myStore.getCargoNum();

    auto existing = getStoreCargo(myStore, existingCargoName, fullQuantity);
    myStore.unload(existing);
    auto noExistNow = getStoreCargo(myStore, existingCargoName, fullQuantity);
    
    auto num_of_cargo_after = myStore.getCargoNum();

    REQUIRE(!noExistNow);
    REQUIRE(num_of_cargo_before == num_of_cargo_after + 1);
}