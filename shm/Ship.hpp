#pragma once

#include <string>
#include <memory>

#include "Cargo.hpp"
#include "Observer.hpp"

class Ship : public Observer
{
public:
    Ship();
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id);
    Ship(int maxCrew, int speed, size_t id);
    ~Ship() override = default;

    void setName(const std::string& name);

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);

    [[nodiscard]] size_t getCapacity() const { return capacity_; }
    [[nodiscard]] size_t getMaxCrew() const { return maxCrew_; }
    [[nodiscard]] size_t getSpeed() const { return speed_; }
    [[nodiscard]] std::string getName() const { return name_; }
    [[nodiscard]] size_t getId() const { return id_; }

    [[nodiscard]] std::shared_ptr<Cargo> getCargo(size_t index) const;
    [[nodiscard]] std::vector<std::shared_ptr<Cargo>> getCargos() const { return storage_; }

    void load(const std::shared_ptr<Cargo>& cargo);
    void unload(Cargo* cargo);

    void NextDay() override;

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    std::vector<std::shared_ptr<Cargo>> storage_;
};
