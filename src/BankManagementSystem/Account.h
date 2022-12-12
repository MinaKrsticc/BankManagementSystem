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
        int availableFunds;
        Data dataTime;

    public:
        Account();
        virtual ~Account(){};
        virtual int Deposit(int amountMoney);
        virtual int Withdraw(int amountMoney);

        virtual void Print() const;
        // friend ostream& operator<< (ostream& os, const Account& acc);
    };

    // ostream& operator<< (ostream& os, const Account& acc )
    // {
    //     os<<acc.name << " "<< acc.adress << " " <<acc.availableFunds<<endl;
        // acc.Print(os);
        // return os;
    // }
}