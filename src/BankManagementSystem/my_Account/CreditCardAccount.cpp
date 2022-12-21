#include <iostream>
#include "CreditCardAccount.h"
using namespace std;
namespace my_Account
{
    CreditCardAccount::CreditCardAccount()
    {
        this->adress = "";
        this->name = "";
        this->type = "CreditCardAccount";
        this->allowedMinus = 100.0;
        this->availableFunds = 1000.0;
        this->limitMoney = 100.0;
        this->dataTime.days = 1;
        this->dataTime.month = 1;
        this->dataTime.year = 2022;
    }

    CreditCardAccount::CreditCardAccount(Data creationData, string nameUser, string adressUser, float amountMoney, float allowedMinus, float limitUsersMoney)
    {
        this->adress = adressUser;
        this->name = nameUser;
        this->type = "CreditCardAccount";
        this->limitMoney = limitUsersMoney;
        this->allowedMinus = allowedMinus;
        this->availableFunds = amountMoney;
        this->dataTime.days = creationData.days;
        this->dataTime.month = creationData.month;
        this->dataTime.year = creationData.year;
    }
    
    CreditCardAccount::~CreditCardAccount()
    {
        if (this->name != "" || this->adress != "")
        {
            this->name = "";
            this->adress = "";
            this->availableFunds = 0;
            this->allowedMinus = 0;
        }
    }

    // void CreditCardAccount::Print()
    void my_Account::Account::Print()
    {
        cout << this->name << " " << this->adress << " " << this->availableFunds <<" "<< this->dataTime.days<<". "<<this->dataTime.month<<". "<<this->dataTime.year<< " "<<this->type << endl;
    }

    float CreditCardAccount::Deposit(float amountMoney)
    {
        this->availableFunds = this->availableFunds + amountMoney;
        return this->availableFunds;
    }

    float CreditCardAccount::Withdraw(float amountMoney)
    {
        float restAccount = this->availableFunds - amountMoney;

        if (this->availableFunds > amountMoney)
        {
            if (amountMoney <= this->limitMoney)
            {
                this->availableFunds = restAccount;
            }
            else
            {
                cout<<"Ne mozete podici taj iznos"<<endl;
            }
        }
        else if (this->allowedMinus >= (amountMoney - this->availableFunds))
        {
            this->availableFunds = restAccount;
        }
        else
        {
            cout<<"Nije dozvoljen toliki minus"<<endl;
        }

        return this->availableFunds;
    }
}