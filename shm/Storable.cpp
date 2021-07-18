#include "Storable.hpp"

void Storable::SpendMoney(int moneyToSpend) {
    if (money_ - moneyToSpend <= 0) {
        money_ = 0;
    }
    money_ -= moneyToSpend;
}