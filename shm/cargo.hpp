#pragma once

#include <string>

class Cargo {
public:
    virtual size_t getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;

    Cargo(std::string name, size_t amount, size_t basePrice);
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(std::string name);

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};

class Fruit : public Cargo {
public:
    //Override from Cargo
    size_t getPrice() const override {
        return basePrice_ * (timeToSpoil_ / expiryDate_);
    }
    std::string getName() const override {
        return name_;
    }
    size_t getAmount() const override {
        return amount_;
    }
    size_t getBasePrice() const override {
        return basePrice_;
    }
    
    Fruit& operator--() {
        if (expiryDate_ == 0) {
            return *this;
        }
        --timeToSpoil_;
        return *this;
    }

private:
    size_t timeToSpoil_ {12};
    const size_t expiryDate_ {12};
};

constexpr size_t maxPower {96};

class Alcohol : public Cargo {
public:
    //Override from Cargo
    size_t getPrice() const override {
        return basePrice_ * (power_ / maxPower);
    }
    std::string getName() const override {
        return name_;
    }
    size_t getAmount() const override {
        return amount_;
    }
    size_t getBasePrice() const override {
        return basePrice_;
    }

private:
    size_t power_;
};

class Item : public Cargo {
public:
    enum class Rarity {
        common = 1,
        rare = 3,
        epic = 8,
        legendary = 50,
    };

    //Override from Cargo
    size_t getPrice() const override {
        return basePrice_ * static_cast<int>(rarity_);
    }
    std::string getName() const override {
        return name_;
    }
    size_t getAmount() const override {
        return amount_;
    }
    size_t getBasePrice() const override {
        return basePrice_;
    }

private:
    const size_t rarity_;
};