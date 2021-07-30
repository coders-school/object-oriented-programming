#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include <cstddef>

class Coordinates
{
private:
    const size_t positionX_;
    const size_t positionY_;

public:
    constexpr Coordinates(size_t positionX, size_t positionY)
        : positionX_(positionX), positionY_(positionY){};
    //void setPositionX(size_t positionX) { positionX_ = positionX; };
    //void setPositionY(size_t positionY) { positionY_ = positionY; };
    constexpr size_t getPositionX() const { return positionX_; };
    constexpr size_t getPositionY() const { return positionY_; };
    bool operator==(const Coordinates &);

    static size_t distance(const Coordinates &lhs, const Coordinates &rhs);
};

#endif