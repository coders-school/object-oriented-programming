#pragma once

#include "cargo.hpp"
#include "common.hpp"
#include "player.hpp"

constexpr size_t DEFAULT_CAPACITY = 1000;
constexpr size_t DEFAULT_FUNDS = 1000;
constexpr size_t AMOUNT_MIN = 0;
constexpr size_t AMOUNT_MAX = 50;

class Store : public Observer
{
public:
    enum class Response { invalid_cargo, done, lack_of_money, lack_of_cargo, lack_of_space };

    enum updateMode { BUY = 0, SELL = 1 };

    Store(Time* time,
          size_t capacity = DEFAULT_CAPACITY,
          size_t availableFunds = DEFAULT_FUNDS);
    ~Store() override;

    Response buy(Cargo* cargo, size_t amount, Player* player, Store* store);
    Response sell(Cargo* cargo, size_t amount, Player* player);
    bool addCargo(Cargo* cargo);
    size_t getAvaiableSpace() const;
    size_t getAvailableFunds() const;
    void setCapacity(const size_t amount);
    void setAvailableFunds(const size_t amount);

    Cargo* getCargo(const std::string& name);
    void printCargo();
    void printResponseMessage(Response& response);
    friend std::ostream& operator<<(std::ostream& out, const Store& store);
    void nextDay() override;

private:
    size_t capacity_;
    size_t availableFunds_;
    std::vector<std::unique_ptr<Cargo>> cargo_;
    Time* time_;

    void updateCargo(Cargo* cargo, size_t amount, updateMode mode);
    void generateCargo();
};
