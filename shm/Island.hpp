#pragma once
#include <cstdint>
#include <iostream>
#include <string>
class Island {
public:
    using coordinateType = std::size_t;

    Island(coordinateType positionX, coordinateType positionY);

    class Coordinates {
    public:
        constexpr Coordinates(Island::coordinateType positionX, Island::coordinateType positionY)
            : positionX_{positionX}, positionY_{positionY} {}

        constexpr bool operator==(const Coordinates& other) const {
            return positionX_ == other.positionX_ and positionY_ == other.positionY_;
        }

        friend std::ostream& operator<<(std::ostream& out, const Coordinates& coords);

    private:
        const Island::coordinateType positionX_;
        const Island::coordinateType positionY_;
    };

    constexpr Coordinates getPosition() const {
        return position_;
    }

private:
    const Coordinates position_;
};

std::ostream& operator<<(std::ostream& out, const Island::Coordinates& coords);