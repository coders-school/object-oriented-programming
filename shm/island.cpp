#include "island.hpp"

void Island::Coordinates::setPositionX(int& positionX) {
    positionX = positionX_;
}
int Island::Coordinates::getPositionX() const {
    return positionX_;
}

void Island::Coordinates::setPositionY(int& positionY) {
    positionY = positionY_;
}
int Island::Coordinates::getPositionY() const {
    return positionY_;
}

bool Island::Coordinates::operator== (const Coordinates& n_pos) const {
    // if ( positionX_ == n_pos.positionX_ && positionY_ == n_pos.positionY_) {
    //     return true;
    // }
    // return false;
    return positionX_ == n_pos.positionX_ && positionY_ == n_pos.positionY_;
}

Island::Coordinates Island::getPosition() const {
    return position_;
}