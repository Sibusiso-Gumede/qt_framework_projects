#include "transaction.h"

//implementation of the Transaction class.

Transaction::Transaction(QString c, QDate d):m_Description(c), m_Date(d)
{}

QString Transaction::toString() const
{
    return QString("Transaction Type: %1\nTransaction Date: %2").arg(m_Description).arg(m_Date.toString());
}

QDate Transaction::getDate() const
{
    return QDate(m_Date);
}
