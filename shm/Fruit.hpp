#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(std::string name, size_t amount, size_t basePrice, size_t freshTime, size_t maxFreshTime = 0)
        : Cargo(name, amount, basePrice), freshTime_{freshTime}, maxFreshTime_{maxFreshTime} {
        if (!maxFreshTime) {
            maxFreshTime_ = freshTime_;
        }
    }
    
    ~Fruit() override = default;

    size_t getPrice() const override {
        if (!maxFreshTime_) {
            return 0u;
        }
        return static_cast<size_t>(basePrice_ * freshTime_ / static_cast<double>(maxFreshTime_));
    }

    bool operator==(const Cargo& other) const override {
        if (auto otherItem = dynamic_cast<const Fruit*>(&other)) {
            return name_ == otherItem->getName()
            and maxFreshTime_ == otherItem->maxFreshTime_
            and freshTime_ == otherItem->freshTime_;
        }
        return false;
    }

    Fruit& operator--(){//prefix operator
        if(freshTime_){
            --freshTime_;
        }
        return *this;
    }

    std::unique_ptr<Cargo> split(size_t amountPart) override {
        if (!amountPart or amountPart > amount_) {
            return {};
        }
        *this -= amountPart;
        return std::make_unique<Fruit>(name_, amountPart, basePrice_, freshTime_, maxFreshTime_);
    }

protected:
    size_t maxFreshTime_ = 0;
    size_t freshTime_ = 0;
};
