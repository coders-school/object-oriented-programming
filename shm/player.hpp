#pragma once
class Ship;

class Player {
private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
    size_t calculateAvSpace();

public:
    Player(std::shared_ptr<Ship> ship, size_t money)
        : ship_(ship), money_(money) {
        availableSpace_ = calculateAvSpace();
    }
    Player(std::shared_ptr<Ship> ship)
        : Player(ship, 0) {
        availableSpace_ = calculateAvSpace();
    }
    ~Player();

    std::shared_ptr<Ship> getShip() const;
    size_t getMoney() const;
    size_t getAvailableSpace();
    size_t getSpeed() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;
};
