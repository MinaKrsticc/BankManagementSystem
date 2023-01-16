#pragma once
#include "Account.h"

using namespace std;

namespace bank_account
{
    class SavingAccount : public Account
    {
    public:
        float interestRate;   // kamatna stopa koja se dodaje prilikom placivanja novca
        // int countWithdrawals; // brojac koliko puta smo podigli novac
        static const int maxWithdrawals = 3;
        float minimumFunds; // minimalni iznos koji mora da ostane na kartici

    public:
        SavingAccount();
        SavingAccount(Date creationDate, string userName, string userAdress, float userAmountMoney, float userMinimumFunds);
        ~SavingAccount();
        float Deposit(float amountMoney) override;
        float Withdraw(float amountMoney) override;
        void CurrentDate() override;
        void Print() override;
    };
}