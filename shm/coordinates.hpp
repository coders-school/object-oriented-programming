#pragma once

class Coordinates {
public:
    Coordinates() = default;
    Coordinates(int, int);
    bool operator==(const Coordinates&) const;

private:
    int positionX_{0};
    int positionY_{0};
};
