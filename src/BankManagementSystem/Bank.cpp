#include <vector>
#include <string.h>
#include <typeinfo>
#include "Bank.h"
#include "AccountTranslation.h"
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

// void Bank::PrintHistoryForDeposit()
// {
//     int len = this->accounts.size();
//     long unsigned int i;
//     int size = 0;
//     cout<<"Istorija uplacivanja novca za:  "<<endl;
//     for(int j = 0; j < len; j++)
//     {
//         i = 0;
//         if ((typeid(*this->accounts[j]) == typeid(CurrentAccount)))
//         {
//             cout<<"CurrentAccount"<<endl;
//             size = this->accounts[j]->historyForDeposit.size();
//         } 
//         else if ((typeid(*this->accounts[j]) == typeid(CreditCardAccount)))
//         {
//             cout<<"CreditCardAccount"<<endl;
//             size = this->accounts[j]->historyForDeposit.size();
//         }
//         else if ((typeid(*this->accounts[j]) == typeid(SavingAccount)))
//         {
//             cout<<"SavingAccount"<<endl;
//             size = this->accounts[j]->historyForDeposit.size();
//         }
//         else if ((typeid(*this->accounts[j]) == typeid(TrustAccount)))
//         {
//             cout<<"TrustAccount"<<endl;
//             size = this->accounts[j]->historyForDeposit.size();
//         }

//         while (i < size && size > 0)
//         {
//             cout << "Uplatio je korisnik: "<< this->accounts[j]->name
//             <<"  datuma: " <<this->accounts[j]->dateTransaction.days<<". "<< this->accounts[j]->dateTransaction.month<<". "<<this->accounts[j]->dateTransaction.year<<" "
//             << "iznos: "<< this->accounts[j]->historyForDeposit[i] <<"  trenutno stanje na racunu: " << this->accounts[j]->historyForDepositAvailableFunds[i]<<endl;
//             i++;
//         }
//     }
//     cout<<endl;
// }

void Bank::AccountDeposit(float amound, Account &acc)
{
    AccountTranslation *accTranslation = new AccountTranslation;
    int len = this->accounts.size();
    for(int j = 0; j < len; j++)
    {
        if ((typeid(*this->accounts[j]) == typeid(acc)))
        {
            if(this->accounts[j]->availableFunds == acc.availableFunds && this->accounts[j]->adress.compare(acc.adress) == 0 && this->accounts[j]->name.compare(acc.name) == 0
            && this->accounts[j]->createDateTime.days == acc.createDateTime.days && this->accounts[j]->createDateTime.month == acc.createDateTime.month && this->accounts[j]->createDateTime.year == acc.createDateTime.year)
            {
                accTranslation->name = this->accounts[j]->name;
                accTranslation->adress = this->accounts[j]->adress;

                accTranslation->amountMoney = amound;
                accTranslation->availableFunds = this->accounts[j]->Deposit(amound);

                time_t ttime = time(0);
                tm *local_time = localtime(&ttime);
                accTranslation->apdateDateTime.year  = 1900 + local_time->tm_year;
                accTranslation->apdateDateTime.month  = 1 + local_time->tm_mon;
                accTranslation->apdateDateTime.days = local_time->tm_mday;

                this->accountTranslation.push_back(accTranslation);
            }
        } 
    }
}

void Bank::AccountWithdraw(float amound, Account &acc)
{
    AccountTranslation *accTranslation = new AccountTranslation;
    int len = this->accounts.size();
    for(int j = 0; j < len; j++)
    {
        if ((typeid(*this->accounts[j]) == typeid(acc)))
        {
            if(this->accounts[j]->availableFunds == acc.availableFunds && this->accounts[j]->adress.compare(acc.adress) == 0 && this->accounts[j]->name.compare(acc.name) == 0
            && this->accounts[j]->createDateTime.days == acc.createDateTime.days && this->accounts[j]->createDateTime.month == acc.createDateTime.month && this->accounts[j]->createDateTime.year == acc.createDateTime.year)
            {
                accTranslation->name = this->accounts[j]->name;
                accTranslation->adress = this->accounts[j]->adress;
                // accTranslation->apdateDateTime.days = this->accounts[j]->dateTransaction.days;
                // accTranslation->apdateDateTime.month = this->accounts[j]->dateTransaction.month;
                // accTranslation->apdateDateTime.year = this->accounts[j]->dateTransaction.year;

                time_t ttime = time(0);
                tm *local_time = localtime(&ttime);
                accTranslation->apdateDateTime.year  = 1900 + local_time->tm_year;
                accTranslation->apdateDateTime.month  = 1 + local_time->tm_mon;
                accTranslation->apdateDateTime.days = local_time->tm_mday;

                accTranslation->amountMoney = amound;
                accTranslation->availableFunds = this->accounts[j]->Withdraw(amound);

                this->accountTranslation.push_back(accTranslation);
            }
        } 
    }
}

void Bank::PrintTranslation()
{
    int lenNewAcc = this->accountTranslation.size();
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

        cout << "Podigao je korisnik: "<< this->accountTranslation[i]->name
        <<"  datuma: " <<this->accountTranslation[i]->apdateDateTime.days<<". "<<this->accountTranslation[i]->apdateDateTime.month<<". "<<this->accountTranslation[i]->apdateDateTime.year<<"  "
        <<" iznos: "<<this->accountTranslation[i]->amountMoney <<"  trenutno stanje na racunu: " << this->accountTranslation[i]->availableFunds<<endl;
        cout<<endl;
    }
}
