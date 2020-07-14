#pragma once

#include <memory>
#include <vector>

#include "cargo.hpp"
#include "cargoHolder.hpp"
#include "time.hpp"

class Ship : public CargoHolder,
             public Time::Observer {
public:
    class Delegate {
    public:
        virtual void payCrew(size_t money) = 0;
        virtual ~Delegate() {}
    };

    Ship();

    Ship(int capacity, int maxCrew, int speed, const std::string& name, unsigned int id, Delegate* delegate = nullptr, Time* time = nullptr);

    Ship(int maxCrew, int speed, unsigned int id, Delegate* delegate = nullptr, Time* time = nullptr);

    void setName(const std::string& name) { name_ = name; }

    size_t getCapacity() const { return capacity_; }
    size_t getMaxCrew() const { return maxCrew_; }
    size_t getSpeed() const { return speed_; }
    std::string getName() const { return name_; }
    int getId() const { return id_; }
    void setDelegate(Delegate* delegate) { payCrew = delegate; }

    std::shared_ptr<Cargo> getCargo(size_t index);
    size_t getAvailableSpace() const;
    void clearEmptyCargo();

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);

    void load(const std::shared_ptr<Cargo>& cargo);
    void unload(const Cargo* const& cargo);

    /* override from CargoHolder */
    const std::vector<std::shared_ptr<Cargo>>& getAllCargo() const override { return cargo_; };
    void receiveCargo(Cargo* cargo, size_t amount, CargoHolder* cargoHolder) override;
    void clearEmptyCargos() override;
    //override from Time::Observer
    void nextDay() override;

    ~Ship() override;

private:
    std::vector<std::shared_ptr<Cargo>> cargo_ = {};
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const int id_;
    Delegate* payCrew;
    Time* time_;
};
