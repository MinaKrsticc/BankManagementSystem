#pragma once
#include <vector>
#include <string.h>
#include <typeinfo>
#include "Bank.h"
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

void Bank::OpenAccount(Account &acc)
{
    Account *accountNew = &acc;
    this->accounts.push_back(accountNew);
}

void Bank::CloseAccount(Account &acc)
{
    int len = this->accounts.size();
    int i = 0;
    while (this->accounts[i] != &acc || len < i)
    {
        i++;
    }

    if (this->accounts[i] == &acc)
    {
        this->accounts.erase(this->accounts.begin() + i);
    }

    // while (this->accounts[i] != &acc && this->accounts[i] != nullptr)
    // {
    //     i++;
    // }
    // if (this->accounts[i] == &acc)
    // {
    //     Account *pomAcc = this->accounts[i];
    //     while (this->accounts[i + 1] != nullptr)
    //     {
    //         this->accounts[i] = this->accounts[i + 1];
    //         i++;
    //     }
    //     this->accounts.pop_back();
    //     pomAcc = nullptr;
    //     delete (pomAcc);
    // }
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
        if (this->accounts[i]->availableFunds >= amound)
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
        if ((typeid(*this->accounts[i]) == typeid(CreditCardAccount)))
        {
            if (this->accounts[i]->availableFunds < 0)
            {
                this->accounts[i]->Print();
            }
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
        if (this->accounts[i]->availableFunds > 0)
        {
            if ((typeid(*this->accounts[i]) == typeid(SavingAccount)))
            {
                if (this->accounts[i]->countWithdrawals + 1 <= SavingAccount::maxWithdrawals)
                {
                    this->accounts[i]->Print();
                    i++;
                }
            }
            else if ((typeid(*this->accounts[i]) == typeid(TrustAccount)))
            {
                if (this->accounts[i]->countWithdrawals + 1 <= TrustAccount::maxWithdrawals)
                {
                    this->accounts[i]->Print();
                    i++;
                }
            }
            else
            {
                this->accounts[i]->Print();
            }
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
    {   return a1->dateTime.days > a2->dateTime.days; });

    sort(this->accounts.begin(), this->accounts.end(), [](const Account *a1, const Account *a2)
    {   return a1->dateTime.month > a2->dateTime.month; });

    sort(this->accounts.begin(), this->accounts.end(), [](const Account *a1, const Account *a2)
    {   return a1->dateTime.year > a2->dateTime.year; });

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