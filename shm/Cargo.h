#pragma once

#include <string>

#include "Observer.h"
#include "Time.h"

class Cargo : public Observer {
public:
    Cargo() = default;
    ~Cargo() override;

    Cargo(std::string name, size_t amount, size_t basePrice, Time* time);

    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getPrice() const = 0;
    virtual size_t getBasePrice() const = 0;
    virtual void nextDay() = 0;
    virtual std::string getDescription() const = 0;
    void update() override;

    virtual bool operator==(Cargo& cargo) const = 0;

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
    Time* time_;
};
