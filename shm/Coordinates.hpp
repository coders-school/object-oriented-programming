#pragma once

class Coordinates {
public:
    Coordinates(const int positionX,
                const int positionY)
        : _positionX(positionX), _positionY(positionY) {}

private:
    const int _positionX;
    const int _positionY;
};
