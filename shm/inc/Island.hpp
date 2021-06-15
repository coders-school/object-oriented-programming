#pragma once

class Island {
public:
    class Coordinates {
    public:
        Coordinates(int, int);
        bool operator==(const Coordinates&);
    private:
        const int positionX_;
        const int positionY_;
    };

    Coordinates getCoordinates() const { return position_; }
    
private:
    const Coordinates position_;
};