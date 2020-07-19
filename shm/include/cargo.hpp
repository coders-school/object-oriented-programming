#pragma once

#include <memory>
#include <string>
#include "observer.hpp"

class Cargo : public Observer {
public:
    Cargo(const std::string& name, size_t amount, size_t basePrice);
    virtual ~Cargo() {}
    virtual Cargo& operator+=(size_t amount) = 0;
    virtual Cargo& operator-=(size_t amount) = 0;
    virtual bool operator==(const Cargo& other) const = 0;

    virtual size_t getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;
    virtual std::shared_ptr<Cargo> getShared() const = 0;

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
