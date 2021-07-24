#pragma once

#include <memory>
#include <vector>

#include "shm/inc/Item.hpp"
#include "shm/inc/Subscriber.hpp"
#include "shm/inc/Time.hpp"

class Cargo;
class Player;

using CargoStorage = std::vector<std::unique_ptr<Cargo>>;

constexpr size_t MIN_CARGO_IN_STORE{ 0 };
constexpr size_t MAX_CARGO_IN_STORE{ 100 };
constexpr size_t STORE_CAPACITY { 1000 };

class Store : public Subscriber {
public:
    explicit Store(const size_t & storeSize, Time* time);
    enum class Response {
        done, 
        lack_of_money, 
        lack_of_cargo, 
        lack_of_space
    };

    friend std::ostream& operator<<(std::ostream& out, const Store& store);

    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);
    Cargo* getCargo(const std::string& name) const;
    CargoStorage::iterator findCargoInStore(Cargo* cargo);
    CargoStorage& getCargoStorage() { return cargo_; };
    void cargoFromShip(Cargo* cargo, size_t amount);
    void cargoToShip(Cargo* cargo, size_t amount);
    void removeCargo(Cargo* cargo);
    void addCargo(Cargo* cargo, size_t amount);

    // override from Subscriber
    void nextDay() override;
    size_t randomGenerate(size_t min, size_t max);
    Item::Rarity rarityConversion(size_t numberForConversion);
    
private:
    void generateAllCargo();
    void convertDataFromFile(std::string lineFromFile);
    void valueOneLineAssignment(const size_t & wordNumber, const std::string & singleWordFromFile);
    void generateSingleCargo();
    void generateFruit();
    void generateAlcohol();
    void generateItem();
    void generateDryFruits();
    CargoStorage cargo_;

    struct SplitLineFromFile {
        std::string className_{};
        std::string itemName_{};
        size_t minAmount_{};
        size_t maxAmount_{};
        size_t minPrice_{};
        size_t maxPrice_{};
        size_t minUniqueStat_{};
        size_t maxUniqueStat_{};
    } oneLine_;
    Time* time_;
};
