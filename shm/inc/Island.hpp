#pragma once

#include <cstddef> 

class Island {
public:
    class Coordinates {
    public:
        Coordinates(size_t positionX, size_t positionY);
        bool operator==(const Coordinates& position) const;
        static size_t distance(const Coordinates& lhs, const Coordinates& rhs);
    private:
        const size_t positionX_ = 0;
        const size_t positionY_ = 0;
    };

    Coordinates getCoordinates() const { return position_; }
    
    Island(const Island::Coordinates& position);

private:
    const Coordinates position_;
};
