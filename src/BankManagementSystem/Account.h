#pragma once
#include <iostream>
using namespace std;
namespace my_Account
{
    struct Data
    {
        int days;
        int year;
        int month;
    };

    class Account
    {
    protected:
        char *name;
        char *adress;
        float availableFunds;
        Data dataTime;

    public:
        virtual float Deposit(float amountMoney) = 0;
        virtual float Withdraw(float amountMoney) = 0;
        virtual void Print() const;
        Account() {};
        // {name = nullptr;
        // adress = nullptr;
        // availableFunds = 1000;
        // dataTime.days = 1;
        // dataTime.month = 1;
        // dataTime.year = 2023;};
        ~Account() {};

        // friend ostream& operator<< (ostream& os, const Account& acc);
    };

    // ostream& operator<< (ostream& os, const Account& acc )
    // {
    //     os<<acc.name << " "<< acc.adress << " " <<acc.availableFunds<<endl;
        // acc.Print(os);
        // return os;
    // }
}