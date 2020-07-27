#pragma once

#include <memory>

#include "Cargo.hpp"
#include "Observer.hpp"
#include "Player.hpp"
#include "Time.hpp"

class Store : public Observer
{
private:
    std::vector<std::unique_ptr<Cargo>> cargo_;
    //    Time* time_; # TODO after implementation Time class

    enum class Response {
        lack_of_money,
        lack_of_cargo,
        lack_of_space,
        done
    };

public:
    explicit Store(Time* time);
    ~Store() override;

    void NextDay() override;

    Cargo* GetCargo(const size_t pos);
    static Response Buy(Cargo* cargo, size_t amount, Player* player);
    static Response Sell(Cargo* cargo, size_t amount, Player* player);

    friend std::ostream& operator<<(std::ostream& out, const Store& store);

private:
    Time* time_;
    void GenerateCargo();
    Cargo* FindMatchCargo(Cargo* cargo);
    void RemoveFromStore(Cargo* cargo);
};
