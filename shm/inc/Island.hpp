#pragma once

#include <cstddef> 

class Island {
public:
    
    class Coordinates {
    public:
        Coordinates(size_t, size_t);
        bool operator==(const Coordinates&) const;
        size_t distance(const Coordinates& lhs, const Coordinates& rhs);
    private:
        const size_t positionX_ = 0;
        const size_t positionY_ = 0;
    };

    explicit Island(const Island::Coordinates&);
    Coordinates getCoordinates() const { return position_; }

private:
    const Coordinates position_;
};
