#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Cargo.hpp"
#include "Delegate.hpp"
#include "Observer.hpp"
#include "StockManagement.hpp"
#include "Time.hpp"

constexpr size_t salaryPerWorker = 1;

class Ship : public Observer, public StockManagement {
private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    Delegate* delegate_{nullptr};
    std::shared_ptr<Time> time_{nullptr};
    CargoStock stock_;

public:
    Ship();
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, std::shared_ptr<Time>& time);
    Ship(int maxCrew, int speed, size_t id, std::shared_ptr<Time>& time);

    void setName(const std::string& name) { name_ = name; }
    void setDelegate(Delegate* const delegate) { delegate_ = delegate; }  //it might be good to integrate it with Ship constructor
                                                                          //but it then requires Player class to construct Ship for itself
    size_t getCapacity() const { return capacity_; }
    size_t getMaxCrew() const { return maxCrew_; }
    size_t getSpeed() const { return speed_; }
    std::string getName() const { return name_; }
    size_t getId() const { return id_; }
    CargoPtr getCargo(size_t index) const;
    CargoStock getAllCargos() const { return stock_; }

    Ship& operator-=(const size_t crew);
    Ship& operator+=(const size_t crew);
    
    void load(const CargoPtr& cargo);
    void unload(const CargoPtr& cargo, size_t amount);

    friend std::ostream& operator<<(std::ostream& out, const Ship& ship);

    //Override from Observer
    void nextDay() override;
};
