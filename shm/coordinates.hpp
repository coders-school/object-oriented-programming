#pragma once

class Coordinates {
public:
    Coordinates();
    Coordinates(int positionX, int positionY);

    static int Distance(const Coordinates& currentX, const Coordinates& currentY);
    bool operator==(const Coordinates& currentPosition) const;

    int getPositionX() const { return positionX_; }
    int getPositionY() const { return positionY_; }

private:
    const int positionX_;
    const int positionY_;
};
