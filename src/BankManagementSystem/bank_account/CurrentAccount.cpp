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
        this->createDateTime.days = 1;
        this->createDateTime.month = 1;
        this->createDateTime.year = 2023;
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
        this->createDateTime.days = creationDate.days;
        this->createDateTime.month = creationDate.month;
        this->createDateTime.year = creationDate.year;
    }

    float CurrentAccount::Deposit(float amountMoney)
    {
        this->availableFunds = this->availableFunds + amountMoney;

        return this->availableFunds;
    }

    float CurrentAccount::Withdraw(float amountMoney) // amoundMoney je kolicina novca koja se podize, funkcija vraca koliko je novca ostalo posle podizanja novca
    {
        if (this->availableFunds > amountMoney)
        {
            if (amountMoney <= this->limitMoney)
            {
                this->availableFunds = this->availableFunds - amountMoney;
            }
            else
            {
                cout << "You have exceeded the limit" << endl;
            }
        }

        return this->availableFunds;
    }

    void CurrentAccount::Print()
    {
        cout << this->name << endl;
        cout << this->adress << endl;
        cout << this->availableFunds << endl;
        cout << this->createDateTime.days << ". " << this->createDateTime.month << ". " << this->createDateTime.year << endl;
        cout << "CurrentAccount" << endl;
    }

    bool CurrentAccount::FundsAvailableOnAccount(float amount)
    {
        if (this->availableFunds >= amount)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool CurrentAccount::AvailableMinusOnAccount()
    {
        return false;
    }

    bool CurrentAccount::AvaibleForWithdrawOnAccount()
    {
        if (this->availableFunds > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
        
    // void CurrentAccount::TimeTransaction()
    // {
    //     time_t ttime = time(0);
    //     tm *local_time = localtime(&ttime);
    //     this->dateTransaction.year = 1900 + local_time->tm_year;
    //     this->dateTransaction.month = 1 + local_time->tm_mon;
    //     this->dateTransaction.days = local_time->tm_mday;
    // }
}