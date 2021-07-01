#pragma once
#include <cstdint>
#include <string>
#include <iostream>
class Island {
public:
    using coordinateType = std::size_t;

    Island(coordinateType positionX, coordinateType positionY);

    class Coordinates {
    public:
        constexpr Coordinates(Island::coordinateType positionX, Island::coordinateType positionY);
        friend std::ostream& operator<<(std::ostream& out, const Coordinates& coords);
        bool operator==(const Coordinates& other) const;
    private:
        const Island::coordinateType positionX_;
        const Island::coordinateType positionY_;
    };

    constexpr Coordinates getPosition() const{
        return position_;
    }
private:
    const Coordinates position_;
};

std::ostream& operator<<(std::ostream& out, const Island::Coordinates& coords);