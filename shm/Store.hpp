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
    std::vector<std::shared_ptr<Cargo>> goodsList_;

    std::shared_ptr<Cargo> findProduct(std::shared_ptr<Cargo> cargo);
    void removeProduct(std::shared_ptr<Cargo> cargo);
    void GenerateGoodsList();

public:
    Store();
    ~Store(){};
    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, Player *player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, Player *player);
    //void printGoodsList() const;
    friend std::ostream &operator<<(std::ostream &, const Store &);
};

#endif