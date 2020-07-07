#pragma once

#include <memory>

#include "Cargo.hpp"
#include "Player.hpp"
#include "Observer.hpp"

class Store : public Observer
{
private:
    std::vector<std::unique_ptr<Cargo>> cargo_;
    //    Time* time_; # TODO after implementation Time class

    enum class Response {
        lack_of_money,
        lack_of_cargo,
        lack_of_space
    };

public:
    //    Store(Time* time);  # TODO after implementation Time class
    Store();
    ~Store() override;
    void NextDay() override;
    Cargo* GetCargo(const size_t pos);
    Response Buy(Cargo* cargo, size_t amount, Player* player);
    Response Sell(Cargo* cargo, size_t amount, Player* player);
    friend std::ostream& operator<<(std::ostream& out, const Store& store);

private:
    void GenerateCargo();
    Cargo* FindMatchCargo(Cargo* cargo);
    void RemoveFromStore(Cargo* cargo);
};
