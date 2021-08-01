#include "coordinates.hpp"

bool Coordinates::operator==(const Coordinates c) const
{
    return positionX_ == c.positionX_ && positionY_ == c.positionY_;
}
