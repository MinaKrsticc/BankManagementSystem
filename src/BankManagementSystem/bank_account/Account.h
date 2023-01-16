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
        Date dateTime;
        Date dateTransaction;
        int countWithdrawals = 0;
        
        vector<float> historyForDeposit;
        vector<float> historyForWithdraw;
        vector<float> historyForDepositAvailableFunds;
        vector<float> historyForWithdrawAvailableFunds;

    public:
        virtual float Deposit(float amountMoney) = 0;
        virtual float Withdraw(float amountMoney) = 0;
        virtual void CurrentDate() = 0;
        virtual void Print() = 0;
        Account() = default;
        ~Account(){};

    };
}