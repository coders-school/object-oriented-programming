#pragma once
#include <iostream>

#include "Cargo.hpp"
#include "Player.hpp"

class Store {
public:
    enum class Response {
        done,
        lack_of_money,
        lack_of_cargo,
        lack_of_space
    };

    Response Buy(Cargo* cargo, size_t amount, Player* player);
    Response Sell(Cargo* cargo, size_t amount, Player* player);

    friend std::ostream& operator<<(std::ostream& out, const Store& store);
    // Temporary added - operator << test
    //begin
    void CreateTestCargo();
    //end

private:
    std::vector<std::shared_ptr<Cargo>> _cargo;
};
