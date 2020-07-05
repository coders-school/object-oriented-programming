#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "alcohol.hpp"
#include "fruit.hpp"
#include "cargo.hpp"
<<<<<<< HEAD
#include "timeSHM.hpp"

class Ship : public Observer {
=======
#include "item.hpp"
>>>>>>> 19bdb27b774442ba226fd5e1ee020abfe8ca221b

public: 
    Ship();
<<<<<<< HEAD
    Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, int id, std::shared_ptr<Time> publisher);
    //Ship(size_t maxCrew, size_t speed, int id);
    ~Ship(){
        this->publisher_->removeObserver(this);
        std::cout << "Goodbye! I was your Ship\n";
    };
    void setName(const std::string& name); 
    void load(Cargo* cargo);
   // void unload(Cargo* cargo);
   void nextDay() override; 
=======
    Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, int id);
    Ship(size_t maxCrew, size_t speed, int id);
    void setName(const std::string& name);
    void load(Alcohol* cargo);
    void load(Fruit* cargo);
    void load(Item* cargo);
    void removeAlco(Alcohol* cargo);
    void removeFruit(Fruit* cargo);
    void removeItem(Item* cargo);
    
>>>>>>> 19bdb27b774442ba226fd5e1ee020abfe8ca221b
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
<<<<<<< HEAD
    size_t fillInCrew();
    void printCargo() const;
    
=======
    void   printCargo() const;
>>>>>>> 19bdb27b774442ba226fd5e1ee020abfe8ca221b
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
<<<<<<< HEAD
    std::shared_ptr<Time> publisher_;
=======
    std::vector<Alcohol*> alcos_;
    std::vector<Fruit*> fruits_;
    std::vector<Item*> items_;
>>>>>>> 19bdb27b774442ba226fd5e1ee020abfe8ca221b
};
