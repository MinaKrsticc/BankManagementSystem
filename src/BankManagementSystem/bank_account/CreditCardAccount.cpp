#include "CreditCardAccount.h"
#include "../Bank.h"
#include <vector>
#include <ctime>

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
        this->createDateTime.days = 1;
        this->createDateTime.month = 1;
        this->createDateTime.year = 2022;
    }

    CreditCardAccount::CreditCardAccount(Date creationDate, string nameUser, string adressUser, float amountMoney, float allowedMinus, float limitUsersMoney)
    {
        this->adress = adressUser;
        this->name = nameUser;
        this->limitMoney = limitUsersMoney;
        this->allowedMinus = allowedMinus;
        this->availableFunds = amountMoney;
        this->createDateTime.days = creationDate.days;
        this->createDateTime.month = creationDate.month;
        this->createDateTime.year = creationDate.year;
    }

    CreditCardAccount::~CreditCardAccount()
    {
    }

    void CreditCardAccount::Print()
    {
        cout<< this->name << endl;
        cout<< this->adress << endl;
        cout<< this->availableFunds << endl;
        cout<< this->createDateTime.days << ". " << this->createDateTime.month << ". " << this->createDateTime.year << endl;
        cout<< "CreditCardAccount" << endl;
    }

    float CreditCardAccount::Deposit(float amountMoney)
    {
        ApdateDate();
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
                ApdateDate();
            }
            else
            {
                cout << "Credit Card:  Ne mozete podici taj iznos" << endl;
            }
        }
        else if (this->allowedMinus >= (amountMoney - this->availableFunds))
        {
            this->availableFunds = restAccount;

            ApdateDate();
        }
        else
        {
            cout << "Credit Card:  Nije dozvoljen toliki minus" << endl;
        }
        return this->availableFunds;
    }

    void CreditCardAccount::ApdateDate()
    {
        time_t ttime = time(0);
        tm *local_time = localtime(&ttime);
        this->dateTransaction.year = 1900 + local_time->tm_year;
        this->dateTransaction.month = 1 + local_time->tm_mon;
        this->dateTransaction.days = local_time->tm_mday;
    }

    bool CreditCardAccount::FundsAvailableOnAccount(float amound)
    {
       if(this->availableFunds >= amound)
       {
            return true;
       } 
       else
       {
            return false;
       }
    }

    bool CreditCardAccount::AvailableMinusOnAccount() 
    {
        if(this->availableFunds < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool CreditCardAccount::AvaibleForWithdrawOnAccount()
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
}