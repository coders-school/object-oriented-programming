#pragma once

#include <stdint.h>

#include <iomanip>

class Coordinates {
    uint16_t positionX_;
    uint16_t positionY_;

public:
    Coordinates() = default;
    Coordinates(uint16_t, uint16_t);

    uint16_t getPositionX() const;
    uint16_t getPositionY() const;

    static uint16_t Distance(const Coordinates&, const Coordinates&);

    bool operator==(const Coordinates&) const;
    friend std::ostream& operator<<(std::ostream&, const Coordinates&);
};