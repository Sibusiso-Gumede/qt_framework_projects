#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H

#include <QList>

class Account;

class AccountList: public QList<Account*>
{
public:
    void addAccount(Account* a);
    void displayList();
    void displayAccounts(QDate d);
    int countAccounts(double d);
    void deleteAll();
};

#endif // ACCOUNTLIST_H
