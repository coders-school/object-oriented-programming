#pragma once

#include <string>
#include <vector>

#include "Cargo.hpp"
#include "Player.hpp"
#include "Time.hpp"

class Ship : public Observer {
    uint16_t id_;
    std::string name_;
    uint16_t speed_;
    uint16_t crew_;
    uint16_t maxCrew_;
    uint16_t capacity_;
    Delegate* delegate_;
    Time* time_;
    std::vector<std::shared_ptr<Cargo>> cargos_;

    std::vector<std::shared_ptr<Cargo>>::iterator findMatchCargo(std::shared_ptr<Cargo>);
    void removeFromStorage(std::shared_ptr<Cargo>);

public:
    Ship();
    Ship(uint16_t, const std::string&, uint16_t, Delegate*, uint16_t, uint16_t, Time*);
    Ship(uint16_t, uint16_t, uint16_t, Delegate*, Time*);

    //Override from Observer
    ~Ship() override;

    uint16_t getId() const;
    std::string getName() const;
    uint16_t getSpeed() const;
    uint16_t getCrew() const;
    uint16_t getMaxCrew() const;
    uint16_t getCapacity() const;
    std::shared_ptr<Cargo> getCargo(uint16_t) const;
    std::vector<std::shared_ptr<Cargo>> getCargos() const;

    void setName(const std::string&);

    void load(std::shared_ptr<Cargo>);
    void unload(std::shared_ptr<Cargo>, uint16_t);

    Ship& operator+=(const uint16_t);
    Ship& operator-=(const uint16_t);

    // Override from Observer
    void nextDay() override;
};