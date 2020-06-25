#pragma once

class Island {
public:
    class Coordinates {
    public:
        Coordinates() = default;
        Coordinates(int positionX, int positionY);
        bool operator==(const Coordinates& rhs) const;

    private:
        int positionX_{};
        int positionY_{};
    };

    Island(int position_X, int position_Y);
    Coordinates getPosition() const { return position_; }

private:
    Coordinates position_;
};
