#pragma once

#include <memory>
#include <string>
#include <vector>

#include "shm/inc/Subscriber.hpp"
#include "shm/inc/Alcohol.hpp"
#include "shm/inc/DryFruit.hpp"
#include "shm/inc/Fruit.hpp"
#include "shm/inc/Item.hpp"

class Cargo;
class Delegate;
class Player;

// class responsible for manage ship(s) in game
class Ship : public Subscriber {
public:
    Ship() = default;
    Ship(int id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity, Delegate* delegate = nullptr);
    Ship(int id, size_t speed, size_t maxCrew, Delegate* delegate);

    Ship& operator+=(const size_t amount);
    Ship& operator-=(const size_t amount);
    friend std::ostream& operator<<(std::ostream& out, const Ship& ship);

    int getId() const { return id_; };
    std::string getName() const { return name_; };
    size_t getSpeed() const { return speed_; };
    size_t getMaxCrew() const { return maxCrew_; };
    size_t getCapacity() const { return capacity_; };
    std::shared_ptr<Cargo> getCargo(size_t index) const;
    Cargo* getCargo(const std::string& name) const;
    std::vector<std::shared_ptr<Cargo>> getCargos() const { return cargos_; };

    void setName(const std::string& name);
    void load(const std::shared_ptr<Cargo>);
    void unload(const std::shared_ptr<Cargo>);
    void changeDelegate(Player* player);

    // overload form Subscriber
    void nextDay() override;

private:
    const int id_ { -1 };
    std::string name_;
    size_t speed_ { 50 };
    const size_t maxCrew_ { 100 };
    const size_t capacity_ { 80 };
    Delegate* delegate_;
    std::vector<std::shared_ptr<Cargo>> cargos_;
    size_t crew_ { 50 };
};
