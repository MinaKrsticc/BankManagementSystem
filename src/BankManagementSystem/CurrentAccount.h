#pragma once
#include <iostream>
#include "Account.h"

using namespace std;
namespace my_Account
{
    class CurrentAccount : public Account
    {
        int limitMoney; //ogranicenje novca koji se moze podici

    public:
        CurrentAccount();
        CurrentAccount(Data creationData, char* name, char* adress, float amountMoney, int limitUsersMoney);
        ~CurrentAccount();
        float Deposit(float amountMoney) override;
        float Withdraw(float amountMoney) override;
        void Print() const override;
    };

}