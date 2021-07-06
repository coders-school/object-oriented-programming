#define CATCH_CONFIG_MAIN

#include <array>
#include <catch/catch.hpp>

#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"
#include "Store.hpp"

constexpr auto singleCargoCost = 10;
struct GoodsData {
    constexpr GoodsData(const char* name)
        : name(name) {}
    constexpr GoodsData(const char* name, size_t value)
        : name(name), value(value) {}

    const char* name;
    size_t value = singleCargoCost;
};

constexpr auto noExistingCargoName = "Woda";
constexpr auto existingCargoName = "Pszenica";

constexpr std::array goods{
    GoodsData{"Drewno"},  // for fun only
    GoodsData{"Cegly"},
    GoodsData{existingCargoName},
    GoodsData{"Kamienie"},
    GoodsData{"Ziemniaki"},  //4 - fruit
    GoodsData{"???"},        //5 - alcohol
    GoodsData{"Skrzynia"}    //6 - item
};

constexpr auto cargoDefaultIndex = 0;
constexpr auto secondCargoDefaultIndex = 1;
constexpr auto fruitIndex = 4;
constexpr auto alcoholIndex = 5;
constexpr auto itemIndex = 6;
constexpr auto defaultGoodsName = "Towar";

constexpr auto cargoTypes = goods.size();

constexpr auto fullCappacity = cargoTypes;
constexpr auto lessCappacity = 6;

constexpr auto fruitBestBefore = 5u;
constexpr auto alcoholPercentage = 40u;
constexpr auto itemQuality = Quality::rare;

constexpr auto moreThanFullQuantity = 101;
constexpr auto fullQuantity = 100;
constexpr auto halfQuantity = 50;

constexpr auto playerMoney = singleCargoCost * fullQuantity * cargoTypes;    //money to buy all Cargo types
constexpr auto playerMoneyForHalfQuantity = singleCargoCost * halfQuantity;  //money to buy half of single cargo

// Return by value to give up ownership
std::unique_ptr<Cargo> generateCargo(size_t index, const std::string& differentName = std::string{}) {
    if (index >= cargoTypes) {
        throw std::out_of_range("generateCargo: index is out of bounds.");
    }

    std::string goodsName;
    if (differentName.empty()) {
        goodsName = goods[index].name;
    } else {
        goodsName = differentName;
    }

    switch (index) {
    case fruitIndex:
        return std::make_unique<Fruit>(goodsName, fullQuantity, goods[index].value, fruitBestBefore);
    case alcoholIndex:
        Alcohol::alcoholBasePriceFor96percent_ = singleCargoCost;
        return std::make_unique<Alcohol>(goodsName, fullQuantity, alcoholPercentage);
    case itemIndex:
        return std::make_unique<Item>(goodsName, fullQuantity, goods[index].value, itemQuality);
    default:
        return std::make_unique<CargoDefault>(goodsName, fullQuantity, goods[index].value);
    }
}

//Fruit::operator-- test

TEST_CASE("Fruit decrement price over time", "[Fruit]") {
    auto fruit = generateCargo(fruitIndex);
    auto& fruitTypeRef = dynamic_cast<Fruit&>(*fruit);

    auto fruitValueFunct = [](auto daysPassed) -> size_t {
        return singleCargoCost * (fruitBestBefore - daysPassed) / static_cast<double>(fruitBestBefore);
    };

    std::cout << "Fresh fruit value: " << fruit->getPrice() << '\n';
    REQUIRE(fruit->getPrice() == singleCargoCost);

    for (int daysPassed = 1; daysPassed <= fruitBestBefore; ++daysPassed) {
        --fruitTypeRef;
        std::cout << "Fruit value: " << fruit->getPrice() << '\n';
        REQUIRE(fruit->getPrice() == fruitValueFunct(daysPassed));
    }
}

