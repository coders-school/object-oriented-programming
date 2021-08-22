#ifndef CARGO_HPP
#define CARGO_HPP
#include <string>
#include <memory>
#include "TimeObserver.hpp"

// Interface class used to represent cargo carried by each ship
class Cargo : public TimeObserver
{
protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;

public:
    Cargo(const std::string &name, size_t amount, size_t basePrice);
    virtual ~Cargo() = default;

    Cargo &operator+=(size_t amount);
    Cargo &operator-=(size_t amount);
    bool operator==(const Cargo &);
    virtual size_t getPrice() const = 0;
    virtual const std::string &getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;
    virtual std::unique_ptr<Cargo> clone(size_t amount) const =0;

    //friend size_t operator+(size_t sum, const Cargo& cargo);
};

/* size_t operator+(size_t sum, const std::shared_ptr<Cargo> & cargo){
    return sum + cargo->getAmount();
} */

#endif
