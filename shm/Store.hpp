#include <vector>
#include <iostream>
#include "Storable.hpp"
#include "alcohol.hpp"
#include "cargo.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "TimeEffectable.hpp"

class Player;
//class Cargo;

enum class Response {done, lack_of_money, lack_of_cargo, lack_of_space};

class Store: public Storable, public TimeEffectable {
public:
    Store(int money, size_t availableSpace) : Storable(money, availableSpace) {}
    //     cargo_.push_back(std::make_shared<Fruit>(0, "Banana", 10, 100, 0));// Fruit(size_t amount, const std::string& name, size_t base_price, size_t expiry_date, size_t time_elapsed)
    //     cargo_.push_back(std::make_shared<Fruit>(0, "Apple", 10, 100, 0));
    //     cargo_.push_back(std::make_shared<Alcohol>(0, "Wodka", 30, 70));// Alcohol(size_t amount, const std::string& name, size_t base_price, size_t percentage);
    //     cargo_.push_back(std::make_shared<Item>(0, "Hook", 50, Item::Rarity::common));//Item(size_t amount, const std::string &name, size_t base_price, Rarity rarity);

    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);

    std::shared_ptr<Cargo> getCargo(size_t index) const override;
    Cargo* findMatchCargo(Cargo* cargo);
    std::vector<std::shared_ptr<Cargo>> cargo_;
    void nextDay() override;
    
    void printStoreCargo() {
        for(auto el : cargo_) {
            el -> printCargo();
        }
    }
};