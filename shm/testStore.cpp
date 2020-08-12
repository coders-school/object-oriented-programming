#include "Cargo.hpp"
#include "Item.hpp"
#include "Store.hpp"

#include "gtest/gtest.h"

#include "TimeMock.hpp"
#include "ObserverMock.hpp"


using ::testing::_;

TEST(store, storeCargoShouldBeGenerated)
{
    ObserverMock obsMock;
    TimeMock timeMock;

    EXPECT_CALL(timeMock, addObserver(_));
    EXPECT_CALL(timeMock, removeObserver(_));
    Store storeA(&timeMock);

}
