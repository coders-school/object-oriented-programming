#ifndef STORE_HPP
#define STORE_HPP
#include "Response.hpp"
#include "Cargo.hpp"
#include "Player.hpp"
#include <vector>
#include <memory>

// Class used to represent store located on an island
class Store
{

private:
    std::vector<std::unique_ptr<Cargo>> goodsList_;

    Cargo* findProduct(Cargo* cargo);
    void removeProduct(Cargo* cargo);
    void GenerateGoodsList();

public:
    Store();
    ~Store(){};
    Response buy(Cargo * cargo, size_t amount, Player *player);
    Response sell(Cargo* cargo, size_t amount, Player *player);
    Cargo* GetCargo(const size_t pos){return goodsList_[pos - 1].get();};
    //void printGoodsList() const;
    friend std::ostream &operator<<(std::ostream &, const Store &);
};

#endif