#include <string.h>
#include "../Bank.h"
#include "CurrentAccount.h"

using namespace std;

namespace bank_account
{
    CurrentAccount::CurrentAccount() //: Account()
    {
        this->adress = "";
        this->name = "";
        this->availableFunds = 10000.0;
        this->dateTime.days = 1;
        this->dateTime.month = 1;
        this->dateTime.year = 2023;
        this->limitMoney = 1000.0;
    }

    CurrentAccount::~CurrentAccount()
    {
    }

    CurrentAccount::CurrentAccount(Date creationDate, string nameUser, string adressUser, float amountMoney, float limitUsersMoney)
    {
        this->adress = adressUser;
        this->name = nameUser;
        this->limitMoney = limitUsersMoney;
        this->availableFunds = amountMoney;
        this->dateTime.days = creationDate.days;
        this->dateTime.month = creationDate.month;
        this->dateTime.year = creationDate.year;
    }

    float CurrentAccount::Deposit(float amountMoney)
    {
        CurrentDate();
        this->availableFunds = this->availableFunds + amountMoney;

        this->historyForDepositAvailableFunds.push_back(this->availableFunds);
        this->historyForDeposit.push_back(amountMoney);

        Bank::bankStatement.push_back(amountMoney);
        return this->availableFunds;
    }

    float CurrentAccount::Withdraw(float amountMoney) // amoundMoney je kolicina novca koja se podize, funkcija vraca koliko je novca ostalo posle podizanja novca
    {
        if (this->availableFunds > amountMoney)
        {
            if (amountMoney <= this->limitMoney)
            {
                this->availableFunds = this->availableFunds - amountMoney;
                this->historyForWithdrawAvailableFunds.push_back(this->availableFunds);
                this->historyForWithdraw.push_back(amountMoney);

                Bank::bankStatement.push_back(amountMoney);
                CurrentDate();
            }
            else
            {
                cout<<"Prekoracili ste limit"<<endl;
            }
        }
        
        return this->availableFunds;
    }

    void CurrentAccount::Print()
    {
        cout<< this->name <<endl;
        cout<< this->adress <<endl;
        cout<< this->availableFunds <<endl;
        cout<< this->dateTime.days << ". " << this->dateTime.month << ". " << this->dateTime.year <<endl;
        cout<< "CurrentAccount" << endl;
    }

    void CurrentAccount::CurrentDate()
    {
        time_t ttime = time(0);
        tm *local_time = localtime(&ttime);
        this->dateTransaction.year = 1900 + local_time->tm_year;
        this->dateTransaction.month = 1 + local_time->tm_mon;
        this->dateTransaction.days = local_time->tm_mday;
    }
}