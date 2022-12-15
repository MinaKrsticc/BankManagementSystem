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
        float Deposit(float amountMoney) override;
        float Withdraw(float amountMoney) override;
        void Print() const override;
        TrustAccount(Data creationData, char* nameUser, char* adressUser, float amountMoney);

    };

}