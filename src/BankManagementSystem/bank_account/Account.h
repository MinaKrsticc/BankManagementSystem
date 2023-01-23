#pragma once
#include <vector>
#include <iostream>

using namespace std;

namespace bank_account
{
    struct Date
    {
        int days;
        int year;
        int month;
    };

    class Account
    {
    public:
        string name;
        string adress;
        float availableFunds;
        Date createDateTime;
        Date dateTransaction;
        int countWithdrawals = 0;
        
    public:
        virtual float Deposit(float amountMoney) = 0;
        virtual float Withdraw(float amountMoney) = 0;
        virtual void ApdateDate() = 0;
        virtual void Print() = 0;
        virtual bool FundsAvailableOnAccount(float amound) = 0;
        virtual bool AvailableMinusOnAccount() = 0;
        virtual bool AvaibleForWithdrawOnAccount() = 0;
        Account() = default;
        ~Account(){};
    };
}