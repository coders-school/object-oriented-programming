#include "coordinates.hpp"

void Coordinates::setPositionX(int positionX) {
    positionX = positionX_;
}
int Coordinates::getPositionX() const {
    return positionX_;
}

void Coordinates::setPositionY(int positionY) {
    positionY = positionY_;
}
int Coordinates::getPositionY() const {
    return positionY_;
}

bool Coordinates::operator== (const Coordinates n_pos) const {
    return positionX_ == n_pos.positionX_ && positionY_ == n_pos.positionY_;
}