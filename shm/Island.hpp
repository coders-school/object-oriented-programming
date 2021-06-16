#pragma once
#include <cstdint>

using coordinateType = std::size_t;

class Island {
public:
    Island(coordinateType positionX, coordinateType positionY);

    class Coordinates {
    public:
        Coordinates(coordinateType positionsX, coordinateType positionY);

        bool operator==(const Coordinates& other) const;

    private:
        const coordinateType positionX_;
        const coordinateType positionY_;
    };

    Coordinates getPosition() const;

private:
    const Coordinates position_;
};