#include <vector>
#include <set>

#include "Alcohol.hpp"
#include "Ship.hpp"
#include "ShmExceptions.hpp"
#include "gtest/gtest.h"

TEST(ship, CrewShouldBeZero)
{
    Ship ship{1, 1, 1, "a", 1};
    EXPECT_THROW(ship.operator-=(10), AmountException);
}

TEST(ship, CrewShouldNotBeHigherThanMaxCrew)
{
    Ship ship{1, 1, 1, "a", 1};
    EXPECT_THROW(ship.operator+=(10), AmountException);
}

TEST(ship, AlcoholVodkaShouldBeSuccesfulLoadedOnShip)
{
    auto capacity = 20;
    auto maxCrew = 5;
    auto speed = 7;
    size_t id = 0;
    Ship freighter(capacity, maxCrew, speed, "Venus", id);

    auto amount = 5;
    auto base_price = 3;
    auto percentage = 40;
    auto vodka = std::make_shared<Alcohol>(amount, "Vodka", base_price, percentage);
    freighter.load(vodka);
    auto cargos = freighter.getCargos();
    EXPECT_EQ(cargos[0], vodka);
}

TEST(ship, AlcoholVodkaShouldBeSuccesfulUnloadedOnShip)
{
    auto capacity = 20;
    auto maxCrew = 5;
    auto speed = 7;
    size_t id = 0;
    Ship freighter(capacity, maxCrew, speed, "Venus", id);

    auto amount = 5;
    auto base_price = 3;
    auto percentage = 40;
    auto vodka = std::make_shared<Alcohol>(amount, "Vodka", base_price, percentage);
    freighter.load(vodka);
    freighter.unload(vodka.get());
    auto cargos = freighter.getCargos();
    EXPECT_TRUE(cargos.empty());
}
