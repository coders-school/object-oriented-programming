#include "Storable.hpp"

void Storable::SpendMoney(int moneyToSpend)
{
    if (money_ - moneyToSpend <= 0)
    {
        money_ = 0;
    }
    money_ -= moneyToSpend;
}
void Storable::EarnMoney(int moneyToEarn)
{
    if(moneyToEarn > 0)
    {
        money_ += moneyToEarn;
    }
}
Storable::~Storable(){}
