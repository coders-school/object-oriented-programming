#pragma once

#include <memory>
#include <string>
#include <vector>

#include "cargo.hpp"

class Ship : public Observer {
public:
    class Delegate {
    public:
        virtual void payCrew(size_t crew_count) = 0;
        virtual ~Delegate(){};
    };
    Ship();
    Ship(int capacity,
         int maxCrew,
         int speed,
         const std::string& name,
         size_t id,
         Delegate* delegate);
    Ship(int maxCrew, int speed, size_t id, Delegate* delegate);
    // override from Observer
    ~Ship() override;

    void setName(const std::string& name);

    Ship& operator-=(size_t crew);
    Ship& operator+=(size_t crew);

    size_t getCapacity() const { return capacity_; }
    size_t getMaxCrew() const { return maxCrew_; }
    size_t getSpeed() const { return speed_; }
    std::string getName() const { return name_; }
    size_t getId() const { return id_; }
    std::vector<std::shared_ptr<Cargo>>& getCargo() { return cargo_; };

    void load(std::shared_ptr<Cargo> cargo);
    void unload(Cargo* cargo, size_t amount);
    // override from Observer
    void nextDay() override;

private:
    Delegate* delegate_;
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    std::vector<std::shared_ptr<Cargo>> cargo_;
};
