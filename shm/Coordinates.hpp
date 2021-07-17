#ifndef COORDINATES_HPP
#define COORDINATES_HPP

class Coordinates {
private:
    size_t positionX_;
    size_t positionY_;

public:
    constexpr Coordinates(size_t positionX, size_t positionY);
    void setPositionX(size_t positionX) { positionX_ = positionX; };
    void setPositionY(size_t positionY) { positionY_ = positionY; };
    constexpr size_t getPositionX() const { return positionX_; };
    constexpr size_t getPositionY() const { return positionY_; };
    bool operator==(const Coordinates&);
};

#endif