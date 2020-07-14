#include "island.hpp"

#include "globaltime.hpp"

Island::Island(int positionX, int positionY)
    : position_(positionX, positionY), store_(std::make_shared<Store>(GlobalTime::getGlobalTime())) {}

Island::Island(const Island& island)
    : position_(island.getPosition()), store_(island.getStore()) {}
