#include "CreditCardAccount.h"

using namespace std;

namespace bank_account
{
    CreditCardAccount::CreditCardAccount()
    {
        this->adress = "";
        this->name = "";
        this->allowedMinus = 100.0;
        this->availableFunds = 1000.0;
        this->limitMoney = 100.0;
        this->dateTime.days = 1;
        this->dateTime.month = 1;
        this->dateTime.year = 2022;
    }

    CreditCardAccount::CreditCardAccount(Date creationDate, string nameUser, string adressUser, float amountMoney, float allowedMinus, float limitUsersMoney)
    {
        this->adress = adressUser;
        this->name = nameUser;
        this->limitMoney = limitUsersMoney;
        this->allowedMinus = allowedMinus;
        this->availableFunds = amountMoney;
        this->dateTime.days = creationDate.days;
        this->dateTime.month = creationDate.month;
        this->dateTime.year = creationDate.year;
    }

    CreditCardAccount::~CreditCardAccount()
    {
    }

    void CreditCardAccount::Print()
    {
        cout<< this->name << endl;
        cout<< this->adress << endl;
        cout<< this->availableFunds << endl;
        cout<< this->dateTime.days << ". " << this->dateTime.month << ". " << this->dateTime.year << endl;
        cout<< "CreditCardAccount" << endl;
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
                cout << "Credit Card:  Ne mozete podici taj iznos" << endl;
            }
        }
        else if (this->allowedMinus >= (amountMoney - this->availableFunds))
        {
            this->availableFunds = restAccount;
        }
        else
        {
            cout << "Credit Card:  Nije dozvoljen toliki minus" << endl;
        }
        return this->availableFunds;
    }

}