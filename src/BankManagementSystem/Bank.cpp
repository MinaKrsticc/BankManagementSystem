#include <vector>
#include <typeinfo>
#include "Bank.h"
#include "AccountTransaction.h"
#include <bits/stdc++.h>
#include "bank_account/Account.h"
#include "bank_account/CurrentAccount.h"
#include "bank_account/SavingAccount.h"
#include "bank_account/CreditCardAccount.h"
#include "bank_account/TrustAccount.h"

using namespace std;
using namespace bank_account;

Bank::Bank()
{
}

Bank::~Bank()
{
    if (this->accounts.size() != 0)
    {
        // for (int i = 0; i < this->accounts.size(); i++)
        // {
        //     this->accounts[i] = nullptr;
        //     // delete accounts[i];
        // }
        this->accounts.clear();
    }
}

void Bank::OpenAccount(Account &accountOpen)
{
    Account *accountNew = &accountOpen;
    this->accounts.push_back(accountNew);
}

void Bank::CloseAccount(Account &accountClose)
{
    int len = this->accounts.size();
    int i = 0;

    while (this->accounts[i] != &accountClose || len < i)
    {
        i++;
    }
    if (this->accounts[i] == &accountClose)
    {
        this->accounts.erase(this->accounts.begin() + i);
    }
    cout<<"close "<< endl;
}

void Bank::PrintAccounts()
{
    int len = this->accounts.size();
    for (int i = 0; i < len; i++)
    {
        this->accounts[i]->Print();
    }
    cout << endl;
}

void Bank::StatisticOfAccount()
{
    int len = this->accounts.size();
    cout << endl;
    cout << "There is in the bank : " << len << " accoounts" << endl;

    int countCurrentAccount = 0;
    int countCreditAccount = 0;
    int countSavingAccount = 0;
    int countTrustAccount = 0;

    for (int i = 0; i < len; i++)
    {
        if ((typeid(*this->accounts[i]) == typeid(CurrentAccount)))
        {
            countCurrentAccount++;
        }
        else if ((typeid(*this->accounts[i]) == typeid(CreditCardAccount)))
        {
            countCreditAccount++;
        }
        else if ((typeid(*this->accounts[i]) == typeid(SavingAccount)))
        {
            countSavingAccount++;
        }
        else if ((typeid(*this->accounts[i]) == typeid(TrustAccount)))
        {
            countTrustAccount++;
        }
    }
    cout << "CurrentAccount: " << countCurrentAccount << endl;
    cout << "CreditCardAccount: " << countCreditAccount << endl;
    cout << "SavingAccount: " << countSavingAccount << endl;
    cout << "TrustAccount: " << countTrustAccount << endl;
    cout << endl;
}

void Bank::PrintAccountThatHaveMoreThanAmount(float amount) // svi racuni koji imaju vise od amound novca
{
    cout << "All accounts that have at least " << amount << " in the account:" << endl;

    int len = this->accounts.size();
    for (int i = 0; i < len; i++)
    {
        if (this->accounts[i]->FundsAvailableOnAccount(amount) == true)
        {
            this->accounts[i]->Print();
        }
    }
    cout << endl;
}

void Bank::PrintAccountThatHasAvailableMinus() // svi racuni koji su u minusu
{
    cout << "All accounts that have a minus:" << endl;

    int len = this->accounts.size();
    for (int i = 0; i < len; i++)
    {
        if (this->accounts[i]->AvailableMinusOnAccount() == true)
        {
            this->accounts[i]->Print();
        }
    }
    cout << endl;
}

void Bank::PrintAccountAvaibleForWithdraw() // svi racuni dostupni za podizanje
{
    cout << "All accounts that have the ability to withdraw money: " << endl;

    int len = this->accounts.size();
    for (int i = 0; i < len; i++)
    {
        if (this->accounts[i]->AvaibleForWithdrawOnAccount() == true)
        {
            this->accounts[i]->Print();
        }
    }
    cout << endl;
}

void Bank::SortByAmount()
{
    sort(this->accounts.begin(), this->accounts.end(), [](const Account *a1, const Account *a2)
        { return a1->availableFunds > a2->availableFunds; });

    PrintAccounts();
    cout << "SortAndPrintForAmount" << endl;
    cout << endl;
}

