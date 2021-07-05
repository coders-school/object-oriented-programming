#pragma once

#include <cstddef>

#include "shm/inc/Subscriber.hpp"

class Cargo;
class Player;

constexpr size_t STORE_CAPACITY = 1000;

class Store : public Subscriber {
public:

    enum class Response {
        done, 
        lack_of_money, 
        lack_of_cargo, 
        lack_of_space
    };

    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);

    // override from Subscriber
    void nextDay() override;

private:

};
