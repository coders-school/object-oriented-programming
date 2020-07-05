#pragma once

#include <memory>
#include <string>
#include <vector>

#include "alcohol.hpp"
#include "fruit.hpp"
#include "cargo.hpp"
#include "item.hpp"

class Ship {
public: 
    Ship();
    Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, int id);
    Ship(size_t maxCrew, size_t speed, int id);
    void setName(const std::string& name);
    void load(Alcohol* cargo);
    void load(Fruit* cargo);
    void load(Item* cargo);
    void removeAlco(Alcohol* cargo);
    void removeFruit(Fruit* cargo);
    void removeItem(Item* cargo);
    
    Ship& operator-=(size_t crewman);
    Ship& operator+=(size_t crewman);

    size_t getCapacity() const;  
    size_t getCrew() const;
    size_t getMaxCrew() const; 
    size_t getSpeed() const;
    std::string getName() const;
    int getId() const;
    Cargo* getCargo(size_t index) const;
    Alcohol* findAlcoByName(const  std::string& name);
    Fruit*   findFruitByName(const std::string& name);
    Item*    findItemByName(const  std::string& name);
    size_t countAvailableSpace() const;
    void   printCargo() const;
private:
    Cargo* findCargo(Cargo* cargo);
    template<typename T>  T findCargoByName(const std::string& name,
                                            std::vector<T>& where);
    template<typename T>  void  removeCargo(T cargo,std::vector<T>& where);
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    int id_;
    std::vector<Cargo*> cargo_;
    std::vector<Alcohol*> alcos_;
    std::vector<Fruit*> fruits_;
    std::vector<Item*> items_;
};
