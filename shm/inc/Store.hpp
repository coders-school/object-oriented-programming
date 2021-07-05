#pragma once

#include <vector>

#include "shm/inc/Subscriber.hpp"

class Cargo;
class Player;

constexpr size_t MIN_CARGO{ 0 };
constexpr size_t MAX_CARGO{ 100 };

class Store : public Subscriber {
public:

    enum class Response {
        done, 
        lack_of_money, 
        lack_of_cargo, 
        lack_of_space
    };

    Response buy(Cargo* cargo, size_t amount, Player* player);

    // override from Subscriber
    void nextDay() override;

private:
    std::vector<std::unique_ptr<Cargo>> cargo_;
};
