#pragma once
#include <iostream>
#include "Account.h"

using namespace std;
namespace my_Account
{
    class TrustAccount : Account
    {
    private:
        int countWithdrawals;
        float minimumFunds;

    public:
        TrustAccount();
        ~TrustAccount();
        int Deposit(int amountMoney) override;
        int Withdraw(int amountMoney) override;
        void Print() const override;
        // ostream& operator<< (ostream& os, const Account& info);

        TrustAccount(Data creationData, char* nameUser, char* adressUser, int amountMoney);

    };

}