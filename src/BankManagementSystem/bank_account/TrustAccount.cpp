#include <string>
#include <string.h>
#include "TrustAccount.h"

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
        this->availableFunds = this->availableFunds + amountMoney;
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
        cout<< this->dateTime.days << ". " << this->dateTime.month << ". " << this->dateTime.year << endl;
        cout<< "TrustAccount" <<endl;
    }

}