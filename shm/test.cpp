#include "gtest/gtest.h"
#include "Cargo.hpp"

#include <string>

class CargoTests : public ::testing::Test {
protected:
    void SetUp() override {
        cargo1 = new Cargo(firstCommodity, cargoQuantity, cargoBasePrice);
        cargo2 = new Cargo(firstCommodity, cargoQuantity, cargoBasePrice);
        cargo3 = new Cargo(secondCommodity, cargoQuantity, cargoBasePrice);
    }
    void TearDown() override {
        delete cargo1;
        delete cargo2;
        delete cargo3;
    }
    Cargo* cargo1;
    Cargo* cargo2;
    Cargo* cargo3;
    const size_t cargoQuantity = 100;
    const size_t cargoBasePrice = 20;
    const std::string firstCommodity = "bananas";
    const std::string secondCommodity = "nuts";
};

TEST_F(CargoTests, EqualOperatorShouldReturnTrue) {
    EXPECT_TRUE(*cargo1 == *cargo2);
    EXPECT_TRUE(*cargo2 == *cargo1);
}

TEST_F(CargoTests, EqualOperatorShouldReturnFalse) {
    EXPECT_FALSE(*cargo1 == *cargo3);
    EXPECT_FALSE(*cargo3 == *cargo1);
}
