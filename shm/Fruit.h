#pragma once

#include "Cargo.h"
#include "Time.h"

struct FruitData {
    std::string name_;
    size_t expiration_date_;
};

class Fruit : public Cargo {
public:
    Fruit(std::string name, size_t amount, size_t base_price, Time* time, size_t expiry_date);
    ~Fruit() override;

    std::string getName() const override;
    size_t getAmount() const override;
    size_t getPrice() const override;
    size_t getBasePrice() const override;
    void nextDay() override;
    std::string getDescription() const override;

    bool operator==(Cargo& cargo) const override;

    size_t getExpiryDate() const;
    size_t getTimeElapsed() const;

    Fruit& operator-=(size_t amount);

private:
    size_t time_elapsed_{0};
    size_t expiry_date_;
};
