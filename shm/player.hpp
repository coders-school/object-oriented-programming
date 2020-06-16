#include <memory>

#include "ship.hpp"

size_t constexpr START_MONEY = 1000;
size_t constexpr START_SPACE = 0;

class Player {
  public:
    Player(Ship* ship, size_t money);
    Player(Ship* ship);

    size_t GetMoney() const { return money_; }
    size_t GetAvailableSpace() const { return availableSpace_; }
    size_t GetSpeed() const;
    Cargo GetCargo(size_t index) const;

  private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};