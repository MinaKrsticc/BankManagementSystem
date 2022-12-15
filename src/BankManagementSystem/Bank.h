#pragma once
#include <iostream>
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingAccount.h"
#include "CreditCardAccount.h"
#include "TrustAccount.h"
#include <vector>
using namespace std;
using namespace my_Account;

class Bank
{
    private:
        Account *accaunt;
        //vector<vector<Account>> acc;

    public:
        Bank();
        ~Bank();
        void OpenAccount(Account &acc);
        void CloseAccount();
        void Print();
        Bank(Account &accaunt);
};
