#pragma once
#include <memory>
#include "cargo.hpp"
#include "ship.hpp"
#include "timeSHM.hpp"

class Coordinates;
class Player : public Observer{
public:

    Player(std::shared_ptr<Ship> ship, size_t money, size_t space, std::shared_ptr<Time> publisher);

    Player(std::shared_ptr<Ship> ship, std::shared_ptr<Time> publisher);
    
    ~Player(){
        this -> Publisher_ -> removeObserver(this);
        std::cout << "Goodbye! I was your Player\n";
    };

    size_t getMoney() const { return money_; }
    size_t getAvailableSpace() const { return availableSpace_; }
    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;
    void payCrew(size_t crew);
    void nextDay();
private:
    std::shared_ptr<Ship> ship_;
    std::shared_ptr<Time> publisher_;
    size_t money_;
    size_t availableSpace_;
    size_t countAvailableSpace();
};
