#pragma once

#include <cmath>
#include <string>

class Cargo {
public:
    Cargo() = default;
    Cargo(std::string name, size_t ammount, double basePrice);
    virtual ~Cargo() = default;

    virtual std::string getName() const = 0;
    virtual size_t getAmmount() const = 0;
    virtual double getBasePrice() const = 0;
    virtual double getPrice() const = 0;

    Cargo& operator+=(const size_t& ammount);
    Cargo& operator-=(const size_t& ammount);
    bool operator==(const Cargo& freight2);

protected:
    std::string name_;
    size_t ammount_;
    double basePrice_;
};

class Fruit : public Cargo {
public:
    Fruit(std::string name, size_t ammount, double basePrice);
    ~Fruit() override {}

    Fruit& operator--() {
        if (timeToRotten_ > 0) {
            timeToRotten_--;
        }
        return *this;
    }
    std::string getName() const override {return name_; }
    size_t getAmmount() const override { return ammount_; }
    double getBasePrice() const override { return basePrice_; }
    size_t getTimeToRotten() const { return timeToRotten_; }
    double getPrice() const override {
        return basePrice_ * (1 / std::exp(timeToRotten_));}

private:
    size_t timeToRotten_;
};

class Alcohol : public Cargo {
public:
    Alcohol(std::string name, size_t ammount, double basePrice);
    ~Alcohol() override {}
    std::string getName() const override {return name_; }
    size_t getAmmount() const override { return ammount_; }
    double getBasePrice() const override { return basePrice_; }
    double getPrice() const override {
        return volume_ == 0,96
                ? getBasePrice()
                : getBasePrice() * (0.96 - volume_);
    }

private:
    const double volume_ = 0.96;
};

class Item : public Cargo {
public:
    enum class Rarity { common = 1,
                        rare = 3,
                        epic = 6,
                        legendary = 10 };

    Item(std::string name, size_t ammount, double basePrice);
    ~Item() override {}
    std::string getName() const override {return name_; }
    size_t getAmmount() const override { return ammount_; }
    double getBasePrice() const override { return basePrice_; }
    double getPrice() const override { return getBasePrice() * static_cast<int>(rarity_); }
private:
    Rarity rarity_;
};

