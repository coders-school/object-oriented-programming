#pragma once

class Cargo {
public:
    Cargo& operator+=(const size_t);
    Cargo& operator-=(const size_t);

private:
    std::string m_name;
    size_t m_amount;
    size_t m_basePrice;
};
