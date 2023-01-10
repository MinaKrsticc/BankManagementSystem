#include <string.h>
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
        // this->counter++;
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
        // this->counter--;
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

}