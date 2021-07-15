#pragma once
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
class Island {
public:
    using coordinateType = std::size_t;

    Island(coordinateType positionX, coordinateType positionY);

    class Coordinates {
    public:
        static constexpr size_t distance(const Coordinates& lhs, const Coordinates& rhs) {
            auto pairX = std::minmax(lhs.positionX_, rhs.positionX_);
            auto pairY = std::minmax(lhs.positionY_, rhs.positionY_);
            auto result = std::sqrt(std::pow(pairX.second - pairX.first, 2) + std::pow(pairY.second - pairY.first, 2));
            return static_cast<size_t>(result);
        }

        constexpr Coordinates(Island::coordinateType positionX, Island::coordinateType positionY)
            : positionX_{positionX}, positionY_{positionY} {}

        constexpr bool operator==(const Coordinates& other) const {
            return positionX_ == other.positionX_ and positionY_ == other.positionY_;
        }

        friend std::ostream& operator<<(std::ostream& out, const Island::Coordinates& coords);

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
