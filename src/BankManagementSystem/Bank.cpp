#pragma once
#include <iostream>
#include "Bank.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingAccount.h"
#include "CreditCardAccount.h"
#include "TrustAccount.h"
using namespace std;
using namespace my_Account;

Bank::Bank()
{
    CurrentAccount *currentAcc = new CurrentAccount();
}

Bank::~Bank()
{
    if(this->acc != nullptr)
    {
        delete this->acc;
        this->acc = nullptr;
    }
}