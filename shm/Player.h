#include <memory>

#include "Cargo.h"
#include "Ship.h"

class Player {
public:
    Player(Ship ship, size_t money);

    Ship* getShip() const;
    size_t getMoney() const;
    void setMoney(size_t amount);
    size_t getAvailableSpace() const;
    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;
    std::vector<std::shared_ptr<Cargo>> getCargos() const;

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t available_space_;
    void checkAvailableSpace();
};
