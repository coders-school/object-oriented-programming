#include <gtest/gtest.h>
#include <string>
#include "alcohol.hpp"
#include "cargo.hpp"
#include "fruit.hpp"
#include "item.hpp"

struct TestCargo : public ::testing::Test {
    //Fruit fruit;
    //Item item;
    Alcohol alcohol = Alcohol("whisky", 10, 110, 0.40);
};

TEST_F(TestCargo, checkAlcoholConstructor) {
    ASSERT_EQ(alcohol.getBasePrice(), 110);
    ASSERT_EQ(alcohol.getName(), "whisky");
    ASSERT_EQ(alcohol.getAmount(), 10);
    ASSERT_EQ(alcohol.getVolume(), 0.40);
}

TEST_F(TestCargo, checkAlcoholOperator) {
    alcohol+=5;
    ASSERT_EQ(alcohol.getAmount(), 15);
    alcohol-=2;
    ASSERT_EQ(alcohol.getAmount(), 13);
    Alcohol alcohol2 = Alcohol("whisky", 10, 110, 0.40);
    ASSERT_TRUE(alcohol == alcohol2);
}
