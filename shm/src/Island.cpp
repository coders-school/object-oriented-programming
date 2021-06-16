#include "inc/Island.hpp"

Island::Coordinates::Coordinates(size_t positionX, size_t positionY) 
    : positionX_(positionX)
    , positionY_(positionY)
{}

bool Island::Coordinates::operator==(const Coordinates& position) const {
    return (positionX_ == position.positionX_ && positionY_ == position.positionY_); 
}
