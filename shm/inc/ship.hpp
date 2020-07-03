#pragma once

#include <string>
#include <memory>
#include <vector>

#include "cargo.hpp"
#include "observer.hpp"
#include "time.hpp"

class Ship : public Observer {
public:
    Ship(int maxCrew, int speed, size_t id, Time* time);
    Ship(int capacity, int maxCrew, int speed,
         const std::string& name, size_t id, Time* time);
    ~Ship() override;

    Ship& operator-=(const size_t crew);
    Ship& operator+=(const size_t crew);

    void setName(const std::string& name);
    
    size_t getCapacity() const;
    size_t getMaxCrew() const;
    size_t getSpeed() const;
    std::string getName() const;
    size_t getId() const;
    
    std::shared_ptr<Cargo> getCargo(const size_t index);
    size_t getAvailableSpace() const;

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    std::vector<std::shared_ptr<Cargo>> cargo_;
    Time *time_;

    void nextDay() override;
};
