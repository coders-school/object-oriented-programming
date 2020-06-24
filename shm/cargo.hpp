#pragma once

#include <string>
#include "subjectTime.hpp"
#include "time.hpp"

class Cargo : public ObserverTime {
public:
    Cargo(uint32_t amount, std::string name, uint32_t basePrice, Time* time);
    ~Cargo();

    uint32_t getAmount() const;
    uint32_t getBasePrice() const;
    std::string getName() const;

    Cargo& operator+=(uint32_t amount);
    Cargo& operator-=(uint32_t amount);
    bool operator==(Cargo& cargo);

// override from ObserverTime
    void nextDay() override;

private:
    std::string name_;
    uint32_t amount_;
    uint32_t basePrice_;
    Time* time_;
};
