#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include <array>
#include <catch/catch.hpp>

#include "Alcohol.hpp"
#include "DefaultCargo.hpp"
#include "Item.hpp"
#include "DryFruit.hpp"

#include "TestCoordinates.hpp"

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
    GoodsData{"Drewno"},
    GoodsData{"Cegly"},
    GoodsData{existingCargoName},
    GoodsData{"Daktyle"},    // 3 - DryFruit
    GoodsData{"Ziemniaki"},  //4 - Fruit
    GoodsData{"???"},        //5 - Alcohol
    GoodsData{"Skrzynia"}    //6 - Item
};

constexpr auto cargoDefaultIndex = 0;
constexpr auto secondCargoDefaultIndex = 1;
constexpr auto dryFruitIndex = 3;
constexpr auto fruitIndex = 4;
constexpr auto alcoholIndex = 5;
constexpr auto itemIndex = 6;
constexpr auto defaultGoodsName = "Towar";

constexpr auto cargoTypes = goods.size();

constexpr auto fullCappacity = cargoTypes;
constexpr auto lessCappacity = fullCappacity - 1;

constexpr auto fruitBestBefore = 5u;
constexpr auto alcoholPercentage = 40u;
constexpr auto itemQuality = Quality::rare;

constexpr auto fullQuantity = 100;

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
    case dryFruitIndex:
        return std::make_unique<DryFruit>(goodsName, fullQuantity, goods[index].value, fruitBestBefore);
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

#include "TestDefaultCargo.hpp"

constexpr auto minimalCargoCost = 1;

#include "TestAlcohol.hpp"
#include "TestItem.hpp"
#include "TestFruit.hpp"
#include "TestDryDruit.hpp"

TEST_CASE("Compare Fruit to Alcohol with same name", "[Alcohol][Fruit]") {
    auto alcohol = generateCargo(alcoholIndex, defaultGoodsName);
    auto fruit = generateCargo(fruitIndex, defaultGoodsName);

    REQUIRE(!(*fruit == *alcohol));
}

#include "TestShip.hpp"

#include "TestPlayer.hpp"

#include "TestWarehouse.hpp"

constexpr auto moreThanFullQuantity = 101;
constexpr auto halfQuantity = 50;

constexpr auto playerMoney = singleCargoCost * fullQuantity * cargoTypes;    //money to buy all Cargo types
constexpr auto playerMoneyForHalfQuantity = singleCargoCost * halfQuantity;  //money to buy half of single cargo

#include "Ship.hpp"

constexpr Capacity shipCapacity = {fullCappacity};
constexpr Crew shipMaxCrew = {20};
constexpr Speed shipSpeed = {10};

#include "TestStore.hpp"
