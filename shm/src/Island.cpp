#include "../inc/Island.hpp"

Island::Coordinates::Coordinates(int positionX, int positionY) 
    : positionX_(positionX)
    , positionY_(positionY)
{}

bool Island::Coordinates::operator==(const Coordinates& position) {
    return (positionX_ == position.positionX_ && positionY_ == position.positionY_); 
}