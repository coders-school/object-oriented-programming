#pragma once
class Coordinates {
private:
    int positionX_;
    int positionY_;

public:
    Coordinates();
    Coordinates(int, int);

    int getPositionX() const { return positionX_; }
    int getPositionY() const { return positionY_; }
    bool operator==(const Coordinates& other) const;
};