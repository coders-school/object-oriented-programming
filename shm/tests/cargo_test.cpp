#include <string>

#include "gtest/gtest.h"

#include "../cargo.hpp"

const std::string testCargoName = "testCargo";
constexpr size_t testCargoAmount = 100;
constexpr size_t testCargoBasePrice = 200;

TEST(cargoTest, ConstructorAndGettersTest) {
    Cargo testCargo(testCargoName, testCargoAmount, testCargoBasePrice);
    ASSERT_EQ(testCargo.getName(), testCargoName);
    ASSERT_EQ(testCargo.getAmount(), testCargoAmount);
    ASSERT_EQ(testCargo.getBasePrice(), testCargoBasePrice);
}
