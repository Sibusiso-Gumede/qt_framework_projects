#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "customer.h"
#include "transaction.h"
#include <QString>

class Account
{
public:
    explicit Account(QString a, Customer c);
    virtual ~Account();
    void deposit(double d);
    virtual bool withdraw(double d) = 0;//"virtual" keyword for runtime
                                    //binding purposes on function calls
                                    //via pointers and references.
    virtual QString toString() const;
    QList<Transaction> getTransactions() const;
    double getBalance() const;
    QString getAccountNo() const;
private:
    QString m_AccountNo;
    Customer m_AccHolder;
    double m_Balance;
    QList<Transaction> m_Transactions;
};

#endif // ACCOUNT_H
