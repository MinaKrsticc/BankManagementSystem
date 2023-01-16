#pragma once
#include "Account.h"

using namespace std;
namespace bank_account
{
    class TrustAccount : public Account
    {
    public:
        // int countWithdrawals;// brojac koliko puta smo podigli novac
        static const int maxWithdrawals = 3; 
        float minimumFunds;

    public:
        TrustAccount();
        ~TrustAccount();
        float Deposit(float amountMoney) override;
        float Withdraw(float amountMoney) override;
        void Print() override;
        void CurrentDate() override;
        TrustAccount(Date creationDate, string nameUser, string adressUser, float amountMoney);
    };

}