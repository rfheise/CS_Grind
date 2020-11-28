#ifndef _ILLEGALBALANCEEXCEPTION_H_
#define _ILLEGALBALANCEEXCEPTION_H_


#include <exception>

class IllegalBalanceException :public std::exception {

public:
    virtual const char *what()const noexcept override;

};

#endif