#pragma once

#include <memory>
#include <vector>

#include "shm/inc/Subscriber.hpp"

class Cargo;
class Player;

constexpr size_t MIN_CARGO_IN_STORE{ 0 };
constexpr size_t MAX_CARGO_IN_STORE{ 100 };
constexpr size_t STORE_CAPACITY { 1000 };

class Store : public Subscriber {
public:

    enum class Response {
        done, 
        lack_of_money, 
        lack_of_cargo, 
        lack_of_space
    };

    friend std::ostream& operator<<(std::ostream& out, const Store& store);

    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);

    // override from Subscriber
    void nextDay() override;
    
private:
    std::vector<std::unique_ptr<Cargo>> cargo_;
};
