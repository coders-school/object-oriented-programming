#pragma once

#include "shm/inc/Cargo.hpp"

class Fruit : private Cargo {
public:
    Fruit(const std::string& name, size_t amount, size_t basePrice);

    //override from Cargo class
    Fruit& operator--();

<<<<<<< HEAD
    std::size_t getPrice() const override;
    std::string getName() const override { return name_; }
    std::size_t getAmount() const override { return amount_; }
    std::size_t getBasePrice() const override{ return basePrice_; }
=======
    std::size_t getPrice() override;
    std::string getName() const override { return name_; }
    std::size_t getAmount() const override { return amount_; }
    std::size_t getBestPrice() const override{ return basePrice_; }
>>>>>>> bcd53401117f360399d41c426bf9514ac93f8084

private:
    size_t rottenTime { 10 };
};
