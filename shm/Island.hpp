#pragma once

class Island {
public:
    Island(int positionX, int positionY);

    bool operator==(const Island& island);

private:
    int positionX_;
    int positionY_;
};
