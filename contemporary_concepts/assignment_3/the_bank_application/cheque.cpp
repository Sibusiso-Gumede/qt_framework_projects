#include "cheque.h"
#include <QDebug>

//the implementation of the Cheque class.

Cheque::Cheque(QString a, Customer c, double o):Account(a, c)
{
    m_Overdraft = o;
}

Cheque::~Cheque()
{
    qDebug()<<"Closing Cheque Account.";
}

bool Cheque::withdraw(double d)
{
    //if the combined total of the balance and overdraft limit
    //is more or equal to the withdrawal amount. Process request
    //else, ignore the request.
    if(d <= (m_Overdraft+getBalance()))
    {
        deposit(-d);
        return true;
    }
    else
        return false;
}

QString Cheque::toString() const
{
    return Account::toString();
}
