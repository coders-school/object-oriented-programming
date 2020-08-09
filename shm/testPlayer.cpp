#include <vector>
#include <set>

#include "Player.hpp"
#include "ShmExceptions.hpp"
#include "gtest/gtest.h"

TEST(player, CrewPayedWhenDayPasses)
{
    size_t space_ = 10;
    size_t money_ = 10;
    size_t crew = 10;
    Player player(std::make_unique<Ship>(crew, 1, 1), money_, space_);
    player.getShip()->NextDay();
    EXPECT_EQ(player.getMoney(), money_ - crew);
}

TEST(player, NotEnoughMoneyToPayCrew)
{
    size_t space_ = 10;
    size_t money_ = 10;
    size_t crew = 100;
    Player player(std::make_unique<Ship>(crew, 1, 1), money_, space_);
    EXPECT_THROW(player.getShip()->NextDay(), AmountException);
}

TEST(player, NewSpaceWasSet)
{
    size_t space_ = 10;
    size_t money_ = 1;
    Player player(std::make_unique<Ship>(), money_, space_);
    EXPECT_EQ(player.getAvailableSpace(), space_);
}

TEST(player, MoneyShouldBeIncreasedAfterErn)
{
    size_t space_ = 10;
    size_t money_ = 1;
    Player player(std::make_unique<Ship>(), money_, space_);
    size_t moreMoney_ = 100;
    player.earnMoney(moreMoney_);
    EXPECT_EQ(player.getMoney(), money_ + moreMoney_);
}

TEST(player, MoneyShouldBeDecreasedAfterSpend)
{
    size_t space_ = 10;
    size_t money_ = 1000;
    Player player(std::make_unique<Ship>(), money_, space_);
    size_t spentMoney_ = 100;
    player.spendMoney(spentMoney_);
    EXPECT_EQ(player.getMoney(), money_ - spentMoney_);
}

TEST(player, SpendMoreMoneyThanHaveShouldResultException)
{
    size_t space_ = 10;
    size_t money_ = 100;
    Player player(std::make_unique<Ship>(), money_, space_);
    size_t spentMoney_ = 1000;
    EXPECT_THROW(player.spendMoney(spentMoney_), AmountException);
}

TEST(player, NewMoneyAmountWasSet)
{
    size_t space_ = 0;
    size_t money_ = 0;
    Player player(std::make_unique<Ship>(), money_, space_);
    size_t money = 10;
    player.setMoney(money);
    EXPECT_EQ(player.getMoney(), money);
}
