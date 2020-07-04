#pragma once
#include <memory>
#include "cargo.hpp"
#include "ship.hpp"
#include "timeSHM.hpp"

class Coordinates;
class Player : public Observer{
public:
    Player(Ship* ship, size_t money, size_t space, Time* Publisher);

    Player(Ship* ship, Time* Publisher);
    
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
    Ship* ship_;
    size_t money_;
    size_t availableSpace_;
    size_t countAvailableSpace();
    Coordinates* ActualPosition;
    Time* Publisher_;
};
