#include "alcohol.hpp"

size_t Alcohol::getPrice() const
{
    return basePrice_ * percentage_ / 96;
}
