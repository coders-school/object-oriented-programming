#pragma once
#include "cargo.hpp"

constexpr size_t MaxPercentage{96};
class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t percentage);
    Alcohol() = default;
    ~Alcohol() override {};

    size_t getPercentage() const { return percentage_; };
    void setPercentage(size_t percentage) { percentage_ = percentage; };

    //Methods override from Cargo class.
    size_t getPrice() const override;

    void nextDay() override {};

    std::shared_ptr<Cargo> clone(const size_t &) const;

    void setTime(const std::shared_ptr<Time>&) override {};
    void detachingObserver() override {};
private:
    size_t percentage_;
};
