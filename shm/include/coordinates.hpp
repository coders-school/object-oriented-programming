#pragma once

class Coordinates {
public:
    Coordinates(int positionX, int positionY);
    bool operator==(const Coordinates& other);

private:
    int positionX_;
    int positionY_;
};
