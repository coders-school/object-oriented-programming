#pragma once 
#include "player.hpp"
#include "cargo.hpp"


enum class Response 
    {
        done
        , lack_of_money
        , lack_of_cargo
        , lack_of_space
    };


class Store 
{

public:
    Store();
    Store();

    // void load(std::shared_ptr<Cargo>);
    // void unload (std::shared_ptr<Cargo>);
    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);

    std::shared_ptr<Cargo> getStoreCargo(const size_t) const;
private:
    size_t capacity_;
    std::vector<std::shared_ptr<Cargo>> storeCargos_;

    
};
