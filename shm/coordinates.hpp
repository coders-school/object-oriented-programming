#pragma once

class Coordinates {
private:
    int positionX_;
    int positionY_;

public:
    Coordinates()
        : positionX_(0)
        , positionY_(0)
    {}
    Coordinates(int positionX, int positionY)
        : positionX_(positionX)
        , positionY_(positionY)
    {}

    int getPositionX() const { return positionX_; }
    int getPositionY() const { return positionY_; }
    bool operator==(const Coordinates& other) const;
};