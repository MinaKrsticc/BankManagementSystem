#pragma once
#include <iostream>
#include "Account.h"

using namespace std;
namespace my_Account
{
    class CurrentAccount : Account
    {
        int limitMoney; //ogranicenje novca koji se moze podici

    public:
        CurrentAccount();
        CurrentAccount(Data creationData, char* name, char* adress, int amountMoney, int limitUsersMoney);
        ~CurrentAccount();
        int Deposit(int amountMoney) override;
        int Withdraw(int amountMoney) override;
        void Print() const override;
    };

}