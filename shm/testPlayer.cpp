#include <vector>
#include <set>

#include "Player.hpp"
#include "ShmExceptions.hpp"
#include "TimeMock.hpp"
#include "Time.hpp"
#include "gtest/gtest.h"

using ::testing::_;

class PlayerTestSuite : public ::testing::Test
{
public:
    PlayerTestSuite() : m_sut(std::make_unique<Ship>(defaultCrew_, 1, 1, time_), defaultMoney_, defaultSpace_) {}
    Time time_;

    testing::StrictMock<TimeMock> timeMock;
    size_t defaultSpace_ = 10;
    size_t defaultMoney_ = 10;
    size_t defaultCrew_ = 10;
    Player m_sut;
};

void BuildPlayerWithTimeMock()
{
}

TEST_F(PlayerTestSuite, CrewPayedWhenDayPasses)
{
    ++time_;
    EXPECT_EQ(m_sut.getMoney(), defaultMoney_ - defaultCrew_);
}

TEST(PlayerWithTimeMock, WhenPlayerBuildObserversAdded)
{
    size_t space_ = 10;
    size_t money_ = 1;
    size_t crew = 10;
    testing::StrictMock<TimeMock> timeMock;
    EXPECT_CALL(timeMock, addObserver(_));
    EXPECT_CALL(timeMock, removeObserver(_));
    Player player(std::make_unique<Ship>(crew, 1, 1, timeMock), money_, space_);
}

TEST_F(PlayerTestSuite, NotEnoughMoneyToPayCrew)
{
    m_sut.setMoney(1);
    EXPECT_THROW(++time_, AmountException);
}

TEST_F(PlayerTestSuite, NewSpaceWasSet)
{
    EXPECT_EQ(m_sut.getAvailableSpace(), defaultSpace_);
}

TEST_F(PlayerTestSuite, MoneyShouldBeIncreasedAfterErn)
{
    size_t moreMoney_ = 100;
    m_sut.earnMoney(moreMoney_);
    EXPECT_EQ(m_sut.getMoney(), defaultMoney_ + moreMoney_);
}

TEST_F(PlayerTestSuite, MoneyShouldBeDecreasedAfterSpend)
{
    size_t spentMoney_ = 1;
    m_sut.spendMoney(spentMoney_);
    EXPECT_EQ(m_sut.getMoney(), defaultMoney_ - spentMoney_);
}

TEST_F(PlayerTestSuite, SpendMoreMoneyThanHaveShouldResultException)
{
    size_t spentMoney_ = defaultMoney_ + 1000;
    m_sut.spendMoney(spentMoney_);
    EXPECT_THROW(m_sut.spendMoney(spentMoney_), AmountException);
}

TEST_F(PlayerTestSuite, NewMoneyAmountWasSet)
{
    size_t money = 10;
    m_sut.setMoney(money);
    EXPECT_EQ(m_sut.getMoney(), money);
}
