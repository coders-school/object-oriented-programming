#pragma once

#include <vector>

class Coordinates
{
public:
    Coordinates()
        : positionX_(0), positionY_(0)
    {}
    Coordinates(int positionX, int positionY)
        : positionX_(positionX)
        , positionY_(positionY)
    {}
    //operator porownania
    // OBWÓD ZIEMI = 360° X 60′ => 21 600 NM
    // 1 NM = 1,852 KM
    // 21 600 NM = 40 TYS. KM
    // x 0 - 360
    // y 0 - 360

    //x  W-180 0 180E
    //y N180
    // 0
    //-180S

private:
    int positionX_;
    int positionY_;
    std::vector<int> position_;
};