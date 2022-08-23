#include "savings.h"
#include <QDebug>

//implementation of the Savings class.

double Savings::interest = 0.05;

Savings::Savings(QString a, Customer c): Account(a,c)
{}

Savings::~Savings()
{
    qDebug() <<"Closing Savings Account.";
}

bool Savings::withdraw(double d)
{
    if((getBalance()-d)>=0)
    {
        deposit(-d);//since m_Balance and m_Transactions cannot be
                    //accessed within this scope, the deposit() function is used
                    //to update the value and record the transaction.
        return true;
    }
    else
        return false;
}

QString Savings::toString() const
{
    return Account::toString();
}
