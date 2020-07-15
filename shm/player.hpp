#pragma once

#include <memory>
#include "cargo.hpp"
#include "ship.hpp"
#include "timeSHM.hpp"


class Coordinates;
class Player : public Observer {
public:
    Player(std::shared_ptr<Ship> ship, size_t money, size_t space, std::shared_ptr<Time> publisher);

    ~Player() {
        this->publisher_->removeObserver(this);
        std::cout << "Goodbye! I was your Player\n";
    };

    size_t getMoney() const { return money_; }
    void giveMoney(size_t money);
    void takeMoney(size_t money);
    size_t getAvailableSpace();
    size_t getSpeed() const;
    void removeCargo(std::shared_ptr<Cargo> cargo);
    Fruit* getFruitWithName(const std::string& name);
    Item* getItemWithName(const std::string& name);
    Cargo* getCargo(size_t index) const;
    void payCrew(size_t crew);
    void nextDay();
    void purchaseCargo(std::shared_ptr<Cargo> cargo, size_t price, size_t amount);

private:
    std::shared_ptr<Ship> ship_;
    std::shared_ptr<Time> publisher_;
    size_t money_;
    size_t availableSpace_;
};
