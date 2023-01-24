#pragma once
#include "Account.h"

using namespace std;

namespace bank_account
{
    class CreditCardAccount : public Account
    {
    private:
        float allowedMinus; // dozvoljeni minus
        float limitMoney;   // ogranicenje novca koji se moze podici

    public:
        CreditCardAccount();
        CreditCardAccount(Date creationDate, string nameUser, string adressUser, float amountMoney, float allowedMinus, float limitUsersMoney);
        ~CreditCardAccount();
        float Deposit(float amountMoney) override;
        float Withdraw(float amountMoney) override;
        bool FundsAvailableOnAccount(float amound) override;
        void Print() override;
        bool AvailableMinusOnAccount() override;
        bool AvaibleForWithdrawOnAccount() override;
    };
}