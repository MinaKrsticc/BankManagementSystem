#pragma once
#include <iostream>
#include "Account.h"

using namespace std;
namespace my_Account
{
    class SavingAccount : public Account
    {
    private:
        float interestRate;   // kamatna stopa koja se dodaje prilikom placivanja novca
        int countWithdrawals; // brojac koliko puta smo podigli novac
        float minimumFunds;   // minimalni iznos koji mora da ostane na kartici

    public:
        SavingAccount();
        SavingAccount(Data creationData, string userName, string userAdress, float userAmountMoney, float userInterestRate, float userMinimumFunds);
        ~SavingAccount();
        float Deposit(float amountMoney);
        float Withdraw(float amountMoney);
        void Print();
    };

}