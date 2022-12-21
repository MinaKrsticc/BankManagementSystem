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
        this->adress = "";
        this->name = "";
        this->type = "SavingAccount";
        this->availableFunds = 0;
        this->dataTime.days = 1;
        this->dataTime.month = 1;
        this->dataTime.year = 2022;
    }

    SavingAccount::~SavingAccount()
    {
        if (this->name != "" || this->adress != "")
        {
            this->name = "";
            this->adress = "";
            this->availableFunds = 0;
            this->interestRate = 0;
            this->countWithdrawals = 0;
        }
    }

    SavingAccount::SavingAccount(Data creationData, string userName, string userAdress, float userAmountMoney, float userInterestRate, float userMinimumFunds)
    {
        this->adress = userAdress;
        this->name = userName;
        this->type = "SavingAccount";
        this->dataTime.days = creationData.days;
        this->dataTime.month = creationData.month;
        this->dataTime.year = creationData.year;
        this->availableFunds = userAmountMoney;
        this->interestRate = userInterestRate;
        this->minimumFunds = userMinimumFunds;
        this->countWithdrawals = 3;
    }

    void SavingAccount::Print()
    {
        cout << this->name << " " << this->adress << " " << this->availableFunds <<" "<< this->type << " "
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
            if (this->availableFunds >= amountMoney)
            {
                this->availableFunds = this->availableFunds - amountMoney;
                if (this->minimumFunds <= this->availableFunds)
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
        else
        {
            cout<<"Podigli ste 3 puta novac ne moze vise"<<endl;
        }
        return this->availableFunds;
    }

}