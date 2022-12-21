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
        this->adress = "";
        this->name = "";
        this->type = "TrustAccount";
        this->availableFunds = 1000;
        this->minimumFunds = this->availableFunds * 0.3;
        this->dataTime.days = 1;
        this->dataTime.month = 1;
        this->dataTime.year = 2022;
        this->countWithdrawals = 3;
    }
    
    TrustAccount::TrustAccount(Data creationData, string nameUser, string adressUser, float amountMoney)
    {
        this->name = nameUser;
        this->adress = adressUser;
        this->type = "TrustAccount";
        this->dataTime.days = creationData.days;
        this->dataTime.month = creationData.month;
        this->dataTime.year = creationData.year;
        this->availableFunds = amountMoney;
        this->minimumFunds = this->availableFunds * 0.3;
        this->countWithdrawals = 3;

    }
    TrustAccount::~TrustAccount()
    {
        if (this->name != "" || this->adress != "")
        {
            this->name = "";
            this->adress = "";
            this->availableFunds = 0;
            this->minimumFunds = 0;
            this->countWithdrawals = 0;
        }
    }

    float TrustAccount::Deposit(float amountMoney)
    {
        this->availableFunds = this->availableFunds + amountMoney;
        return this->availableFunds;
    }

    float TrustAccount::Withdraw(float amountMoney)//dopraviti ovu funkciju tj proveriti
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

    void TrustAccount::Print()
    {
        cout << this->name << " " <<this->adress << " "<< this->availableFunds <<" "<<this->type <<endl;
    }
}