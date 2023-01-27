#pragma once
#include <vector>
#include <iostream>
#include "Date.h"
using namespace std;

namespace bank_account
{
    class Account
    {
    public:
        string name;
        string adress;
        float availableFunds;
        Date createDateTime;
        Date dateTransaction;
        int countWithdrawals = 0; // brojac koliko puta smo podigli novac

        
    public:
        virtual float Deposit(float amountMoney) = 0;
        virtual float Withdraw(float amountMoney) = 0;
        virtual void Print() = 0;
        virtual bool FundsAvailableOnAccount(float amount) = 0;
        virtual bool AvailableMinusOnAccount() = 0;
        virtual bool AvaibleForWithdrawOnAccount() = 0;
        // virtual void TimeTransaction() = 0;
        Account() = default;
        ~Account(){};
    };

}  