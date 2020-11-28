#ifndef _BUSINESS_H_
#define _BUSINESS_H_

#include "Checking.h"
#include <string>

class Business : public Checking{
private:
    static const constexpr double strinterest = 0;
    static const constexpr char * strname = "Juice";
    static const constexpr double strbalance = 0;
public:
    virtual void deposit(double ammount) override;
    virtual std::string print() override;
    Business(const double balance = strbalance, const char *name = strname, const double interest = strinterest);
protected:
    double interest;
};

#endif