#pragma once

#include <cstddef> 

//class responsible for manage landmass in game
class Island {
public:

    //class responsible for manage coordinates of islands in game
    class Coordinates {
    public:
        Coordinates(size_t, size_t);
        bool operator==(const Coordinates&) const;
    private:
        const size_t positionX_ = 0;
        const size_t positionY_ = 0;
    };

    Coordinates getCoordinates() const { return position_; }
    
    Island(const Island::Coordinates&);

private:
    const Coordinates position_;
};
