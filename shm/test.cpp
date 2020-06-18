#include <vector>

#include "Cargo.hpp"
#include "gtest/gtest.h"

TEST(cargo, TwoCargosWithTheSameAmountShouldBeEqual) {
  Cargo cargoA, cargoB;
  cargoA += 10;
  cargoB += 10;
  ASSERT_EQ(cargoA, cargoB);
}

TEST(cargo, TwoCargosWithDifferentAmountShouldNotBeEqual) {
  Cargo cargoA, cargoB;
  cargoA += 10;
  cargoB += 100;
  ASSERT_NE(cargoA, cargoB);
}
