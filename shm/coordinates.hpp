#pragma once

class Coordinates {
private:
    float positionX_;
    float positionY_;

public:
    Coordinates(float positionX, float positionY) {
        positionX_ = positionX;
        positionY_ = positionY;
    }
    Coordinates()
        : Coordinates(0.f, 0.f) {}

    float GetPositionX() { return positionX_; }
    float GetPositionY() { return positionY_; }

    void SetPositionX(const float& positionX) { positionX_ = positionX; }
    void SetPositionY(const float& positionY) { positionY_ = positionY; }

    bool operator==(const Coordinates& c1) const;
    
};