TEST_CASE("Fruit decrement below max time", "[Fruit]") {
    auto fruit = generateCargo(fruitIndex);
    auto& fruitTypeRef = dynamic_cast<Fruit&>(*fruit);

    for (int daysPassed = 1; daysPassed <= fruitBestBefore; ++daysPassed) {
        --fruitTypeRef;
    }
    constexpr auto rottingDays = 4;
    for (int daysPassed = 0; daysPassed < rottingDays; ++daysPassed) {
        --fruitTypeRef;
        std::cout << "Fruit value after rotting: " << fruit->getPrice() << '\n';
    }
    REQUIRE(fruit->getPrice() == 0);
}

//Cargo types operator== tests

TEST_CASE("Compare same CargoDefault", "[Alcohol][Cargo]") {
    auto cargoDefault = generateCargo(cargoDefaultIndex);
    auto samecargoDefault = generateCargo(cargoDefaultIndex);

    REQUIRE(*samecargoDefault == *cargoDefault);
}

TEST_CASE("Compare CargoDefault to CargoDefault with same name", "[Alcohol][Cargo]") {
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);
    auto secondcargoDefault = generateCargo(secondCargoDefaultIndex, defaultGoodsName);

    REQUIRE(*secondcargoDefault == *cargoDefault);  // Unimportant because CargoDefault is temporary
}

TEST_CASE("Compare different CargoDefault", "[Alcohol][Cargo]") {
    auto cargoDefault = generateCargo(cargoDefaultIndex);
    auto secondcargoDefault = generateCargo(secondCargoDefaultIndex);

    REQUIRE(!(*secondcargoDefault == *cargoDefault));
}

