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

class Store : public Warehouse,
              public Timeable {
public:
    Store() = default;
    virtual ~Store() = default;

    void nextDay() override;

    Response buy(const Cargo* const cargo, size_t amount, Player* player);
    Response sell(const Cargo* const cargo, size_t amount, Player* player);

    Cargo* findCargo(const Cargo* const exampleCargo) const;
    void setChangeAssortmentCallback(std::function<void()> callback);
    size_t getAssortmentSize();
    
    friend std::ostream& operator<<(std::ostream&, const Store&);

private:
    std::function<void()> changeAssortment_;
};

std::ostream& operator<<(std::ostream& out, const Store& store);
