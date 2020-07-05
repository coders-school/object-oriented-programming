#pragma once

#include <memory>
#include <string>
#include <vector>

#include "cargo.hpp"
#include "time.hpp"

using cargoPtr = std::shared_ptr<Cargo>;

class Ship : public Observer {
public:
    class Delegate {
    public:
        virtual ~Delegate() = default;
        virtual void payCrew(size_t money) = 0;
    };

    Ship();
    Ship(size_t id, std::string name, size_t speed, size_t maxCrew, size_t capacity);
    Ship(size_t id, std::string name, size_t speed, size_t maxCrew, size_t capacity, Delegate* delegate);
    Ship(size_t id, std::string name, size_t speed);

    int getId() const { return id_; }
    std::string getName() const { return name_; }
    size_t getSpeed() const { return speed_; }
    size_t getMaxCrew() const { return maxCrew_; }
    size_t getCapacity() const { return capacity_; }
    std::vector<cargoPtr> getCargo() const { return cargo_; }
    size_t getCrew() const { return crew_; }
    void load(cargoPtr cargo);

    cargoPtr FindMatchCargo(Cargo* cargo);
    Cargo* getCargo(size_t index) { return cargo_[index].get(); }

    void Unload(Cargo* cargo);
    void RemoveFromStorage(Cargo* cargo);
    void RemoveFromStorageIfRotten();

    void setName(const std::string& name);
    void nextDay() override;

    void printCargo() const;
    friend std::ostream& operator<<(std::ostream& os, const Cargo* cargo);

    Ship& operator+=(const size_t& crew);
    Ship& operator-=(const size_t& crew);

private:
    int id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;
    std::vector<cargoPtr> cargo_;
    size_t money_;
    Delegate* delegate_;
};
