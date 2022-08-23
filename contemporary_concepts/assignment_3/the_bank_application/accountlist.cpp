#include "accountlist.h"
#include "account.h"
#include <QTextStream>

QTextStream cout(stdout);

void AccountList::addAccount(Account* a)
{
    append(a);
}

void AccountList::displayList()
{
    //display the details of all the accounts.
    foreach(Account* acc, *this)
    {
        cout << "\n----------------------------------------\n";
        cout << "\n" << acc->toString()+"\n";
    }
}

void AccountList::displayAccounts(QDate d)
{
    bool sameDate(false);//a flag to confirm if a transaction
                        //was recorded on the same date as the
                        //parameter value.
    cout <<"Accounts which recorded a transaction on "
        <<d.toString()<<":\n";
    foreach(Account* acc, *this)
    {
        foreach(Transaction tran, acc->getTransactions())
            if(tran.getDate()==d)
                sameDate = true;
        if(sameDate)
            cout << acc->getAccountNo() << "\n";
    }
}

int AccountList::countAccounts(double d)
{
    //count all the accounts with a balance greater than the
    //parameter value.
    int count(0);
    foreach(Account* a, *this)
        if(a->getBalance() > d)
            ++count;
    return count;
}

void AccountList::deleteAll()
{
    qDeleteAll(*this);
    clear();
}
