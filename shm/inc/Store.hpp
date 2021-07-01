#pragma once
#include "shm/inc/Cargo.hpp"
#include "shm/inc/Player.hpp"

class Store {
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