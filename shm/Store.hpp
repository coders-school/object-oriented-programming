#ifndef STORE_HPP
#define STORE_HPP
#include "Response.hpp"
#include "Cargo.hpp"
#include "Player.hpp"
#include <vector>
#include <memory>

// Class used to represent store located on an island
class Store {

private: 
    std::vector<std::shared_ptr<Cargo>> goodsList_;

    std::shared_ptr<Cargo> findProduct(Cargo* cargo);
    void removeProduct(Cargo* cargo);
    void GenerateGoodsList();

public:
    Store();
    ~Store() {};
    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);
    void printGoodsList() const;
    //friend std::ostream& operator<<(std::ostream&, const Store&);


};

#endif