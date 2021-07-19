#pragma once

#include <memory>
#include <vector>

#include "cargo.hpp"
#include "player.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store {
public:
    Store() = default;

    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player);

    std::string getResponse(const Response& response);
    std::shared_ptr<Cargo> getCargo(const  size_t ) const;

private:
    std::vector<std::shared_ptr<Cargo>> stock_;
    void generateCargo();
    void randomizeCargo();
    void load( std::shared_ptr<Cargo> cargo, size_t amount);
    void unload( std::shared_ptr<Cargo> cargo, size_t amount);
};
