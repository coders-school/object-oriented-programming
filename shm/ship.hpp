#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "cargo.hpp"

class Ship {
public: 
    Ship();
    Ship(int capacity, int maxCrew, int speed, const std::string& name, int id);
    Ship(int maxCrew, int speed, size_t id);
    void setName(const std::string& name); 
    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);
    size_t getCapacity() const;  
    size_t getMaxCrew() const; 
    size_t getSpeed() const;
    std::string getName() const;
    int getId() const;
        
    ​void load(std::unique_ptr<Cargo> cargo) { 
        cargo_.push_back(std::move(cargo));
    }
    //wziąć pod uwagę available space - countFreeSpace w klasie player!
    //porównanie dwóch towarów - akumulacja tych samych typów towarów
    //czy zmiesci sie caly towar (maxcapacity?)

    void unload(Cargo* cargo) {
        auto it = find_if(cargo_.begin(), cargo_.end(), [cargo](const auto& ptr) {
            return ptr.get() == cargo;
        });

        if (it != cargo_.end())
            cargo_.erase(it);
    }
  //sprawdzić ilość czy jest 0 - usuwamy
  //ile zostanie towaru

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const int id_;
    std::vector<std::unique_ptr<Cargo>> cargo_;
};
