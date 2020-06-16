#include <string>

class Cargo {
public:
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
}

