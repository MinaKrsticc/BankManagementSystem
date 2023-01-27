#pragma once
#include "Account.h"

using namespace std;

namespace bank_account
{
    class CurrentAccount : public Account
    {
    private:
        float limitMoney; // ogranicenje novca koji se moze podici

    public:
        CurrentAccount();
        CurrentAccount(Date creationDate, string name, string adress, float amountMoney, float limitUsersMoney);
        ~CurrentAccount();
        float Deposit(float amountMoney) override;
        float Withdraw(float amountMoney) override;
        void Print() override;
        // void TimeTransaction() override;
        bool FundsAvailableOnAccount(float amount) override;
        bool AvailableMinusOnAccount() override;
        bool AvaibleForWithdrawOnAccount() override;
    };
}