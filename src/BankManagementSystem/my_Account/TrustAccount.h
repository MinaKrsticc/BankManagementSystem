#pragma once
#include <iostream>
#include "Account.h"

using namespace std;
namespace my_Account
{
    class TrustAccount : public Account
    {
    private:
        int countWithdrawals;
        float minimumFunds;

    public:
        TrustAccount();
        ~TrustAccount();
        float Deposit(float amountMoney);
        float Withdraw(float amountMoney);
        void Print();
        TrustAccount(Data creationData, string nameUser, string adressUser, float amountMoney);
    };

}