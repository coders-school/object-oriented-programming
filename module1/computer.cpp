#include <iostream>

class Computer {
    unsigned ramAmount_ = 4;

public:
    Computer& operator+=(int amount) {
        ramAmount_ += amount;
        std::cout << "Ram memory extended by " << amount << '\n';
        return *this;
    }
    unsigned getRam() const { return ramAmount_; }
};

int main() {
    Computer hp{};  // default configuration
    hp += 8;
    hp += 4;
    std::cout << hp.getRam() << '\n';
}
