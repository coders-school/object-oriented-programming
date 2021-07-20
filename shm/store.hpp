#pragma once

#include <memory>
#include <vector>
#include <iostream>

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
    Store(size_t availableSpace, size_t money): availableSpace_(availableSpace), money_(money){};

    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player);

    std::string getResponse(const Response& response);
    // std::shared_ptr<Cargo> getCargo(const  size_t ) const;

    // void generateCargo();
    // void randomizeCargo();
    
    void load( std::shared_ptr<Cargo> cargo, size_t amount);
    void unload( std::shared_ptr<Cargo> cargo, size_t amount);
    std::vector<std::shared_ptr<Cargo>>::iterator findCargo(const std::shared_ptr<Cargo>& cargo);
private:
    std::vector<std::shared_ptr<Cargo>> stock_;
    size_t availableSpace_;
    size_t money_;
};
