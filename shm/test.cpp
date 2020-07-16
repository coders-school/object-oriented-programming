#include "gtest/gtest.h"
#include "Cargo.hpp"
#include "Island.hpp"

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

class IslandTests : public ::testing::Test {
protected:
    int positionX1{2}, positionX2{2}, positionX3{2}, positionX4{3}, positionX5{11};
    int positionY1{5}, positionY2{5}, positionY3{6}, positionY4{5}, positionY5{14};
    Island island1{positionX1, positionY1};
    Island island2{positionX2, positionY2};
    Island island3{positionX3, positionY3};
    Island island4{positionX4, positionY5};
    Island island5{positionX4, positionY5};
};

class CoordinatesTests : public ::testing::Test {
protected:
    Coordinates someCoordinates{2,5};
    Coordinates someEqualCoordinates{2,5};
    Coordinates someNotEqualCoordinates1{2,6};
    Coordinates someNotEqualCoordinates2{1,5};
    Coordinates someNotEqualCoordinates3{11,19};
};


// CargoTests beginning
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


// IslandTests beginning
TEST_F(IslandTests, equalOperatorShouldReturnTrue) {
    EXPECT_TRUE(island1 == island2);
    EXPECT_TRUE(island2 == island1);
}

TEST_F(IslandTests, equalOperatorShouldReturnFalse) {
    EXPECT_FALSE(island1 == island3);
    EXPECT_FALSE(island1 == island4);
    EXPECT_FALSE(island1 == island5);
    EXPECT_FALSE(island3 == island1);
    EXPECT_FALSE(island4 == island1);
    EXPECT_FALSE(island5 == island1);
}

// CoordinatesTests beginning
TEST_F(CoordinatesTests, equalOperatorShouldReturnTrue) {
    EXPECT_TRUE(someCoordinates == someEqualCoordinates);
    EXPECT_TRUE(someEqualCoordinates == someCoordinates);
}

TEST_F(CoordinatesTests, equalOperatorShouldReturnFalse) {
    EXPECT_FALSE(someCoordinates == someNotEqualCoordinates1);
    EXPECT_FALSE(someCoordinates == someNotEqualCoordinates2);
    EXPECT_FALSE(someCoordinates == someNotEqualCoordinates3);
}
