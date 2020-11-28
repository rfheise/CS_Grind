#include "InsufficientFundsException.h"


const char *InsufficientFundsException::what() const noexcept{
    return "Fool you ain't got no money";
}