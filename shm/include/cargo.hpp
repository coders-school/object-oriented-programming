#pragma once

#include <string>

class Cargo {
public:
    Cargo() = default;
    Cargo(std::string name, size_t ammount, double basePrice);
    virtual ~Cargo() = default;

    virtual std::string getName() const = 0;
    virtual size_t getAmmount() const = 0;
    virtual size_t getBasePrice() const = 0;

    Cargo& operator+=(const size_t& ammount);
    Cargo& operator-=(const size_t& ammount);
    bool operator==(const Cargo& freight2);

protected:
    std::string name_;
    size_t ammount_;
    size_t basePrice_;
};

class Fruit : public Cargo {
public:
    Fruit(std::string name, size_t ammount, double basePrice);
    ~Fruit() override {}
    std::string getName() const override {return name_; }
    size_t getAmmount() const override { return ammount_; }
    size_t getBasePrice() const override { return basePrice_; }
};

class Alcohol : public Cargo {
public:
    Alcohol(std::string name, size_t ammount, double basePrice);
    ~Alcohol() override {}
    std::string getName() const override {return name_; }
    size_t getAmmount() const override { return ammount_; }
    size_t getBasePrice() const override { return basePrice_; }
};

