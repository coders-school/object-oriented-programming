#include "gtest/gtest.h"
#include "Cargo.hpp"

#include <string>

class CargoTests : public ::testing::Test {
protected:
    void SetUp() override {
        cargo1 = new Cargo(firstCommodity, firstQuantity, firstBPrice);
        cargo2 = new Cargo(secondCommodity, secondQuantity, secondBPrice);
        cargo3 = new Cargo(thirdCommodity, thirdQuantity, thirdBPrice);
    }
    void TearDown() override {
        delete cargo1;
        delete cargo2;
        delete cargo3;
    }
    Cargo* cargo1;
    Cargo* cargo2;
    Cargo* cargo3;

    const size_t firstQuantity{100}, secondQuantity{125}, thirdQuantity{150};
    const size_t firstBPrice{20}, secondBPrice{30}, thirdBPrice{40};
    const std::string firstCommodity{"bananas"}, secondCommodity{"bananas"}, thirdCommodity{"nuts"};
};

TEST_F(CargoTests, equalOperatorShouldReturnTrue) {
    EXPECT_TRUE(*cargo1 == *cargo2);
    EXPECT_TRUE(*cargo2 == *cargo1);
}

TEST_F(CargoTests, equalOperatorShouldReturnFalse) {
    EXPECT_FALSE(*cargo1 == *cargo3);
    EXPECT_FALSE(*cargo3 == *cargo1);
}

TEST_F(CargoTests, getNameShouldReturnCargoName) {
    EXPECT_EQ(firstCommodity, cargo1->getName());
    EXPECT_EQ(secondCommodity, cargo2->getName());
    EXPECT_EQ(thirdCommodity, cargo3->getName());
}

TEST_F(CargoTests, getAmountShouldReturnCargoAmount) {
    EXPECT_EQ(firstQuantity, cargo1->getAmount());
    EXPECT_EQ(secondQuantity, cargo2->getAmount());
    EXPECT_EQ(thirdQuantity, cargo3->getAmount());
}

TEST_F(CargoTests, getBasePriceShouldReturnCargoBasePrice) {
    EXPECT_EQ(firstBPrice, cargo1->getBasePrice());
    EXPECT_EQ(secondBPrice, cargo2->getBasePrice());
    EXPECT_EQ(thirdBPrice, cargo3->getBasePrice());
}
