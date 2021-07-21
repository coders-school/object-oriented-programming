#pragma once

#include <iostream>
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
    Store(size_t availableSpace, size_t money)
        : availableSpace_(availableSpace), money_(money){};

    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player);

    std::string getResponse(const Response& response);
    // std::shared_ptr<Cargo> getCargo(const  size_t ) const;

    void generateCargo();
    void randomizeCargo(std::vector<std::shared_ptr<Cargo>> storeCargos);

    void load(std::shared_ptr<Cargo> cargo, size_t amount);
    void unload(std::shared_ptr<Cargo> cargo, size_t amount);
    std::vector<std::shared_ptr<Cargo>>::iterator findCargo(const std::shared_ptr<Cargo>& cargo);

    size_t getSpace() const { return availableSpace_; };
    size_t getMoney() const { return money_; };

    void setSpace(size_t availableSpace) { availableSpace_ = availableSpace; };
    void setMoney(size_t money) { money_ = money; };

    friend std::ostream& operator<<(std::ostream& os, const Store& store);

private:
    std::vector<std::shared_ptr<Cargo>> stock_;
    size_t availableSpace_;
    size_t money_;
};
