#include <string>

#include "cargo.hpp"
#include "gtest/gtest.h"
#include "item.hpp"
#include "player.hpp"
#include "rarity.hpp"
#include "ship.hpp"
#include "store.hpp"
#include "timeSHM.cpp"

class ItemTest : public ::testing::Test {
public:
   int rarity = static_cast<int>(Rarity::rare);

protected:
    std::string name = "Old_Shoe";
    size_t amount = 2;
    size_t basePrice = 1000;
    Time Publisher;
    ItemTest() : itemOne(name, amount, basePrice, rarity, &Publisher) {
        shipOne = Ship(65, 20, 7, "Middleman", 2);   
    };
    Item itemOne;
    Ship shipOne;
    Player playerOne = Player(std::make_unique<Ship>(40, 10, 5, "Battered Boat", 3));
    Store storeOne = Store(&Publisher);
};


TEST_F(ItemTest, ShouldGivePriceOfItem) {
    auto priceAfterRarity = itemOne.getBasePrice() * rarity;
    ASSERT_EQ(itemOne.getPrice(), priceAfterRarity);
}

TEST_F(ItemTest, CheckShipLoading) {
    ASSERT_EQ(shipOne.getName(), "Middleman");
    ASSERT_EQ(shipOne.countAvailableSpace(), 65);
    shipOne.load(&itemOne);
    ASSERT_EQ(shipOne.countAvailableSpace(), 63);
    itemOne += 20;
    ASSERT_EQ(shipOne.countAvailableSpace(), 43);
    itemOne -= 7;
    ASSERT_EQ(shipOne.countAvailableSpace(), 50);
    shipOne.removeCargo(&itemOne);
    ASSERT_EQ(shipOne.countAvailableSpace(), 65);
}

TEST_F(ItemTest, CheckPlayerInteraction) {
    ASSERT_EQ(playerOne.getMoney(), 1000);
    ASSERT_EQ(playerOne.getAvailableSpace(), 40);
    playerOne.giveCargo(&itemOne);
    ASSERT_EQ(playerOne.getAvailableSpace(), 38);
    itemOne += 20;
    ASSERT_EQ(playerOne.getAvailableSpace(), 18);
    itemOne -= 2;
    ASSERT_EQ(playerOne.getAvailableSpace(), 20);
    playerOne.removeCargo(&itemOne);
    ASSERT_EQ(playerOne.getAvailableSpace(), 40);
}

TEST_F(ItemTest, CheckPlayerStoreInteraction) {
    ASSERT_EQ(storeOne.buy(&itemOne,5,&playerOne),Response::lack_of_cargo);
    itemOne += 200;
    ASSERT_EQ(storeOne.buy(&itemOne,100,&playerOne),Response::lack_of_space);
    ASSERT_EQ(storeOne.buy(&itemOne,2,&playerOne),Response::lack_of_money);
    ASSERT_EQ(playerOne.getMoney(), 1000);
    playerOne.giveMoney(5000);
    ASSERT_EQ(playerOne.getMoney(), 6000);
    ASSERT_EQ(itemOne.getAmount(), 202);
    ASSERT_EQ(storeOne.buy(&itemOne,3,&playerOne),Response::done);
    ASSERT_EQ(itemOne.getAmount(), 199);
    ASSERT_EQ(playerOne.getAvailableSpace(), 37);
    ASSERT_EQ(playerOne.getMoney(), 3000);
    Cargo* itemTwo = playerOne.getCargoWithName(name);
    ASSERT_EQ(itemTwo->getAmount(), 3);
    ASSERT_EQ(storeOne.sell(itemTwo,100,&playerOne),Response::lack_of_cargo);
    ASSERT_EQ(storeOne.sell(itemTwo,1,&playerOne),Response::done);
    ASSERT_EQ(itemTwo->getAmount(), 2);
    ASSERT_EQ(playerOne.getMoney(), 4000);
    ASSERT_EQ(storeOne.sell(itemTwo,2,&playerOne),Response::done);
    ASSERT_EQ(playerOne.getMoney(), 6000);
    ASSERT_EQ(playerOne.getCargoWithName(name),nullptr);
}
