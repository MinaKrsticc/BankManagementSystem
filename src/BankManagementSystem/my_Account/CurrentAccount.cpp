#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "CurrentAccount.h"

using namespace std;
namespace my_Account
{
    CurrentAccount::CurrentAccount() //: Account()
    {
        this->adress = "";
        this->name = "";
        this->type = "CurrentAccount";
        this->availableFunds = 10000.0;
        this->dataTime.days = 1;
        this->dataTime.month = 1;
        this->dataTime.year = 2023;
        this->limitMoney = 1000.0;
    }

    CurrentAccount::~CurrentAccount()
    {
       if (this->name != "" || this->adress != "")
        {
            this->name = "";
            this->adress = "";
            this->availableFunds = 0;
        }
    }
    
    CurrentAccount::CurrentAccount(Data creationData, string nameUser, string adressUser, float amountMoney, float limitUsersMoney)
    {
        this->adress = adressUser;
        this->name = nameUser;
        this->type = "CurrentAccount";
        this->limitMoney = limitUsersMoney;
        this->availableFunds = amountMoney;
        this->dataTime.days = creationData.days;
        this->dataTime.month = creationData.month;
        this->dataTime.year = creationData.year;
    }

    float CurrentAccount::Deposit(float amountMoney) 
    {
        this->availableFunds = this->availableFunds + amountMoney;
        return this->availableFunds;
    }

    float CurrentAccount::Withdraw(float amountMoney)  // amoundMoney je kolicina novca koja se podize , funkcija vraca koliko je novca ostalo posle podizanja novca
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
        cout<< this->name << " " << this->adress << " " << this->availableFunds << ". " <<this->dataTime.days << ". " << this->dataTime.month <<". "<< this->dataTime.year <<" "<< this->type <<endl;
    }
}