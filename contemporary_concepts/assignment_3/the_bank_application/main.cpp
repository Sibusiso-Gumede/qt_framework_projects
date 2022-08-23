#include "accountlist.h"
#include "cheque.h"
#include "savings.h"
#include <QTextStream>

int main()
{
    QTextStream cout(stdout);

    //declare the container of pointers.
    AccountList bank;
    //declare and initialise the accounts.
    Account* savingsAcc1 = new Savings("643018", Customer("Thomas Jefferson","640191"));
    Account* chequeAcc1 = new Cheque("654018", Customer("Uncle Sam","551133"), 1000.00);
    Account* savingsAcc2 = new Savings("643019", Customer("Aristotle","650918"));
    Account* chequeAcc2 = new Cheque("654019", Customer("Tresmagastus","881011"), 500.00);
    Account* chequeAcc3 = new Cheque("654020", Customer("Mansa Mousa", "971105"), 2000.00);

    //perform some transactions on the accounts.
    savingsAcc2->deposit(2000.00);
    chequeAcc3->deposit(500.00);
    savingsAcc2->withdraw(750.00);
    chequeAcc2->deposit(400.00);
    savingsAcc1->deposit(400.00);
    chequeAcc1->deposit(250.00);
    chequeAcc3->withdraw(2500.00);
    chequeAcc2->withdraw(350.00);

    //add the accounts to the list.
    bank.addAccount(chequeAcc3);
    bank.addAccount(chequeAcc2);
    bank.addAccount(chequeAcc1);
    bank.addAccount(savingsAcc2);
    bank.addAccount(savingsAcc1);

    //get some information from the list.
    bank.displayList();
    bank.displayAccounts(QDate::currentDate());
    cout<<"\nNumber of accounts that have a balance that's more than 500.00: "
       <<bank.countAccounts(500.00);
    //clear memory.
    bank.deleteAll();

    return 0;
}
