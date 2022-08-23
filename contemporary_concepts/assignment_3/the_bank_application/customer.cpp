#include "customer.h"

//the implementation of the Customer class.

Customer::Customer(QString n, QString i):m_Name(n), m_Id(i)
{}

QString Customer::toString() const
{
    return QString("Customer Name: %1\nCustomer ID: %2")
            .arg(m_Name).arg(m_Id);
}
