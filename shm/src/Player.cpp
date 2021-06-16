#include "Player.hpp"

class Player {
public:
    explicit Player(std::shared_ptr<Ship> ship, size_t money, size_t availableSpace)
        : 
     
    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;

};