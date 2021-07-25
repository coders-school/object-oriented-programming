#include <iostream>
#include <vector>
#include "Storable.hpp"
#include "alcohol.hpp"
#include "cargo.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "TimeEffectable.hpp"
#include "cargo.hpp"


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
    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);

    std::shared_ptr<Cargo> getCargo(size_t index) const override;
    std::shared_ptr<Cargo> findMatchCargo(std::shared_ptr<Cargo> cargo);
    std::vector<std::shared_ptr<Cargo>> storeCargo;

    void addStoreCargo(std::shared_ptr<Cargo>, size_t);
    void removeCargo(std::shared_ptr<Cargo>, size_t);    
    void nextDay() override;
    void printStoreCargo();

    friend std::ostream& operator<<(std::ostream& out, const Store& store) {
        out << "Store: \n";
        for (auto& el : store.storeCargo) {
            out << el.get()->getCargoInfo();
        }

        return out;
    }
};
