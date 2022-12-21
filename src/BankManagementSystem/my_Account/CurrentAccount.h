#pragma once
#include <iostream>
#include "Account.h"

using namespace std;
namespace my_Account
{
    class CurrentAccount : public Account
    {
    private:
        float limitMoney; // ogranicenje novca koji se moze podici

    public:
        CurrentAccount();
        CurrentAccount(Data creationData, string name, string adress, float amountMoney, float limitUsersMoney);
        ~CurrentAccount();
        float Deposit(float amountMoney);
        float Withdraw(float amountMoney);
        void Print();
    };
}