#include "account.h"
#include <QDebug>

//implementation of the Account class.

Account::Account(QString a, Customer c):m_AccountNo(a), m_AccHolder(c), m_Balance(0.00)
{
    m_Transactions.append(Transaction("Account Opened", QDate::currentDate()));
}

Account::~Account()
{
    qDebug()<<"Closing account.";
}

void Account::deposit(double d)
{
    /*update the account and perform transaction operations.*/
    m_Balance += d;
    if(d > 0)
        m_Transactions.append(Transaction("Deposit", QDate::currentDate()));
    else
        m_Transactions.append(Transaction("Withdrawal", QDate::currentDate()));
}

QString Account::toString() const
{
    /*collect, format and return all information pertaining the account.*/
    QString accDetails("Account Number: ");
    accDetails.append(m_AccountNo+"\nAccount Holder\n"+m_AccHolder.toString());
    accDetails.append(QString("\nBalance: %1").arg(m_Balance));
    accDetails.append("\n\nTRANSACTIONS\n");
    foreach(Transaction t, m_Transactions)
        accDetails.append(QString("\n%1\n").arg(t.toString()));

    return accDetails;
}

QList<Transaction> Account::getTransactions() const
{
    return m_Transactions;
}

double Account::getBalance() const
{
    return m_Balance;
}

QString Account::getAccountNo() const
{
    return m_AccountNo;
}
