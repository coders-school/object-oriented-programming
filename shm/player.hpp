#pragma once

#include <memory>
#include "cargo.hpp"
#include "ship.hpp"
#include "timeSHM.hpp"


class Coordinates;
class Player : public Observer{
public:

    Player(std::shared_ptr<Ship> ship, size_t money, size_t space, std::shared_ptr<Time> publisher);
    
    ~Player(){
        this->publisher_->removeObserver(this);
        std::cout << "Goodbye! I was your Player\n";
    };

    size_t getMoney() const { return money_; }
    void   giveMoney(size_t money);
    void   takeMoney(size_t money);
    size_t getAvailableSpace();
    size_t getSpeed() const;
    void   giveCargo(Alcohol* cargo);
    void   giveCargo(Fruit* cargo);
    void   giveCargo(Item* cargo);
    void   removeAlco (Alcohol* cargo);
    void   removeFruit(Fruit* cargo);
    void   removeItem (Item* cargo);
    Alcohol* getAlcoWithName(const  std::string& name);
    Fruit*   getFruitWithName(const std::string& name);
    Item*    getItemWithName(const  std::string& name);
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
