#ifndef SAVINGS_H
#define SAVINGS_H

#include "account.h"

class Savings: public Account
{
public:
    Savings(QString a, Customer c);
    virtual ~Savings();
    virtual bool withdraw(double d);
    virtual QString toString() const;
    static double interest;
};

#endif // SAVINGS_H
