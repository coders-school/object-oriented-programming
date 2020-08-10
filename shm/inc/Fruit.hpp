#include <stddef.h>
#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(size_t amount, const std::string& name, uint16_t base_price, uint16_t expiry_date, uint16_t time_elapsed);
    ~Fruit() override;

    // override from Cargo

    uint16_t getPrice() const override;
    std::string getName() const override;
    uint16_t getAmount() const override;
    // uint16_t getBasePrice() const override;
    Cargo& operator--();
    Cargo& operator+=(uint16_t amount) override;
    Cargo& operator-=(uint16_t amount) override;
    bool operator==(const Cargo&) const override;
    uint16_t getTimeElapsed() const;
    uint16_t getExpiryDate() const;

private:
    uint16_t time_elapsed_{0};
    uint16_t time_to_spoil;
};