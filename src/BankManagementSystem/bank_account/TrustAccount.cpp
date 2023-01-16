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
        this->dateTime.days = 1;
        this->dateTime.month = 1;
        this->dateTime.year = 2022;
        this->countWithdrawals = 0;
    }

    TrustAccount::TrustAccount(Date creationData, string nameUser, string adressUser, float amountMoney)
    {
        this->name = nameUser;
        this->adress = adressUser;
        this->dateTime.days = creationData.days;
        this->dateTime.month = creationData.month;
        this->dateTime.year = creationData.year;
        this->availableFunds = amountMoney;
        this->minimumFunds = this->availableFunds * 0.3;
        this->countWithdrawals = 0;
    }

    TrustAccount::~TrustAccount()
    {
    }

    float TrustAccount::Deposit(float amountMoney)
    {
        CurrentDate();
        this->availableFunds = this->availableFunds + amountMoney;

        this->historyForDepositAvailableFunds.push_back(this->availableFunds);
        this->historyForDeposit.push_back(amountMoney);

        Bank::bankStatement.push_back(amountMoney);
        return this->availableFunds;
    }

    float TrustAccount::Withdraw(float amountMoney)
    {
        if(this->availableFunds >= amountMoney)
        {
            float remainingFounds = this->availableFunds - amountMoney;

            if (this->minimumFunds <= this->availableFunds)
            {
                if (this->countWithdrawals <= this->maxWithdrawals)
                {
                    this->countWithdrawals++;
                    this->availableFunds = remainingFounds;
                    this->historyForWithdrawAvailableFunds.push_back(this->availableFunds);
                    this->historyForWithdraw.push_back(amountMoney);

                    Bank::bankStatement.push_back(amountMoney);
                    CurrentDate();
                }
                else
                {
                    cout<<"TrustAccount:  Podigli ste vec "<< this->maxWithdrawals <<"puta "<<endl;
                }
            }
            else
            {
                cout<< "TrustAccount:  Ne mozete podici novac, zato sto imate minimalna sredstva koja moraju biti na racunu" <<endl;
            }
        }
        else
        {
            cout << "TrustAccount:  Ne mozete podici sredstva, nemate dovoljno" << endl;
        }

        return this->availableFunds;
    }

    void TrustAccount::Print()
    {
        cout << this->name <<endl;
        cout << this->adress <<endl;
        cout << this->availableFunds<<endl;
        cout << "countWithdrawals  "<< this->countWithdrawals<<endl;
        cout<< this->dateTime.days << ". " << this->dateTime.month << ". " << this->dateTime.year << endl;
        cout<< "TrustAccount" <<endl;
    }

    void TrustAccount::CurrentDate()
    {
        time_t ttime = time(0);
        tm *local_time = localtime(&ttime);
        this->dateTransaction.year = 1900 + local_time->tm_year;
        this->dateTransaction.month = 1 + local_time->tm_mon;
        this->dateTransaction.days = local_time->tm_mday;
    }
}