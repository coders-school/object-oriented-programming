#include <vector>
#include <iostream>
#include "Storable.hpp"
#include "cargo.hpp"

class Player;
//class Cargo;

enum class Response {done, lack_of_money, lack_of_cargo, lack_of_space};

class Store: public Storable {
public:
    Store(int money, size_t availableSpace);

    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);

    std::shared_ptr<Cargo> getCargo(size_t index) const override;
    Cargo* findMatchCargo(Cargo* cargo);
    std::vector<std::shared_ptr<Cargo>> cargo_;
    
    void printStoreCargo() {
        for(auto el : cargo_) {
            el -> printCargo();
        }
    }
};