#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "CurrentAccount.h"

using namespace std;
namespace my_Account
{
    CurrentAccount::CurrentAccount()
    {
        this->adress = nullptr;
        this->name = nullptr;
        this->limitMoney = 1000;
        this->availableFunds = 10000;
        this->dataTime.days = 1;
        this->dataTime.month = 1;
        this->dataTime.year = 2023;
    }

    CurrentAccount::~CurrentAccount()
    {
        if (this->name != nullptr || this->adress != nullptr)
        {
            delete this->name;
            delete this->adress;
            this->name = nullptr;
            this->adress = nullptr;
            this->availableFunds = 0;
        }
    }
    
    CurrentAccount::CurrentAccount(Data creationData, char* nameUser, char* adressUser, float amountMoney, int limitUsersMoney)
    {
        strcpy(this->adress, adressUser);
        strcpy(this->name, nameUser);
        //this->adress = adressUser;
        //this->name = nameUser;
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

    void CurrentAccount::Print() const
    {
        cout << this->name << " " << this->adress << " "<< this->availableFunds <<"  CurrentAccount" <<endl;
    }

}