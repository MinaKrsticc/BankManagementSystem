#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include "SavingAccount.h"

using namespace std;
namespace my_Account
{
    SavingAccount::SavingAccount()
    {
        this->interestRate = 0.03;
        this->countWithdrawals = 3;
        this->minimumFunds = 1000;
        this->adress = nullptr;
        this->name = nullptr;
        this->availableFunds = 0;
        this->dataTime.days = 1;
        this->dataTime.month = 1;
        this->dataTime.year = 2022;
    }

    SavingAccount::~SavingAccount()
    {
        if (this->name != nullptr || this->adress != nullptr)
        {
            delete this->name;
            delete this->adress;
            this->adress = nullptr;
            this->name = nullptr;
            this->availableFunds = 0;
            this->interestRate = 0;
            this->countWithdrawals = 0;
        }
    }

    SavingAccount::SavingAccount(Data creationData, char *userName, char *userAdress, float userAmountMoney, float userInterestRate, float userMinimumFunds)
    {
        this->adress = userAdress;
        this->name = userName;
        this->dataTime.days = creationData.days;
        this->dataTime.month = creationData.month;
        this->dataTime.days = creationData.days;
        this->availableFunds = userAmountMoney;
        this->interestRate = userInterestRate;
        this->minimumFunds = userMinimumFunds;
        this->countWithdrawals = 3;
    }

    void SavingAccount::Print() const
    {
        cout << this->name << " " << this->adress << " " << this->availableFunds << "SavingAccount"
             << "Kamata je  " << this->interestRate << endl;
    }

    float SavingAccount::Deposit(float amountMoney)
    {
        this->availableFunds = this->availableFunds + amountMoney + (amountMoney * this->interestRate);
        return this->availableFunds;
    }

    float SavingAccount::Withdraw(float amountMoney)
    {
        if (this->countWithdrawals > 0 && this->countWithdrawals <= 3)
        {
            if (this->availableFunds > amountMoney)
            {
                this->availableFunds = this->availableFunds - amountMoney;
                if (this->minimumFunds > this->availableFunds)
                {
                    this->countWithdrawals--;
                }
                else
                {
                    cout << "Ne mozete podici sredstva" << endl;
                    this->availableFunds = this->availableFunds + amountMoney;
                }
            }
        }
        return this->availableFunds;
    }

}