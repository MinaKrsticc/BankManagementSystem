#include <vector>
#include <string.h>
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
        for (int i = 0; i < this->accounts.size(); i++)
        {
            this->accounts[i] = nullptr;
        }
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
}

void Bank::Print()
{
    int len = this->accounts.size();
    for (int i = 0; i < len; i++)
    {
        this->accounts[i]->Print();
    }
}

void Bank::StatisticOfAccount()
{
    int len = this->accounts.size();
    cout << endl;
    cout << "U banci ima : " << len << " account-a" << endl;

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

void Bank::FundsAvailable(float amound) // svi racuni koji imaju vise od amound novca
{
    cout << "Svi racuni koji imaju bar " << amound << " na racunu:" << endl;

    int len = this->accounts.size();
    for (int i = 0; i < len; i++)
    {
        if(this->accounts[i]->FundsAvailableOnAccount(amound) == true)
        {
            this->accounts[i]->Print();
        }
    }
    cout << endl;
}

void Bank::AvailableMinus() // svi racuni koji su u minusu
{
    cout << "Svi racuni koji su u minusu:" << endl;

    int len = this->accounts.size();
    for (int i = 0; i < len; i++)
    {
        if(this->accounts[i]->AvailableMinusOnAccount() == true)
        {
            this->accounts[i]->Print();
        }
    }
    cout << endl;
}

void Bank::AvaibleForWithdraw() // svi racuni dostupni za podizanje
{
    cout << "Svi racuni koji mogu da podignu novac: " << endl;

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

void Bank::SortAndPrintForAmount()
{
    int len = this->accounts.size();
    sort(this->accounts.begin(), this->accounts.end(), [](const Account *a1, const Account *a2)
    { return a1->availableFunds > a2->availableFunds; });

    for (int j = 0; j < len; j++)
    {
        this->accounts[j]->Print();
    }
    cout << "SortAndPrintForAmount" << endl;
    cout << endl;
}

void Bank::SortAndPrintForDate()
{
    int len = this->accounts.size();

    sort(this->accounts.begin(), this->accounts.end(), [](const Account *a1, const Account *a2)
    {   return a1->createDateTime.days > a2->createDateTime.days; });

    sort(this->accounts.begin(), this->accounts.end(), [](const Account *a1, const Account *a2)
    {   return a1->createDateTime.month > a2->createDateTime.month; });

    sort(this->accounts.begin(), this->accounts.end(), [](const Account *a1, const Account *a2)
    {   return a1->createDateTime.year > a2->createDateTime.year; });

    for (int j = 0; j < len; j++)
    {
        this->accounts[j]->Print();
    }
    cout << "SortAndPrintForDate" << endl;
    cout << endl;
}

void Bank::SortAndPrintForName()
{
    int len = this->accounts.size();

    sort(this->accounts.begin(), this->accounts.end(), [](const Account *a1, const Account *a2)
    {
        return a1->name.compare(a2->name) < 0;
    });

    for (int j = 0; j < len; j++)
    {
        this->accounts[j]->Print();
    }
    cout << "SortAndPrintForName" << endl;
    cout << endl;
}

void Bank::AccountDeposit(float amound, Account &account)
{
    AccountTransaction *accTransaction = new AccountTransaction;
    int len = this->accounts.size();
    for(int j = 0; j < len; j++)
    {
        if ((typeid(*this->accounts[j]) == typeid(account)))
        {
            if(this->accounts[j]->availableFunds == account.availableFunds && this->accounts[j]->adress.compare(account.adress) == 0 && this->accounts[j]->name.compare(account.name) == 0
            && this->accounts[j]->createDateTime.days == account.createDateTime.days && this->accounts[j]->createDateTime.month == account.createDateTime.month && this->accounts[j]->createDateTime.year == account.createDateTime.year)
            {
                accTransaction->name = this->accounts[j]->name;
                accTransaction->adress = this->accounts[j]->adress;

                accTransaction->amountMoney = amound;
                accTransaction->availableFunds = this->accounts[j]->Deposit(amound);

                time_t ttime = time(0);
                tm *local_time = localtime(&ttime);
                accTransaction->apdateDateTime.year  = 1900 + local_time->tm_year;
                accTransaction->apdateDateTime.month  = 1 + local_time->tm_mon;
                accTransaction->apdateDateTime.days = local_time->tm_mday;

                this->accountTransaction.push_back(accTransaction);
            }
        } 
    }
}

void Bank::AccountWithdraw(float amound, Account &account)
{
    AccountTransaction *accTransaction = new AccountTransaction;
    int len = this->accounts.size();
    for(int j = 0; j < len; j++)
    {
        if ((typeid(*this->accounts[j]) == typeid(account)))
        {
            if(this->accounts[j]->availableFunds == account.availableFunds && this->accounts[j]->adress.compare(account.adress) == 0 && this->accounts[j]->name.compare(account.name) == 0
            && this->accounts[j]->createDateTime.days == account.createDateTime.days && this->accounts[j]->createDateTime.month == account.createDateTime.month && this->accounts[j]->createDateTime.year == account.createDateTime.year)
            {
                accTransaction->name = this->accounts[j]->name;
                accTransaction->adress = this->accounts[j]->adress;
                // accTranslation->apdateDateTime.days = this->accounts[j]->dateTransaction.days;
                // accTranslation->apdateDateTime.month = this->accounts[j]->dateTransaction.month;
                // accTranslation->apdateDateTime.year = this->accounts[j]->dateTransaction.year;

                time_t ttime = time(0);
                tm *local_time = localtime(&ttime);
                accTransaction->apdateDateTime.year  = 1900 + local_time->tm_year;
                accTransaction->apdateDateTime.month  = 1 + local_time->tm_mon;
                accTransaction->apdateDateTime.days = local_time->tm_mday;

                accTransaction->amountMoney = amound;
                accTransaction->availableFunds = this->accounts[j]->Withdraw(amound);

                this->accountTransaction.push_back(accTransaction);
            }
        } 
    }
}

void Bank::PrintTranslation()
{
    int lenNewAcc = this->accountTransaction.size();
    for (int i = 0; i < lenNewAcc; i++)
    {
        if ((typeid(*this->accounts[i]) == typeid(CurrentAccount)))
        {
            cout<<"CurrentAccount"<<endl;
        } 
        else if ((typeid(*this->accounts[i]) == typeid(CreditCardAccount)))
        {
            cout<<"CreditCardAccount"<<endl;
        }
        else if ((typeid(*this->accounts[i]) == typeid(SavingAccount)))
        {
            cout<<"SavingAccount"<<endl;
        }
        else if ((typeid(*this->accounts[i]) == typeid(TrustAccount)))
        {
            cout<<"TrustAccount"<<endl;
        }

        cout << "Podigao je korisnik: "<< this->accountTransaction[i]->name
        <<"  datuma: " <<this->accountTransaction[i]->apdateDateTime.days<<". "<<this->accountTransaction[i]->apdateDateTime.month<<". "<<this->accountTransaction[i]->apdateDateTime.year<<"  "
        <<" iznos: "<<this->accountTransaction[i]->amountMoney <<"  trenutno stanje na racunu: " << this->accountTransaction[i]->availableFunds<<endl;
        cout<<endl;
    }
}
