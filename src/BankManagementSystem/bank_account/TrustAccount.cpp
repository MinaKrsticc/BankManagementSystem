#include <string>
#include <string.h>
#include "TrustAccount.h"
#include "../Bank.h"

using namespace std;

namespace bank_account
{
    TrustAccount::TrustAccount()
    {
        this->adress = "";
        this->name = "";
        this->availableFunds = 1000;
        this->minimumFunds = this->availableFunds * 0.3;
        this->createDateTime.days = 1;
        this->createDateTime.month = 1;
        this->createDateTime.year = 2022;
        this->countWithdrawals = 0;
    }

    TrustAccount::TrustAccount(Date creationData, string nameUser, string adressUser, float amountMoney)
    {
        this->name = nameUser;
        this->adress = adressUser;
        this->createDateTime.days = creationData.days;
        this->createDateTime.month = creationData.month;
        this->createDateTime.year = creationData.year;
        this->availableFunds = amountMoney;
        this->minimumFunds = this->availableFunds * 0.3;
        this->countWithdrawals = 0;
    }

    TrustAccount::~TrustAccount()
    {
    }

    float TrustAccount::Deposit(float amountMoney)
    {
        this->availableFunds = this->availableFunds + amountMoney;

        return this->availableFunds;
    }

    float TrustAccount::Withdraw(float amountMoney)
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
                    cout << "TrustAccount: You raised already " << this->maxWithdrawals << "times " << endl;                
                }
            }
            else
            {
                cout << "TrustAccount:  You cannot withdraw money, because you have minimum funds that must be in the account" << endl;
            }
        }
        else
        {
            cout << "TrustAccount: You can't withdraw money, you don't have enough" << endl;
        }

        return this->availableFunds;
    }

    void TrustAccount::Print()
    {
        cout << this->name << endl;
        cout << this->adress << endl;
        cout << this->availableFunds << endl;
        cout << "count withdrawals  " << this->countWithdrawals << endl;
        cout << this->createDateTime.days << ". " << this->createDateTime.month << ". " << this->createDateTime.year << endl;
        cout << "TrustAccount" << endl;
    }

    bool TrustAccount::FundsAvailableOnAccount(float amount)
    {
        if (this->availableFunds >= amount)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool TrustAccount::AvailableMinusOnAccount()
    {
        return false;
    }

    bool TrustAccount::AvaibleForWithdrawOnAccount()
    {
        if (this->availableFunds > 0 && this->countWithdrawals + 1 <= this->maxWithdrawals)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // void TrustAccount::TimeTransaction()
    // {
    //     time_t ttime = time(0);
    //     tm *local_time = localtime(&ttime);
    //     this->dateTransaction.year = 1900 + local_time->tm_year;
    //     this->dateTransaction.month = 1 + local_time->tm_mon;
    //     this->dateTransaction.days = local_time->tm_mday;
    // }
}