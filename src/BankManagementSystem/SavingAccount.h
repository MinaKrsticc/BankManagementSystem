#pragma once
#include <iostream>
#include "Account.h"

using namespace std;
namespace my_Account
{
    class SavingAccount : public Account
    {
        private:
        float interestRate; //kamatna stopa koja se dodaje prilikom placivanja novca
        int countWithdrawals; //brojac koliko puta smo podigli novac
        float minimumFunds; // minimalni iznos koji mora da ostane na kartici

    public:
        SavingAccount();
        SavingAccount(Data creationData, char* userName, char* userAdress, float userAmountMoney, float userInterestRate, float userMinimumFunds);
        ~SavingAccount();
        float Deposit(float amountMoney) override;
        float Withdraw(float amountMoney) override;
        void Print() const override;
    };

}