#pragma once

class Coordinates {
public:
    Coordinates(int, int);
    bool operator==(const Coordinates& pos) const {
        return positionX == pos.positionX && positionY == pos.positionY;
    }
private:
    int positionX;
    int positionY;
};

class Island {
public:
    Coordinates getPosition();
private:
    Coordinates position_;
};
