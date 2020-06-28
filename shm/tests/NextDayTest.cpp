#include "alcohol.hpp"
#include "fruit.hpp"
#include "gtest/gtest.h"
#include "item.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "store.hpp"

class NextDayTest : public ::testing::Test {
public:
    Player player;
    Alcohol alco;
    Item item;
    Fruit fruit;
    std::vector<std::shared_ptr<Cargo>> known_stock;
    Store store;
    Ship ship;
    NextDayTest()
        : player(std::make_unique<Ship>(ship), 100, 50),
          alco("alco", 10, 100, 40),
          item("item", 5, 50, Item::Rarity::common),
          fruit("fruit", 30, 20, 10),
          known_stock({{std::make_shared<Alcohol>(alco)},
                      {std::make_shared<Item>(item)},
                      {std::make_shared<Fruit>(fruit)}}),
          store({{std::make_shared<Alcohol>(alco)},
                 {std::make_shared<Item>(item)},
                 {std::make_shared<Fruit>(fruit)}}),
          ship(30, 10, 1, &player) {}
};

TEST_F(NextDayTest, NextDayShouldDoNothingToAlcohol) {
    auto temp_alco = alco;
    alco.nextDay();
    ASSERT_EQ(alco, temp_alco);
}

TEST_F(NextDayTest, NextDayShouldSpoilFruit) {
    auto time_to_spoil = 9;
    auto expiry_date = 10;
    auto expected_price = static_cast<size_t>(fruit.getBasePrice() * (float(time_to_spoil) / expiry_date));
    fruit.nextDay();
    ASSERT_EQ(expected_price, fruit.getPrice());
}

TEST_F(NextDayTest, NextDayShouldChangeStockInStore) {
    for (size_t i = 0; i < known_stock.size(); ++i) {
        ASSERT_EQ(known_stock[i]->getAmount(), store.get_stock()[i]->getAmount());
    }
    store.nextDay();
    for (size_t i = 0; i < known_stock.size(); ++i) {
    ASSERT_NE(known_stock[i]->getAmount(), store.get_stock()[i]->getAmount());
    }
    ASSERT_EQ(known_stock[0]->getAmount(), 10);
}

TEST_F(NextDayTest, NextDayShouldPayCrew) {
    auto player_money = player.getMoney();
    ship += 5;
    ship.nextDay();
    ASSERT_EQ(player_money - 5, player.getMoney());
}
