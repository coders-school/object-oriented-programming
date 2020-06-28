#include "alcohol.hpp"
#include "gtest/gtest.h"

class AlcoholTest : public ::testing::Test {
protected:
    AlcoholTest() : alco1_("Whisky", 5, 200, 48) {}
    Alcohol alco1_;
};

TEST_F(AlcoholTest, IncOperatorShouldAddToAmount) {
    auto amountValue = 5;
    auto oldAmount = alco1_.getAmount();

    alco1_ += amountValue;
    ASSERT_EQ(alco1_.getAmount(), amountValue + oldAmount);
}

TEST_F(AlcoholTest, DecOperatorShouldSubstractFromAmount) {
    auto amountValue = 4;
    auto oldAmount = alco1_.getAmount();

    alco1_ -= amountValue;
    ASSERT_EQ(alco1_.getAmount(), oldAmount - amountValue);
}

TEST_F(AlcoholTest, DecOperatorShouldBeNowLowerThanZero) {
    auto amountValue = 100;
    auto oldAmount = alco1_.getAmount();

    alco1_ -= amountValue;
    ASSERT_EQ(alco1_.getAmount(), 0);
}
