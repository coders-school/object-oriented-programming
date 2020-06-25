#pragma once

#include "gmock/gmock.h"

#include "island.hpp"

class MockIsland : public Island {
public:
    MOCK_METHOD(Coordinates, getPosition, (), (const));
};
