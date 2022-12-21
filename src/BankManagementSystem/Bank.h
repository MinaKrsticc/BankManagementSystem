#pragma once
#include <iostream>
#include "my_Account/Account.h"
#include "my_Account/CurrentAccount.h"
#include "my_Account/SavingAccount.h"
#include "my_Account/CreditCardAccount.h"
#include "my_Account/TrustAccount.h"
#include <vector>
using namespace std;
using namespace my_Account;

class Bank
{
    private:
    vector<Account*> account;
    public:
        Bank();
        Bank(Account &acc);
        ~Bank();
        void OpenAccount(Account &acc);
        void CloseAccount(Account &acc);
        void Print();
};
