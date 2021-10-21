#pragma once

#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

#include "cargo.hpp"
#include "player.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};
// Class responsible for managing a store
class Store : public IObserver {
public:
    Store() = default;
    Store(std::shared_ptr<Time> time);
    ~Store();

    Response buy(const std::shared_ptr<Cargo>& cargo, const size_t& amount, Player* player);
    Response sell(const std::shared_ptr<Cargo>& cargo, const size_t& amount, Player* player);
    std::vector<std::shared_ptr<Cargo>> getCargoOfStore() const { return stock_; };

    // Function responsible for adding a new cargo to a Store
    void addCargo(const std::shared_ptr<Cargo>& cargo, size_t amount);
    // Fucntion responsible for subtracting cargo from a Store.
    void loadShip(const std::shared_ptr<Cargo>&  cargo, const size_t& amount);
    // Funcition responsibel for adding amount of cargo to a Store.
    void unloadShip(const std::shared_ptr<Cargo>&  cargo, const size_t& amount);
    // Function responsible for finding proper cargo.
    std::vector<std::shared_ptr<Cargo>>::iterator findMatchCargo(const std::shared_ptr<Cargo>& wantedCargo);

    friend std::ostream& operator<<(std::ostream& os, const Store& store);

    void nextDay() override; 

private:
    std::vector<std::shared_ptr<Cargo>> stock_{};
    void generateDefaultCargo();
    std::shared_ptr<Time> time_{ nullptr };

};
