#pragma once 

#include <memory>
#include <string>
#include <vector>

class Ship {
public:
    Ship();
    Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, size_t id);
    Ship(int maxCrew, int speed, size_t id);
    
    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);

    void setName(const std::string& name);
    size_t getCapacity() const;
    size_t getId() const;
    size_t getMaxCrew() const;
    std::string getName() const;
    int getSpeed() const;
    Cargo* getCargo(size_t index) const;

private:
    size_t capacity_;
    size_t crew_;
    const size_t id_;
    size_t maxCrew_;
    std::string name_;
    int speed_;
    std::vector<std::shared_ptr<Cargo>> cargo_{};
};
