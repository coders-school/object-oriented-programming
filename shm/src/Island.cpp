#include "shm/inc/Island.hpp"

#include <cmath>

Island::Coordinates::Coordinates(size_t positionX, size_t positionY) 
    : positionX_(positionX)
    , positionY_(positionY)
{}

bool Island::Coordinates::operator==(const Coordinates& position) const {
    return (positionX_ == position.positionX_ && positionY_ == position.positionY_); 
}

Island::Island(const Island::Coordinates& position, const size_t & storeSize, Time* time)
    : position_(position)
{
    store_ = std::make_shared<Store>(storeSize, time);
}

size_t Island::Coordinates::distance(const Coordinates& lhs, const Coordinates& rhs) {
    size_t result = static_cast<size_t>(std::sqrt(std::pow((int)lhs.positionX_ - (int)rhs.positionX_, 2) + std::pow((int)lhs.positionY_ - (int)rhs.positionY_, 2)));
    return result;
}