#pragma once

#include <cstddef>

#include "shm/inc/Subscriber.hpp"

class Cargo;
class Player;

class Store : public Subscriber {
public:

    enum class Response {
        done, 
        lack_of_money, 
        lack_of_cargo, 
        lack_of_space
    };

    Response buy(Cargo* cargo, size_t amount, Player* player);

private:

};
