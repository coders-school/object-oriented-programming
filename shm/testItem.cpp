#include <string>

#include "alcohol.hpp"
#include "cargo.hpp"
#include "fruit.hpp"
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
    shipOne.removeItem(&itemOne);
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
    playerOne.removeItem(&itemOne);
    ASSERT_EQ(playerOne.getAvailableSpace(), 40);
}

TEST_F(ItemTest, CheckPlayerStoreInteraction) {
    ASSERT_EQ(storeOne.buy(&itemOne,5,&playerOne),Response::lack_of_cargo);
    itemOne += 200;
    ASSERT_EQ(storeOne.buy(&itemOne,100,&playerOne),Response::lack_of_space);
    ASSERT_EQ(storeOne.buy(&itemOne,2,&playerOne),Response::lack_of_money);
    ASSERT_EQ(playerOne.getMoney(), 1000);
    playerOne.giveMoney(15000);
    ASSERT_EQ(playerOne.getMoney(), 16000);
    ASSERT_EQ(itemOne.getAmount(), 202);
    ASSERT_EQ(storeOne.buy(&itemOne,3,&playerOne),Response::done);
    ASSERT_EQ(itemOne.getAmount(), 199);
    ASSERT_EQ(playerOne.getAvailableSpace(), 37);
    ASSERT_EQ(playerOne.getMoney(), 7000);
    Item* itemTwo = playerOne.getItemWithName(name);
    ASSERT_EQ(itemTwo->getAmount(), 3);
    ASSERT_EQ(storeOne.sell(itemTwo,100,&playerOne),Response::lack_of_cargo);
    ASSERT_EQ(storeOne.sell(itemTwo,1,&playerOne),Response::done);
    ASSERT_EQ(itemTwo->getAmount(), 2);
    ASSERT_EQ(playerOne.getMoney(), 10000);
    ASSERT_EQ(storeOne.sell(itemTwo,2,&playerOne),Response::done);
    ASSERT_EQ(playerOne.getMoney(), 16000);
    ASSERT_EQ(playerOne.getItemWithName(name),nullptr);

    Alcohol alcoOne("Jack Sparrow",1000,5000,192,&Publisher);
    ASSERT_EQ(alcoOne.getPrice(), 10000);
    ASSERT_EQ(storeOne.buy(&alcoOne,1001,&playerOne),Response::lack_of_cargo);
    ASSERT_EQ(storeOne.buy(&alcoOne,66,&playerOne),Response::lack_of_space);
    ASSERT_EQ(storeOne.buy(&alcoOne,2,&playerOne),Response::lack_of_money);
    ASSERT_EQ(storeOne.buy(&alcoOne,1,&playerOne),Response::done);
    ASSERT_EQ(playerOne.getMoney(), 6000);
    ASSERT_EQ(alcoOne.getAmount(), 999);
    Alcohol* alcoTwo = playerOne.getAlcoWithName(alcoOne.getName());
    ASSERT_EQ(alcoTwo->getAmount(), 1);
    ASSERT_EQ(storeOne.sell(alcoTwo,100,&playerOne),Response::lack_of_cargo);
    ASSERT_EQ(storeOne.sell(alcoTwo,1,&playerOne),Response::done);
    ASSERT_EQ(playerOne.getMoney(), 16000);
    ASSERT_EQ(playerOne.getAlcoWithName(alcoOne.getName()),nullptr);

    Fruit fruitOne("Devilfruit",100,666,66,6,&Publisher);
    ASSERT_EQ(fruitOne.getPrice(), 605);
    ASSERT_EQ(storeOne.buy(&fruitOne,667,&playerOne),Response::lack_of_cargo);
    ASSERT_EQ(storeOne.buy(&fruitOne,66,&playerOne),Response::lack_of_space);
    ASSERT_EQ(storeOne.buy(&fruitOne,40,&playerOne),Response::lack_of_money);
    ASSERT_EQ(storeOne.buy(&fruitOne,10,&playerOne),Response::done);
    ASSERT_EQ(playerOne.getMoney(), 9950);
    ASSERT_EQ(fruitOne.getAmount(), 90);
    Fruit* fruitTwo = playerOne.getFruitWithName(fruitOne.getName());
    ASSERT_EQ(fruitTwo->getAmount(), 10);
    ASSERT_EQ(storeOne.sell(fruitTwo,11,&playerOne),Response::lack_of_cargo);
    ASSERT_EQ(storeOne.sell(fruitTwo,1,&playerOne),Response::done);
    ASSERT_EQ(playerOne.getMoney(), 10555);
    ASSERT_EQ(fruitTwo->getAmount(), 9);
    ASSERT_EQ(storeOne.sell(fruitTwo,9,&playerOne),Response::done);
    ASSERT_EQ(playerOne.getMoney(), 16000);
    ASSERT_EQ(playerOne.getFruitWithName(name),nullptr);
}

TEST_F(ItemTest, GenerateGoodsTest) {
    storeOne.generateGoods();
    std::cout << storeOne;
}

