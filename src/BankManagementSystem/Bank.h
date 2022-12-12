#pragma once
#include <iostream>
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingAccount.h"
#include "CreditCardAccount.h"
#include "TrustAccount.h"
using namespace std;
using namespace my_Account;

class Bank
{
private:
   Account *acc;
   
public:
    Bank();
    ~Bank();
    void OpenAccount(Account acc);
    void CloseAccount(Account acc);
    void Print();
};


