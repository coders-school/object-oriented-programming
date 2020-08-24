#include "Cargo.hpp"
#include "Item.hpp"
#include "Store.hpp"

#include "gtest/gtest.h"

#include "TimeMock.hpp"
#include "StoreMock.hpp"
#include "ObserverMock.hpp"


using ::testing::_;

TEST(store, observerShouldBeAddedWhenCargoCreated)
{
    testing::StrictMock<ObserverMock> obsMock;
    testing::StrictMock<TimeMock> timeMock;

    EXPECT_CALL(timeMock, addObserver(_));
    EXPECT_CALL(timeMock, removeObserver(_));
    Store storeA(timeMock);
}


TEST(store, CargosNestDayShouldBecalledWhenNextDayPasses)
{
    Time time_;
    testing::StrictMock<StoreMock> storeMock(&time_);
    EXPECT_CALL(storeMock, NextDay());
    ++time_;

}

