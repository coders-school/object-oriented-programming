#pragma once

#include <memory>
#include <optional>
#include <string>

#include <assert.h>

class Cargo {
public:
    Cargo(const std::string& name, size_t amount, size_t basePrice);

    virtual ~Cargo() = default;

    //operator-= throws std::invalid_argument. if you will use operator remember about try-catch.
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    virtual bool operator==(const Cargo& other) const = 0;

    virtual size_t getPrice() const = 0;
    const std::string_view getName() const;
    virtual size_t getAmount() const;
    virtual size_t getBasePrice() const;

    std::optional<size_t> haveSuffix(const std::string_view suffix) const;
    void removeSuffix(const std::string_view suffix);
    void addSuffix(const std::string_view suffix);

    std::unique_ptr<Cargo> split(size_t amountPart);

protected:
    std::string name_{};
    size_t amount_{};
    size_t basePrice_{};

private:
    virtual std::unique_ptr<Cargo> createAmountOfEqual(size_t amount) = 0;
};