void Bank::SortByDate()
{
    sort(this->accounts.begin(), this->accounts.end(), [](const Account *a1, const Account *a2)
        { return a1->createDateTime.days > a2->createDateTime.days; });

    sort(this->accounts.begin(), this->accounts.end(), [](const Account *a1, const Account *a2)
        { return a1->createDateTime.month > a2->createDateTime.month; });

    sort(this->accounts.begin(), this->accounts.end(), [](const Account *a1, const Account *a2)
        { return a1->createDateTime.year > a2->createDateTime.year; });

    PrintAccounts();
    cout << "SortAndPrintForDate" << endl;
    cout << endl;
}

void Bank::SortByName()
{
    sort(this->accounts.begin(), this->accounts.end(), [](const Account *a1, const Account *a2)
        { return a1->name.compare(a2->name) < 0; });

    PrintAccounts();
    cout << "SortAndPrintForName" << endl;
    cout << endl;
}

void Bank::ExecutionOfDeposits(float amount, Account &account)
{
    AccountTransaction *accTransaction = new AccountTransaction(&account, amount);
    accTransaction->accountTransaction->availableFunds = account.Deposit(amount);
    accTransaction->transactionIdentifierDeposit = true;

    this->accountTransactionBank.push_back(accTransaction);
}

void Bank::ExecutionOfWithdraw(float amount, Account &account)
{
    AccountTransaction *accTransaction = new AccountTransaction(&account, amount);
    accTransaction->accountTransaction->availableFunds = account.Withdraw(amount);
    accTransaction->transactionIdentifierWithdraw = true;

    this->accountTransactionBank.push_back(accTransaction);

    // accTransaction->accountTransaction->name = this->accounts[j]->name;
    // accTransaction->accountTransaction->adress = this->accounts[j]->adress;
    // accTransaction->accountTransaction->availableFunds = this->accounts[j]->Withdraw(amount);
    // accTransaction->amountMoney = amount;
    // accTransaction->accountTransaction->dateTransaction.days = this->accounts[j]->dateTransaction.days;
    // accTransaction->accountTransaction->dateTransaction.month = this->accounts[j]->dateTransaction.month;
    // accTransaction->accountTransaction->dateTransaction.year = this->accounts[j]->dateTransaction.year;
}

void Bank::PrintAccountsThatMadeTranslation()
{
    int len = this->accountTransactionBank.size();
    for (int i = 0; i < len; i++)
    {
        if ((typeid(this->accountTransactionBank[i]->accountTransaction) == typeid(CurrentAccount)))
        {
            cout << "CurrentAccount" << endl;
        }
        else if ((typeid(this->accountTransactionBank[i]->accountTransaction) == typeid(CreditCardAccount)))
        {
            cout << "CreditCardAccount" << endl;
        }
        else if ((typeid(this->accountTransactionBank[i]->accountTransaction) == typeid(SavingAccount)))
        {
            cout << "SavingAccount" << endl;
        }
        else if ((typeid(this->accountTransactionBank[i]->accountTransaction) == typeid(TrustAccount)))
        {
            cout << "TrustAccount" << endl;
        }

        if(this->accountTransactionBank[i]->transactionIdentifierDeposit == true)
        {
            cout << "The deposit was made by the user: " << this->accountTransactionBank[i]->accountTransaction->name
            << "  the date of the transaction: " << this->accountTransactionBank[i]->dateTransaction.days << ". " << this->accountTransactionBank[i]->dateTransaction.month << ". " << this->accountTransactionBank[i]->dateTransaction.year << "  "
            << " amount: " << this->accountTransactionBank[i]->amountMoney << "  current account balance: " << this->accountTransactionBank[i]->accountTransaction->availableFunds << endl;
            cout << endl;
        }
        else if(this->accountTransactionBank[i]->transactionIdentifierWithdraw == true)
        {
            cout << "The withdrawal was made by the user: " << this->accountTransactionBank[i]->accountTransaction->name
            << " the date of the transaction: " << this->accountTransactionBank[i]->dateTransaction.days << ". " << this->accountTransactionBank[i]->dateTransaction.month << ". " << this->accountTransactionBank[i]->dateTransaction.year << "  "
            << " amount: " << this->accountTransactionBank[i]->amountMoney << "  current account balance: " << this->accountTransactionBank[i]->accountTransaction->availableFunds << endl;
            cout << endl;
        }
    }
}
