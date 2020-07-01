#include "alcohol.hpp"
#include "fruit.hpp"
#include "gtest/gtest.h"
#include "item.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "store.hpp"
#include "time.hpp"

class NextDayTest : public ::testing::Test {
public:
    Time time;
    Player player;
    Alcohol alco;
    Item item;
    Fruit fruit;
    std::vector<std::shared_ptr<Cargo>> test_stock;
    Store store;
    Ship ship;
    NextDayTest()
        : time(),
          player(std::make_unique<Ship>(30, 10, 1, &player, &time), 100, 50),
          alco("alco", 10, 100, 40),
          item("item", 5, 50, Item::Rarity::common),
          fruit("fruit", 30, 20, 10),
          test_stock({{std::make_shared<Alcohol>(alco)},
                      {std::make_shared<Item>(item)},
                      {std::make_shared<Fruit>(fruit)}}),
          store(test_stock, &time),
          ship(30, 10, 1, &player, &time) {}
};

TEST_F(NextDayTest, NextDayShouldDoNothingToAlcohol) {
    auto temp_alco = alco;
    alco.nextDay();
    ASSERT_EQ(temp_alco, alco);
}

TEST_F(NextDayTest, NextDayShouldDoNothingToItem) {
    auto temp_item = item;
    item.nextDay();
    ASSERT_EQ(temp_item, item);
}

TEST_F(NextDayTest, NextDayShouldSpoilFruit) {
    auto time_to_spoil = 9;
    auto expiry_date = 10;
    auto expected_price = static_cast<size_t>(fruit.getBasePrice() * (float(time_to_spoil) / expiry_date));
    fruit.nextDay();
    ASSERT_EQ(expected_price, fruit.getPrice());
}

TEST_F(NextDayTest, NextDayShouldChangeStockInStore) {
    auto original_alco_amount = test_stock[0]->getAmount();
    auto original_item_amount = test_stock[1]->getAmount();
    auto original_fruit_amount = test_stock[2]->getAmount();
    ASSERT_EQ(original_alco_amount, test_stock[0]->getAmount());
    ASSERT_EQ(original_item_amount, test_stock[1]->getAmount());
    ASSERT_EQ(original_fruit_amount, test_stock[2]->getAmount());
    store.nextDay();
    ASSERT_NE(original_alco_amount, test_stock[0]->getAmount());
    ASSERT_NE(original_item_amount, test_stock[1]->getAmount());
    ASSERT_NE(original_fruit_amount, test_stock[2]->getAmount());
}

TEST_F(NextDayTest, NextDayShouldPayCrew) {
    auto player_money = player.getMoney();
    ship += 5;
    ship.nextDay();
    ASSERT_EQ(player_money - 5, player.getMoney());
}
