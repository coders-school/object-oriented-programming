#include "ShmExceptions.hpp"

AmountException::AmountException(std::string p_msg) : logic_error(p_msg)
{
}

const char* AmountException::what() const throw()
{
    std::ostringstream o;
    o << logic_error::what();
    return o.str().c_str();
}
