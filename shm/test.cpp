#include "gtest/gtest.h"
#include "Cargo.hpp"

#include <string>

class CargoTests : public ::testing::Test {
protected:
    const size_t firstQuantity{100}, secondQuantity{125}, thirdQuantity{150};
    const size_t firstBPrice{20}, secondBPrice{30}, thirdBPrice{40};
    const std::string firstCommodity{"bananas"}, secondCommodity{"bananas"}, thirdCommodity{"nuts"};

    Cargo cargo1{firstCommodity, firstQuantity, firstBPrice};
    Cargo cargo2{secondCommodity, secondQuantity, secondBPrice};
    Cargo cargo3{thirdCommodity, thirdQuantity, thirdBPrice};
};

TEST_F(CargoTests, equalOperatorShouldReturnTrue) {
    EXPECT_TRUE(cargo1 == cargo2);
    EXPECT_TRUE(cargo2 == cargo1);
}

TEST_F(CargoTests, equalOperatorShouldReturnFalse) {
    EXPECT_FALSE(cargo1 == cargo3);
    EXPECT_FALSE(cargo3 == cargo1);
}

TEST_F(CargoTests, getNameShouldReturnCargoName) {
    EXPECT_EQ(firstCommodity, cargo1.getName());
    EXPECT_EQ(secondCommodity, cargo2.getName());
    EXPECT_EQ(thirdCommodity, cargo3.getName());
}

TEST_F(CargoTests, getAmountShouldReturnCargoAmount) {
    EXPECT_EQ(firstQuantity, cargo1.getAmount());
    EXPECT_EQ(secondQuantity, cargo2.getAmount());
    EXPECT_EQ(thirdQuantity, cargo3.getAmount());
}

TEST_F(CargoTests, getBasePriceShouldReturnCargoBasePrice) {
    EXPECT_EQ(firstBPrice, cargo1.getBasePrice());
    EXPECT_EQ(secondBPrice, cargo2.getBasePrice());
    EXPECT_EQ(thirdBPrice, cargo3.getBasePrice());
}
