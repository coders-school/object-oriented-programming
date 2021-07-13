#pragma once

#include <iostream>
#include "Player.hpp"
#include "Time.hpp"
#include "Timeable.hpp"

enum class Response { done,
                      lack_of_money,
                      lack_of_cargo,
                      lack_of_space };

using StoreCargoVec = std::vector<std::unique_ptr<Cargo>>;

class Store : public Timeable {
public:
    Store():Timeable(){}
    virtual ~Store();

    //store buy from player
    Response buy(Cargo* cargo, size_t amount, Player* player);
    //store sell to player
    Response sell(Cargo* cargo, size_t amount, Player* player);

    void nextDay() override;

    size_t getCargoNum() {
        return cargoVec_.size();
    }
//private:

    void load(std::unique_ptr<Cargo> cargo);

    void unload(const Cargo* const cargo);

    friend std::ostream& operator<<(std::ostream&, const Store&);
    //find comperable cargo in store
    Cargo* findCargoInStore(const Cargo* const exampleCargo) const;

//private:
    StoreCargoVec cargoVec_{};
};

std::ostream& operator<<(std::ostream& out, const Store& store);
