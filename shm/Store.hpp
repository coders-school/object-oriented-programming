#pragma once
#include <iostream>
#include <vector>
#include "Storable.hpp"
#include "alcohol.hpp"
#include "cargo.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "TimeEffectable.hpp"
#include "cargo.hpp"
#include <random>

class Time;

class Player;
//class Cargo;

enum class Response 
{
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space 
};

class Store: public Storable {
public:
    Store(int money, size_t availableSpace, Time* time);
    
    virtual ~Store();   
    Response buy(Cargo * cargo, size_t amount, Player* player);
    Response sell(Cargo * cargo, size_t amount, Player* player);

    Cargo * getCargo(size_t index) const override;
    Cargo * findMatchCargo(Cargo * cargo);
    std::vector<Cargo *> storeCargo;

    void addStoreCargo(Cargo *, size_t);
    void removeCargo(Cargo *, size_t);    
    void nextDay() override;
    void printStoreCargo();

    friend std::ostream& operator<<(std::ostream& out, const Store& store) {
        out << "Store: \n";
        for (auto el : store.storeCargo) {
            out << el->getCargoInfo();
        }

        return out;
    }
private:
    void SetUpRandomCargo(Time *time);
};
