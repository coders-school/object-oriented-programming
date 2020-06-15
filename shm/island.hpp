#pragma once

class Coordinates {
public:
    Coordinates(int, int);
private:
    int positionX;
    int positionY;
};

class Island {
public:
    Coordinates getPosition();
    //bool operator==()
private:
    Coordinates position_;
};
