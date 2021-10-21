
#pragma once
#include <string>
#include "time.hpp"
#include "iObserver.hpp"

class Cargo : public IObserver {
public:
    Cargo() = default;
    Cargo(const std::string& name, size_t amount) : name_(name), amount_(amount) {};
    Cargo(const std::string& name, size_t amount, size_t basePrice, std::shared_ptr<Time> time);
    Cargo(const std::string& name, size_t amount, size_t basePrice);
    virtual ~Cargo() = default;

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo&) const;

    std::string getName() const;
    size_t getAmount() const;
    size_t getBasePrice() const;

    virtual size_t getPrice() const = 0;

    virtual std::shared_ptr<Cargo> clone(const size_t &) const = 0;

    virtual void setTime(const std::shared_ptr<Time>&) = 0;

    virtual void detachingObserver() = 0;
    
protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
    std::shared_ptr<Time> time_ {nullptr};
};
