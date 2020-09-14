#pragma once

#include <ostream>

class Coordinates {
public:
    Coordinates();
    Coordinates(int positionX, int positionY);

    static int Distance(const Coordinates& pointA, const Coordinates& pointB);
    bool operator==(const Coordinates& currentPosition) const;

    int getPositionX() const { return positionX_; }
    int getPositionY() const { return positionY_; }

    friend std::ostream& operator<<(std::ostream& print, const Coordinates& cord);


private:
    const int positionX_;
    const int positionY_;
};
