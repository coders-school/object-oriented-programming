#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "alcohol.hpp"
#include "cargo.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "timeSHM.hpp"

using CargoIt = std::vector<std::shared_ptr<Cargo>>::iterator;

class Ship : public Observer {
public:
    Ship();
    Ship(size_t capacity,
         size_t maxCrew,
         size_t speed,
         const std::string& name,
         int id,
         std::shared_ptr<Time> publisher);
    ~Ship() {
        this->publisher_->removeObserver(this);
        std::cout << "Goodbye! I was your Ship\n";
    };

    void setName(const std::string& name);
    void load(std::shared_ptr<Cargo> cargo);
    void nextDay() override;



    Ship& operator-=(size_t crewman);
    Ship& operator+=(size_t crewman);

    size_t getCapacity() const;
    size_t getCrew() const;
    size_t getMaxCrew() const;
    size_t getSpeed() const;
    std::string getName() const;
    int getId() const;
    Cargo* getCargo(size_t index) const;
    Alcohol* findAlcoByName(const std::string& name);
    Fruit* findFruitByName(const std::string& name);
    Item* findItemByName(const std::string& name);
    size_t countAvailableSpace() const;
    size_t fillInCrew();
    void printCargo() const;

private:
    Cargo* findCargo(Cargo* cargo) const;
    Cargo* findCargoByName(const std::string& name) const;
    void removeCargo(Cargo* cargo);
    CargoIt Ship::findSameCargo(Cargo* cargo);
    template<typename T>
    CargoIt findIdenticalCargo(T* concreteCargo);

    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    int id_;
    std::vector<std::shared_ptr<Cargo>> cargo_;
    std::shared_ptr<Time> publisher_;
};
