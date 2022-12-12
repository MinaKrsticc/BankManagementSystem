#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include "TrustAccount.h"

using namespace std;
namespace my_Account
{
    TrustAccount::TrustAccount()
    {
        this->adress = nullptr;
        this->name = nullptr;
        this->availableFunds = 1000;
        this->minimumFunds = this->availableFunds * 0,3;
        this->dataTime.days = 1;
        this->dataTime.month = 1;
        this->dataTime.year = 2022;
        this->countWithdrawals = 3;

    }
    
    TrustAccount::TrustAccount(Data creationData, char* nameUser, char* adressUser, int amountMoney)
    {
        this->name = nameUser;
        this->adress = adressUser;
        this->dataTime.days = creationData.days;
        this->dataTime.month = creationData.month;
        this->dataTime.days = creationData.days;
        this->availableFunds = amountMoney;
        this->minimumFunds = this->availableFunds * 0,3;
        this->countWithdrawals = 3;

    }
    TrustAccount::~TrustAccount()
    {
            {
        if (this->name != nullptr || this->adress != nullptr)
        {
            delete this->name;
            delete this->adress;
            this->adress = nullptr;
            this->name = nullptr;
            this->availableFunds = 0;
            this->minimumFunds = 0;
            this->countWithdrawals = 0;
        }
    }
    }

    int TrustAccount::Deposit(int amountMoney)
    {
        this->availableFunds = this->availableFunds + amountMoney;
        return this->availableFunds;
    }

    int TrustAccount::Withdraw(int amountMoney)//dopraviti ovu funkciju tj proveriti
    {
        if (this->countWithdrawals > 0 && this->countWithdrawals <= 3)
        {
            int restAccount = this->availableFunds - amountMoney;

            if (this->availableFunds > amountMoney && restAccount < this->minimumFunds)
            {
                this->availableFunds = this->availableFunds - amountMoney;
                this->countWithdrawals--; 
            }
        }
        return this->availableFunds;
    }

    void TrustAccount::Print() const
    {
        cout << this->name << " " <<this->adress << " "<< this->availableFunds <<"  TrustAccount" <<endl;
    }
}