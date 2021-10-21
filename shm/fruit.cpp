#include "fruit.hpp"
#include <iostream>
#include <limits>

Fruit::Fruit(const std::string &name, size_t amount, size_t basePrice, size_t expirationDate, std::shared_ptr<Time> time) : Cargo(name, amount, basePrice, time), expirationDate_(expirationDate){
};

Fruit::~Fruit() { time_->detachObserver(this); };

size_t Fruit::getPrice() const
{
    return static_cast<size_t>(basePrice_ * static_cast<float>(purchaseDate_) / expirationDate_);
}

Fruit &Fruit::operator--()
{
    if (purchaseDate_ <= 0)
    {
        purchaseDate_ = 0;
    }
    purchaseDate_--;
    return *this;
}

void Fruit::nextDay()
{
    if (purchaseDate_)
    {
        operator--();
    }
}

std::shared_ptr<Cargo> Fruit::clone(const size_t &amount) const {
    return std::make_shared<Fruit>(this->getName(),
                                    amount,
                                    this->getBasePrice(),
                                    this->getExpirationDate(),
                                    time_);
}

void Fruit::setTime(const std::shared_ptr<Time>& time) {
    time_ = time;
}

void Fruit::detachingObserver() {
    time_->detachObserver(this);
}
