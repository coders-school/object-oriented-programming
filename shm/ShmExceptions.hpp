#pragma once

#include <stdexcept>
#include <sstream>

class AmountException : public std::logic_error
{
public:
    AmountException(std::string p_msg);
    const char* what() const throw() override;
};
