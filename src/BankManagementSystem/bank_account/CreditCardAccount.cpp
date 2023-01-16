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
        CurrentDate();
        this->availableFunds = this->availableFunds + amountMoney;

        this->historyForDeposit.push_back(amountMoney);
        this->historyForDepositAvailableFunds.push_back(this->availableFunds);

        Bank::bankStatement.push_back(amountMoney);
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
                this->historyForWithdrawAvailableFunds.push_back(this->availableFunds);
                this->historyForWithdraw.push_back(amountMoney);

                Bank::bankStatement.push_back(amountMoney);
                CurrentDate();
            }
            else
            {
                cout << "Credit Card:  Ne mozete podici taj iznos" << endl;
            }
        }
        else if (this->allowedMinus >= (amountMoney - this->availableFunds))
        {
            this->availableFunds = restAccount;
            this->historyForWithdrawAvailableFunds.push_back(this->availableFunds);
            this->historyForWithdraw.push_back(amountMoney);
            
            Bank::bankStatement.push_back(amountMoney);
            CurrentDate();
        }
        else
        {
            cout << "Credit Card:  Nije dozvoljen toliki minus" << endl;
        }
        return this->availableFunds;
    }

    void CreditCardAccount::CurrentDate()
    {
        time_t ttime = time(0);
        tm *local_time = localtime(&ttime);
        this->dateTransaction.year = 1900 + local_time->tm_year;
        this->dateTransaction.month = 1 + local_time->tm_mon;
        this->dateTransaction.days = local_time->tm_mday;
    }
}