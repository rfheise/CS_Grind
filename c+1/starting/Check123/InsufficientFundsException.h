#ifndef _INSUFFICIENTFUNDS_H_
#define _INSUFFICIENTFUNDS_H_

#include <exception>


class InsufficientFundsException : public std::exception {
public:
    virtual const char * what() const noexcept override;
};

#endif