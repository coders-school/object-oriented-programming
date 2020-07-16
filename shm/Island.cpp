    #include "Island.hpp"

    Island::Island()
        : position_(Coordinates(0,0))
    {}
    Island::Island(int positionX, int positionY)
        : position_(Coordinates(positionX, positionY))
    {}

    bool Island::operator==(const Island& island) {
        return (*this).getPosition() == island.getPosition();
    }

    Coordinates Island::getPosition() const {
        return position_;
    }
