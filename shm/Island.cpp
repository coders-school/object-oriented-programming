    #include "Island.hpp"

    Island::Island(int positionX, int positionY)
        : positionX_(positionX)
        , positionY_(positionY)
    {}

    bool Island::operator==(const Island& island) {
        return ((positionX_ == island.positionX_) &&
                (positionY_ == island.positionY_));
    }
