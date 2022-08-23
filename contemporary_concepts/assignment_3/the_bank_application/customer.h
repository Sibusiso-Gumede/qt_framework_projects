#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

//the interface of the Customer class.

class Customer
{
public:
    Customer(QString n, QString i);
    QString toString() const;//const keyword after the paranthesis
                              //to ensure that the object data members
                            //don't get changed by the actions of the function.
private:
    QString m_Name, m_Id;
};

#endif // CUSTOMER_H
