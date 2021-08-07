#pragma once

//Class responsible for coordinates on map
class Coordinates {
private:
    int positionX_;
    int positionY_;

public:
    Coordinates(int positionX, int positionY) {
        positionX_ = positionX;
        positionY_ = positionY;
    }
    Coordinates()
        : Coordinates(0, 0) {}

    const int GetPositionX() { return positionX_; }
    const int GetPositionY() { return positionY_; }

    void SetPositionX(const int& positionX) { positionX_ = positionX; }
    void SetPositionY(const int& positionY) { positionY_ = positionY; }

    bool operator==(const Coordinates) const;
};
