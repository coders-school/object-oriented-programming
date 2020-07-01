#pragma once
#include <memory>

#include "Cargo.hpp"
#include "Observer.hpp"
#include "Ship.hpp"

class Player : public Delegate {
public:
    Player(Ship ship, size_t money);

    size_t getMoney() const { return _money; }
    size_t getAvailableSpace() const { return _availableSpace; }
    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;

    // override from Delegate
    void payCrew(size_t money) override;

private:
    std::unique_ptr<Ship> _ship;
    size_t _money;
    size_t _availableSpace;

    void updateAvailableSpace();
};
