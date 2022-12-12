#pragma once
#include <iostream>
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingAccount.h"
#include "CreditCardAccount.h"
#include "TrustAccount.h"
using namespace std;
using namespace my_Account;
int main()
{
    CurrentAccount cacc;
    cacc.Deposit(300);
    cacc.Print();
    return 0;
}
