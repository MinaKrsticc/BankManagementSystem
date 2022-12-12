#pragma once
#include <iostream>
#include "Account.h"

using namespace std;
namespace my_Account
{
    class SavingAccount : Account
    {
        private:
        float interestRate; //kamatna stopa koja se dodaje prilikom placivanja novca
        int countWithdrawals; //brojac koliko puta smo podigli novac
        int minimumFunds; // minimalni iznos koji mora da ostane na kartici

    public:
        SavingAccount();
        SavingAccount(Data creationData, char* userName, char* userAdress, int userAmountMoney, float userInterestRate, int userMinimumFunds);
        ~SavingAccount();
        int Deposit(int amountMoney) override;
        int Withdraw(int amountMoney) override;
        // friend ostream& operator<< (ostream& os, const Account& info );

        void Print() const override;
    };

}