TEST_CASE("Compare Alcohol to CargoDefault with same name", "[Alcohol][Cargo]") {
    auto alcohol = generateCargo(alcoholIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    REQUIRE(!(*alcohol == *cargoDefault));
}

/*TEST_CASE("Compare CargoDefault to Alcohol with same name", "[Alcohol][Cargo]") {
    auto alcohol = generateCargo(alcoholIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    CHECK(!(*cargoDefault == *alcohol));  // Unimportant because CargoDefault is temporary
}*/

TEST_CASE("Compare Fruit to Alcohol with same name", "[Alcohol][Fruit][Cargo]") {
    auto alcohol = generateCargo(alcoholIndex, defaultGoodsName);
    auto fruit = generateCargo(fruitIndex, defaultGoodsName);

    REQUIRE(!(*fruit == *alcohol));
}

template <typename T>
void fillWithGeneratedData(T* container) {  //use T::load !!! Test it first
    if (!container) {
        return;
    }

    for (int i = 0; i < cargoTypes; ++i) {
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

    auto cargo = generateCargo(0);
    store.load(std::move(cargo));
    cargo = generateCargo(0);
    store.load(std::move(cargo));

    cargo = generateCargo(0);
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

TEST_CASE("findCargoInStore will ignore own Cargo ptr", "[Store]") {
    Store store;
    fillWithGeneratedData(&store);

    auto existing = getStoreCargo(store, existingCargoName, fullQuantity);
    auto selfCargo = store.findCargoInStore(existing);

    REQUIRE(!selfCargo);
}

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

    auto cargoExample = generateCargo(0);
    auto response = store.buy(cargoExample.get(), fullQuantity, nullptr);

    REQUIRE(response == Response::lack_of_cargo);
}

TEST_CASE("player sell without ship to empty store", "[Player][Store][buy]") {  //use Player and Ship
    auto ship = std::unique_ptr<Ship>{};
    Player player(std::move(ship), playerMoney);
    Store store;

    auto cargoExample = generateCargo(0);
    auto response = store.buy(cargoExample.get(), fullQuantity, &player);

    REQUIRE(response == Response::lack_of_cargo);
}

TEST_CASE("player sell noexisting cargo to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(fullCappacity, 0, 0, "Ship", 0, std::vector<std::unique_ptr<Cargo>>{});
    Player player(std::move(ship), playerMoney);
    Store store;

    auto cargoExample = generateCargo(0);
    auto response = store.buy(cargoExample.get(), fullQuantity, &player);

    REQUIRE(response == Response::lack_of_cargo);
}

TEST_CASE("player sell more of single cargo than have to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(fullCappacity, 0, 0, "Ship", 0, std::vector<std::unique_ptr<Cargo>>{});
    Player player(std::move(ship), playerMoney);
    fillWithGeneratedData(player.getShip());
    Store store;

    auto cargoExample = generateCargo(0);
    auto response = store.buy(cargoExample.get(), moreThanFullQuantity, &player);

    REQUIRE(response == Response::lack_of_cargo);
    REQUIRE(player.getAvailableSpace() == 0);
    REQUIRE(store.getCargoNum() == 0);

    for (const auto& cargo : player.getShip()->getCargoVec()) {
        REQUIRE(cargo->getAmount() == fullQuantity);
    }
}

TEST_CASE("player sell half of single cargo than have to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(fullCappacity, 0, 0, "Ship", 0, std::vector<std::unique_ptr<Cargo>>{});
    Player player(std::move(ship), playerMoney);
    fillWithGeneratedData(player.getShip());
    Store store;

    auto cargoExample = generateCargo(0);
    auto response = store.buy(cargoExample.get(), halfQuantity, &player);

    REQUIRE(response == Response::done);
    REQUIRE(player.getAvailableSpace() == 0);
    REQUIRE(store.getCargoNum() == 1);

    std::cout << "Ship Cargo: \n";
    for (const auto& cargo : player.getShip()->getCargoVec()) {
        std::cout << std::setw(15) << std::left << cargo->getName() << ":" << std::setw(5) << cargo->getAmount() << '\n';
        if (*cargo == *cargoExample) {
            REQUIRE(cargo->getAmount() == halfQuantity);
            continue;
        }
        REQUIRE(cargo->getAmount() == fullQuantity);
    }
}

TEST_CASE("player sell full of single cargo to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(fullCappacity, 0, 0, "Ship", 0, std::vector<std::unique_ptr<Cargo>>{});
    Player player(std::move(ship), playerMoney);
    fillWithGeneratedData(player.getShip());
    Store store;

    auto cargoExample = generateCargo(alcoholIndex);
    auto response = store.buy(cargoExample.get(), fullQuantity, &player);

    REQUIRE(response == Response::done);
    REQUIRE(player.getAvailableSpace() == 1);
    REQUIRE(store.getCargoNum() == 1);

    std::cout << "Ship Cargo: \n";
    for (const auto& cargo : player.getShip()->getCargoVec()) {
        std::cout << std::setw(15) << std::left << cargo->getName() << ":" << std::setw(5) << cargo->getAmount() << '\n';
        REQUIRE(cargo->getAmount() == fullQuantity);
        REQUIRE_FALSE(*cargo == *cargoExample);
    }

    std::cout << "Store Cargo: \n";
    for (const auto& cargo : store.cargoVec_) {
        std::cout << std::setw(15) << std::left << cargo->getName() << ":" << std::setw(5) << cargo->getAmount() << '\n';
        REQUIRE(cargo->getAmount() == fullQuantity);
        REQUIRE(*cargo == *cargoExample);
    }
}

TEST_CASE("player sell full of all cargo to empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(fullCappacity, 0, 0, "Ship", 0, std::vector<std::unique_ptr<Cargo>>{});
    Player player(std::move(ship), playerMoney);
    fillWithGeneratedData(player.getShip());

    REQUIRE(player.getAvailableSpace() == 0);

    Store store;

    for (int i = 0; i < cargoTypes; ++i) {
        auto cargoExample = generateCargo(i);
        auto response = store.buy(cargoExample.get(), fullQuantity, &player);
        REQUIRE(response == Response::done);
    }

    REQUIRE(player.getAvailableSpace() == fullCappacity);
    REQUIRE(store.getCargoNum() == fullCappacity);

    std::cout << "Store Cargo: \n";
    for (const auto& cargo : store.cargoVec_) {
        std::cout << std::setw(15) << std::left << cargo->getName() << ":" << std::setw(5) << cargo->getAmount() << '\n';
        REQUIRE(cargo->getAmount() == fullQuantity);
    }
}

//Store::sell tests

TEST_CASE("no player to buy from empty store", "[Store][sell]") {  //use Player and Ship
    Store store;

    auto cargoExample = generateCargo(0);
    auto response = store.sell(cargoExample.get(), fullQuantity, nullptr);

    REQUIRE(response == Response::lack_of_space);
}

TEST_CASE("rich player buy without ship from empty store", "[Player][Store][sell]") {  //use Player and Ship
    auto ship = std::unique_ptr<Ship>{};
    Player player(std::move(ship), playerMoney);
    Store store;

    auto cargoExample = generateCargo(0);
    auto response = store.sell(cargoExample.get(), fullQuantity, &player);

    REQUIRE(response == Response::lack_of_space);
}

TEST_CASE("rich player with empty ship buy noexisting cargo from empty store", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(fullCappacity, 0, 0, "Ship", 0, std::vector<std::unique_ptr<Cargo>>{});
    Player player(std::move(ship), playerMoney);
    Store store;

    auto cargoExample = generateCargo(0);
    auto response = store.sell(cargoExample.get(), fullQuantity, &player);

    REQUIRE(response == Response::lack_of_cargo);
}

TEST_CASE("rich player with empty ship buy more of single cargo than store have", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(fullCappacity, 0, 0, "Ship", 0, std::vector<std::unique_ptr<Cargo>>{});
    Player player(std::move(ship), playerMoney);
    Store store;
    fillWithGeneratedData(&store);

    auto cargoExample = generateCargo(0);
    auto response = store.sell(cargoExample.get(), moreThanFullQuantity, &player);

    REQUIRE(response == Response::lack_of_cargo);
}

TEST_CASE("rich player with empty ship buy half of single cargo than store have", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(fullCappacity, 0, 0, "Ship", 0, std::vector<std::unique_ptr<Cargo>>{});
    Player player(std::move(ship), playerMoney);
    Store store;
    fillWithGeneratedData(&store);

    auto cargoExample = generateCargo(0);
    auto response = store.sell(cargoExample.get(), halfQuantity, &player);

    REQUIRE(response == Response::done);
    REQUIRE(player.getAvailableSpace() == fullCappacity - 1);
    REQUIRE(store.getCargoNum() == cargoTypes);
}

TEST_CASE("rich player with empty ship buy full of single cargo from empty store", "[Player][Ship][Store][buy]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(fullCappacity, 0, 0, "Ship", 0, std::vector<std::unique_ptr<Cargo>>{});
    Player player(std::move(ship), playerMoney);
    Store store;
    fillWithGeneratedData(&store);

    auto cargoExample = generateCargo(0);
    auto response = store.sell(cargoExample.get(), fullQuantity, &player);

    REQUIRE(response == Response::done);
    REQUIRE(player.getAvailableSpace() == fullCappacity - 1);
    REQUIRE(store.getCargoNum() == cargoTypes - 1);
}

TEST_CASE("rich player with empty ship with enough capacity buy full of all cargo from store", "[Player][Ship][Store][sell]") {  //use Player and Ship
    auto ship = std::make_unique<Ship>(fullCappacity, 0, 0, "Ship", 0, std::vector<std::unique_ptr<Cargo>>{});
    Player player(std::move(ship), playerMoney);

    REQUIRE(player.getAvailableSpace() == fullCappacity);

    Store store;
    fillWithGeneratedData(&store);

    for (int i = 0; i < cargoTypes; ++i) {
        auto cargoExample = generateCargo(i);
        auto response = store.sell(cargoExample.get(), fullQuantity, &player);
        REQUIRE(response == Response::done);
    }

    REQUIRE(player.getAvailableSpace() == 0);
    REQUIRE(store.getCargoNum() == 0);
}
