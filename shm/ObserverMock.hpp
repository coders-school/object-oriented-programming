
#include "Observer.hpp"
#include "gmock/gmock.h"

struct ObserverMock : public Observer
{
    MOCK_METHOD0(NextDay, void());
};
