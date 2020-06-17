#pragma once

class Coordinates {
public:
    Coordinates() = default;
    Coordinates(int positionX, int positionY);
    bool operator==(const Coordinates& rhs) const;

private:
    int positionX_{0};
    int positionY_{0};
};
