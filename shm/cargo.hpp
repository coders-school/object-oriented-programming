#include <iostream>
#include <string>

class Cargo {
private:
    const std::string name_;
    size_t amount_;
    double basePrice_;

public:
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
};
