#include <string>
#include <string.h>
#include "SavingAccount.h"

using namespace std;

namespace bank_account
{
    int counterSavingAcc;

    SavingAccount::SavingAccount()
    {
        this->minimumFunds = 1000;
        this->adress = "";
        this->name = "";
        this->availableFunds = 0;
        this->dateTime.days = 1;
        this->dateTime.month = 1;
        this->dateTime.year = 2022;
        this->interestRate = 0.03;
        this->countWithdrawals = 0;
    }

    SavingAccount::~SavingAccount()
    {
    }

    SavingAccount::SavingAccount(Date creationDate, string userName, string userAdress, float userAmountMoney, float userMinimumFunds)
    {
        this->adress = userAdress;
        this->name = userName;
        this->interestRate = 0.03;
        this->dateTime.days = creationDate.days;
        this->dateTime.month = creationDate.month;
        this->dateTime.year = creationDate.year;
        this->availableFunds = userAmountMoney;
        this->minimumFunds = userMinimumFunds;
        this->countWithdrawals = 0;
    }

    void SavingAccount::Print()
    {
        cout << this->name << endl;
        cout << this->adress << endl;
        cout << this->availableFunds << endl;
        cout << "SavingAccount:  Kamata je  " << this->interestRate << endl;
        cout << this->dateTime.days <<  ". " << this->dateTime.month << ". " << this->dateTime.year << endl;
        cout << "SavingAccount" << endl;
    }

    float SavingAccount::Deposit(float amountMoney)
    {
        this->availableFunds = this->availableFunds + amountMoney + (amountMoney * this->interestRate);
        return this->availableFunds;
    }

    float SavingAccount::Withdraw(float amountMoney)
    {
        if (this->availableFunds >= amountMoney)
        {
            float remainingFounds = this->availableFunds - amountMoney;

            if (this->minimumFunds <= this->availableFunds)
            {
                if (this->countWithdrawals <= this->maxWithdrawals)
                {
                    this->countWithdrawals++;
                    this->availableFunds = remainingFounds;
                }
                else
                {
                    cout << "SavingAccount:  Podigli ste vec " << this->maxWithdrawals << "puta " << endl;
                }
            }
            else
            {
                cout << "SavingAccount:  Ne mozete podici novac, zato sto imate minimalna sredstva koja moraju biti na racunu" << endl;
            }
        }
        else
        {
            cout << " SavingAccount:  Ne mozete podici sredstva, nemate dovoljno" << endl;
        }
        return this->availableFunds;
    }

}