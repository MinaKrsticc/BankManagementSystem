#include <iostream>
#include "CreditCardAccount.h"
using namespace std;
namespace my_Account
{
    CreditCardAccount::CreditCardAccount()
    {
        this->adress = nullptr;
        this->name = nullptr;
        this->allowedMinus = 100;
        this->availableFunds = 1000;
        this->limitMoney = 100;
        this->dataTime.days = 1;
        this->dataTime.month = 1;
        this->dataTime.year = 2022;
    }

    CreditCardAccount::CreditCardAccount(Data creationData, char *nameUser, char *adressUser, float amountMoney, int allowedMinus, int limitUsersMoney)
    {
        this->adress = adressUser;
        this->name = nameUser;
        this->limitMoney = limitUsersMoney;
        this->allowedMinus = allowedMinus;
        this->availableFunds = amountMoney;
        this->dataTime.days = creationData.days;
        this->dataTime.month = creationData.month;
        this->dataTime.year = creationData.year;
    }
    
    CreditCardAccount::~CreditCardAccount()
    {
        if (this->name != nullptr || this->adress != nullptr)
        {
            delete this->name;
            delete this->adress;
            this->name = nullptr;
            this->adress = nullptr;
            this->availableFunds = 0;
            this->allowedMinus = 0;
        }
    }

    void CreditCardAccount::Print() const
    {
        cout << this->name << " " << this->adress << " " << this->availableFunds << "  CreditCardAccount" << endl;
    }

    float CreditCardAccount::Deposit(float amountMoney)
    {
        this->availableFunds = this->availableFunds + amountMoney;
        return this->availableFunds;
    }

    float CreditCardAccount::Withdraw(float amountMoney)
    {
        int restAccount = this->availableFunds - amountMoney;

        if (this->availableFunds > amountMoney)
        {
            if (amountMoney <= this->limitMoney)
            {
                this->availableFunds = this->availableFunds - amountMoney;
            }
        }
        else if (this->allowedMinus > restAccount)
        {
            this->availableFunds = restAccount;
        }

        return this->availableFunds;
    }
}