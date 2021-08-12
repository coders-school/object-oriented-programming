#ifndef SHIP_HPP
#define SHIP_HPP
#include <memory>
#include <string>
#include <vector>
#include "Cargo.hpp"

// Class used to represent merchant ship in the game
class Ship
{
private:
    const size_t id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;
    std::vector<std::unique_ptr<Cargo>> cargoList_;

    Cargo* findCargo(Cargo* cargo);
    void removeFromStorage(Cargo* cargo);

public:
    Ship();
    Ship(int capacity, int maxCrew, int speed, const std::string &name, size_t id);
    Ship(int maxCrew, int speed, size_t id);

    size_t getCapacity() const { return capacity_; }
    size_t getMaxCrew() const { return maxCrew_; }
    size_t getSpeed() const { return speed_; }
    std::string getName() const { return name_; }
    size_t getId() const { return id_; }
    Cargo* getCargo(size_t index) const { return cargoList_[index].get(); };
    size_t calculateCargoAmount();
    void printCargolist();
    void nextDay();

    void setName(const std::string &name);
    void load(std::unique_ptr<Cargo> cargo);
    void unload(Cargo* cargo);

    Ship &operator-=(size_t num);
    Ship &operator+=(size_t num);
};

#endif