#ifndef STORE_HPP
#define STORE_HPP
#include "Response.hpp"
#include "Cargo.hpp"
#include "Player.hpp"
#include "Time.hpp"
#include "TimeObserver.hpp"
#include <vector>
#include <memory>

// Class used to represent store located on an island
class Store : public TimeObserver
{

private:
    std::vector<std::unique_ptr<Cargo>> goodsList_;
    Time* time_;

    Cargo* findProduct(Cargo* cargo);
    void removeProduct(Cargo* cargo);
    void GenerateGoodsList();

public:
    Store(Time* time);
    ~Store(){};
    Response buy(Cargo * cargo, size_t amount, Player *player);
    Response sell(Cargo* cargo, size_t amount, Player *player);
    Cargo* GetCargo(const size_t pos){return goodsList_[pos - 1].get();};
    void nextDay() override;

    friend std::ostream &operator<<(std::ostream &, const Store &);
};

#endif