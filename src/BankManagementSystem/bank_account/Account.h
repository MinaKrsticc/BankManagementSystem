#pragma once
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
        int countWithdrawals = 0;
        // static int counter;

    public:
        virtual float Deposit(float amountMoney) = 0;
        virtual float Withdraw(float amountMoney) = 0;
        virtual void Print() = 0;
        Account() = default;
        ~Account(){};
    };
    // int Account::counter = 0;
}