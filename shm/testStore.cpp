#include "Cargo.hpp"
#include "Item.hpp"
#include "Store.hpp"

#include "gtest/gtest.h"

#include "TimeMock.hpp"
#include "ObserverMock.hpp"


TEST(store, storeCargoShouldBeGenerated)
{

    ObserverMock* obs = new ObserverMock();
    TimeMock* timeMock_ptr = new TimeMock();
    EXPECT_CALL(*timeMock_ptr, addObserver());

    //Store storeA(timeMock_ptr);

}
