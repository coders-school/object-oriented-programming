#include "Store.hpp"
#include "Time.hpp"
#include "gmock/gmock.h"

struct StoreMock : public Store
{
    MOCK_METHOD0(NextDay, void());
    MOCK_METHOD1(Store, void(Time*));
};
