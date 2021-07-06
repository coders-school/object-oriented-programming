#pragma once

#include <cstddef> 

// class responsible for manage landmass in game
class Island {
public:

    // class responsible for manage coordinates of islands in game
    class Coordinates {
    public:
        Coordinates(size_t positionX, size_t positionY);
        bool operator==(const Coordinates& position) const;
        static size_t distance(const Coordinates& lhs, const Coordinates& rhs);
        size_t getPositionX() { return positionX_; }
        size_t getPositionY() { return positionY_; }

    private:
        const size_t positionX_ = 0;
        const size_t positionY_ = 0;
    };

    explicit Island(const Island::Coordinates& position);
    Coordinates getCoordinates() const { return position_; }
    
private:
    const Coordinates position_;
};
