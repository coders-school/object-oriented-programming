#pragma once

#include "Player.hpp"
#include <iostream>

enum class Response { done,
                      lack_of_money,
                      lack_of_cargo,
                      lack_of_space };

using StoreCargoVec = std::vector<std::unique_ptr<Cargo>>;

class Store {
public:
    Store(){}

    //store buy from player
    Response buy(Cargo* cargo, size_t amount, Player* player);
    //store sell to player
    Response sell(Cargo* cargo, size_t amount, Player* player);

    //void nextDay();

    size_t getCargoNum(){
        return cargoVec_.size();
    }
//private:

    //take responsible for deleting object
    void load(std::unique_ptr<Cargo> cargo);

    //release responsible for deleting object if have it
    void unload(const Cargo* const cargo);

    friend std::ostream& operator<<(std::ostream&, const Store&);
    //find comperable cargo in store
    Cargo* findCargoInStore(const Cargo* const exampleCargo) const;
private:
    
    StoreCargoVec cargoVec_{};
};

std::ostream& operator<<(std::ostream& out, const Store& store);