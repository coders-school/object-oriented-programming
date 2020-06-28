#pragma once

#include <cstddef>  // for size_t

class Island {
public:
    class Coordinates {
    public:
        Coordinates() = default;
        Coordinates(size_t positionX, size_t positionY);

        // for testing
        size_t getPositionX() const { return positionX_; };
        size_t getPositionY() const { return positionY_; };

        bool operator==(const Coordinates& rhs) const;

    private:
        size_t positionX_{};
        size_t positionY_{};
    };

    Island(size_t position_X, size_t position_Y);
    Coordinates getPosition() const { return position_; }

private:
    Coordinates position_{};
};
