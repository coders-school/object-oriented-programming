#pragma once

class Coordinates {
public:
    Coordinates();
    Coordinates(int positionX, int positionY);

    bool operator==(const Coordinates& coords);

private:
    int positionX_;
    int positionY_;
};
