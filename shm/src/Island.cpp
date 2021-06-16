#include "Island.hpp"

Island::Island(const Island::Coordinates& position)
    : position_(position)
{}

Island::Coordinates::Coordinates(int positionX, int positionY) 
    : positionX_(positionX)
    , positionY_(positionY)
{}

bool Island::Coordinates::operator==(const Coordinates& position) const {
    return (positionX_ == position.positionX_ && positionY_ == position.positionY_); 
}
