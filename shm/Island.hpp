#pragma once
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
class Island {
public:
    using CoordinateType = std::size_t;
    class Position;

    Island(CoordinateType coordinateX, CoordinateType coordinateY);
    Island(Position position);

    class Position {
    public:
        constexpr Position(Island::CoordinateType coordinateX, Island::CoordinateType coordinateY)
            : coordinateX_{coordinateX}, coordinateY_{coordinateY} {}

        constexpr bool operator==(const Position& other) const {
            return coordinateX_ == other.coordinateX_ and coordinateY_ == other.coordinateY_;
        }

        friend std::ostream& operator<<(std::ostream& out, const Island::Position& position);

        static constexpr size_t distance(const Position& lhs, const Position& rhs) {
            auto pairX = std::minmax(lhs.coordinateX_, rhs.coordinateX_);
            auto pairY = std::minmax(lhs.coordinateY_, rhs.coordinateY_);
            auto result = std::sqrt(std::pow(pairX.second - pairX.first, 2) + std::pow(pairY.second - pairY.first, 2));
            return static_cast<size_t>(result);
        }

    private:
        const Island::CoordinateType coordinateX_;
        const Island::CoordinateType coordinateY_;
    };

    constexpr Position getPosition() const {
        return position_;
    }

private:
    const Position position_;
};

std::ostream& operator<<(std::ostream& out, const Island::Position& position);
