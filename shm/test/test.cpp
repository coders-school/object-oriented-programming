#include "fruit.hpp"
#include "gtest/gtest.h"
#include "player.hpp"
#include "ship.hpp"
#include "store.hpp"
#include "time.hpp"

namespace SHM_test
{
constexpr size_t SHIP_CAPACITY = 500;
constexpr char SHIP_NAME[] = "BestShipEver";
constexpr int SHIP_MAX_CREW = 20;
constexpr int SHIP_SPEED = 666;
constexpr size_t SHIP_ID = 7;
constexpr int SHIP_CREW = 5;
constexpr size_t MONEY = 1000;
constexpr size_t SALARY = 20;
constexpr size_t AVAILABLE_SPACE = 100;
constexpr char FRUIT_MELON[] = "Melon";
constexpr size_t FRUIT_MELON_SPOIL_TIME = 5;
constexpr size_t FRUIT_MELON_BASEPRICE = 10;
constexpr size_t FRUIT_MELON_AMOUNT = 24;

constexpr char APPLE[] = "Apple";
constexpr size_t APPLE_AMOUNT = 16;
constexpr size_t APPLE_HALF_AMOUNT = 8;
constexpr size_t APPLE_BASEPRICE = 3;
constexpr size_t APPLE_SPOILTIME = 8;

Time time;
Ship ship(SHIP_CAPACITY, SHIP_MAX_CREW, SHIP_SPEED, SHIP_NAME, SHIP_ID, &time);
Player player(ship, MONEY, AVAILABLE_SPACE);
Fruit apple(APPLE, APPLE_AMOUNT, APPLE_BASEPRICE, APPLE_SPOILTIME, &time);

TEST(ShipTest, ShouldInitShip)
{
    EXPECT_EQ(ship.getMaxCrew(), SHIP_MAX_CREW);
    EXPECT_EQ(ship.getSpeed(), SHIP_SPEED);
    EXPECT_EQ(ship.getId(), SHIP_ID);
}
TEST(ShipTest, ShouldAddCrew)
{
    ship += SHIP_CREW;
    EXPECT_EQ(ship.getCrew(), SHIP_CREW);
}
TEST(ShipTest, ShouldSubtractCrew)
{
    ship -= SHIP_CREW;
    EXPECT_EQ(ship.getCrew(), 0);
}
TEST(PlayerTest, ShouldInitPlayer)
{
    EXPECT_EQ(player.getMoney(), MONEY);
}
TEST(PlayerTest, ShouldPayCrew)
{
    size_t crew = ship.getCrew();
    size_t money = player.getMoney();

    ++time;
    EXPECT_EQ(player.getMoney(), money - crew);
}
TEST(TimeTest, ShouldTimePass)
{
    ++time;
    EXPECT_EQ(time.getElapsedTime(), 2);
}
TEST(StoreTest, ShouldHandleBuySell)
{
    Store store;

    EXPECT_EQ(store.buy(&apple, APPLE_AMOUNT, &player), Store::Response::invalid_cargo);
    store.addCargo(&apple);
    EXPECT_EQ(store.buy(&apple, APPLE_AMOUNT * 2, &player), Store::Response::lack_of_cargo);
    EXPECT_EQ(store.buy(&apple, APPLE_AMOUNT * 2000, &player), Store::Response::lack_of_money);
    EXPECT_EQ(store.buy(&apple, APPLE_HALF_AMOUNT, &player), Store::Response::done);
    EXPECT_EQ(store.sell(&apple, APPLE_HALF_AMOUNT, &player), Store::Response::done);
}
TEST(FruitTest, ShouldSpoil)
{
    size_t spoilTime = FRUIT_MELON_SPOIL_TIME;

    Fruit fruit(FRUIT_MELON, FRUIT_MELON_AMOUNT, FRUIT_MELON_BASEPRICE, FRUIT_MELON_SPOIL_TIME, &time);

    while (spoilTime) {
        ++time;
        --spoilTime;
    }
    EXPECT_EQ(fruit.getAmount(), 0);
}
TEST(StoreNextDay, ShouldGenerateRandomAmountOfCargo)
{
    Store store;
    Time time;
    Fruit fruit("banana", 10, 25, 99, &time);
    store.addCargo(&fruit);
    store.nextDay();
    std::cout << "\n* Amount of " << fruit.getName() << " is NOW: " <<
                 store.getCargo("banana")->getAmount() << " *\n\n";
}
}  // namespace SHM_test
