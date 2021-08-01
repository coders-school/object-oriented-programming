#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include <cstddef>

class Coordinates
{
private:
    size_t positionX_;
    size_t positionY_;

public:
    Coordinates(size_t positionX, size_t positionY)
        : positionX_(positionX), positionY_(positionY){};
    void setPositionX(size_t positionX) { positionX_ = positionX; };
    void setPositionY(size_t positionY) { positionY_ = positionY; };
    size_t getPositionX() const { return positionX_; };
    size_t getPositionY() const { return positionY_; };
    bool operator==(const Coordinates &);

    static size_t distance(const Coordinates &lhs, const Coordinates &rhs);
};

#endif