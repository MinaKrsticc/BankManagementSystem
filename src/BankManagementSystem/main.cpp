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
int main()
{
    // Data datum;
    // datum.days = 2;
    // datum.month = 3;
    // datum.year = 2022;
    // char * ime = "Jovan";
    // char* adresa = "Bulevar";
    CurrentAccount curAcc{};
    Bank banka(curAcc);
    curAcc.Print();
    SavingAccount cacc{};
    cacc.Deposit(300);
    cacc.Print();
    return 0;
}
