#include "Time.hpp"
#include "Observer.hpp"
#include "gmock/gmock.h"

struct TimeMock : public Time
{
    MOCK_METHOD1(addObserver, void(Observer*));
    MOCK_METHOD1(removeObserver, void(Observer*));
};
