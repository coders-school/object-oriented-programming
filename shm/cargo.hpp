#pragma once

#include <memory>
#include <string>
//#include "alcohol.hpp"
//#include "fruit.hpp"
//#include "item.hpp"
#include "subjectTime.hpp"
#include "time.hpp"

class Cargo : public ObserverTime {
public:
    Cargo(uint32_t amount, std::string name, uint32_t basePrice);
    virtual ~Cargo();
    virtual std::shared_ptr<Cargo> clone() const = 0;

    virtual uint32_t getAmount() const = 0;
    virtual uint32_t getBasePrice() const = 0;
    virtual std::string getName() const = 0;
    virtual double getPrice() const = 0;

    virtual Cargo& operator+=(uint32_t amount) = 0;
    virtual Cargo& operator-=(uint32_t amount) = 0;
    virtual bool operator==(const Cargo& cargo) const = 0;

    // override from ObserverTime
    virtual void nextDay() = 0;

protected:
    uint32_t amount_;
    std::string name_;
    uint32_t basePrice_;
    // Time* time_;
};
