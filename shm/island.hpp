#include "coordinates.hpp"

class Island {
private:
    Coordinates position_;

public:
    Island(Coordinates position) {
        position_ = position;
    }
    Coordinates GetPosition() { return position_; }
    void SetPosition(const Coordinates& position) { position_ = position; }
};