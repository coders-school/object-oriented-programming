#pragma once

#include <cmath>
#include <string>

enum class Rarity { common = 1,
                    rare = 3,
                    epic = 6,
                    legendary = 10 };

class Cargo {
public:
    Cargo() = default;
    Cargo(std::string name, size_t amount, double basePrice);
    virtual ~Cargo() = default;

    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual double getBasePrice() const = 0;
    virtual double getPrice() const = 0;
    virtual size_t getExpiryDate() const = 0;
    virtual double getPercentage() const = 0;
    virtual Rarity getRarity() const = 0;
    virtual Cargo& operator--() = 0;
    virtual Cargo& operator+=(const size_t& amount) = 0;
    virtual Cargo& operator-=(const size_t& amount) = 0;
    bool operator==(const Cargo& freight2);

protected:
    std::string name_;
    size_t amount_;
    double basePrice_;
};

class Fruit : public Cargo {
public:
    Fruit(std::string name, size_t amount, double basePrice);
    ~Fruit() override {}

    Cargo& operator--() {
        if (timeToRotten_ > 0) {
            timeToRotten_--;
        }
        return *this;
    }
    Cargo& operator+=(size_t amount) {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(const size_t& amount) {
        if (amount_ - amount >= 0) {
            amount_ -= amount;
        }
        return *this;
    }

    std::string getName() const override {return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    size_t getTimeToRotten() const { return timeToRotten_; }
    double getPrice() const override {
        return basePrice_ * (1 / std::exp(timeToRotten_));}
    size_t getExpiryDate() const { return timeToRotten_; }

protected:
    size_t time_elapsed_{0};
    size_t timeToRotten_;
};

class DryFruit : public Fruit {
    std::string getName() const override { return "Dry Fruit"; }
    double getPrice() const override {
        return 3 * basePrice_ * (1 / std::exp(timeToRotten_));}
    Cargo& operator--() override {
        if (++counter_ == 10) {
            ++time_elapsed_;
            counter_ = 0;
        }
        return *this;
    }
private:
    size_t counter_{0};
};

class Alcohol : public Cargo {
public:
    Alcohol(std::string name, size_t amount, double basePrice);
    ~Alcohol() override {}

    Cargo& operator+=(size_t amount) {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(const size_t& amount) {
        if (amount_ - amount >= 0) {
            amount_ -= amount;
        }
        return *this;
    }
    std::string getName() const override {return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    double getPrice() const override {
        return volume_ == 0,96
                ? getBasePrice()
                : getBasePrice() * (0.96 - volume_);
    }
    double getPercentage() const { return volume_; }

private:
    const double volume_ = 0.96;
};

class Item : public Cargo {
public:
    Item(std::string name, size_t amount, double basePrice);
    ~Item() override {}
    Cargo& operator+=(size_t amount) {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(const size_t& amount) {
        if (amount_ - amount >= 0) {
            amount_ -= amount;
        }
        return *this;
    }
    std::string getName() const override {return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    double getPrice() const override { return getBasePrice() * static_cast<int>(rarity_); }
    Rarity getRarity() const { return rarity_; }
private:
    Rarity rarity_;
};

