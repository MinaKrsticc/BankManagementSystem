#pragma once
#include <iostream>
#include "Bank.h"
#include "my_Account/Account.h"
#include "my_Account/CurrentAccount.h"
#include "my_Account/SavingAccount.h"
#include "my_Account/CreditCardAccount.h"
#include "my_Account/TrustAccount.h"
using namespace std;
using namespace my_Account;
int main()
{
    Data datum;
    datum.days = 2;
    datum.month = 3;
    datum.year = 2022;
    string ime = "Jovan";
    string adresa = "Bulevar";
    string imeA = "Aleksa";
    string adresaA = "Slavija";
    CurrentAccount curAcc(datum, adresa, ime, 10000.0, 15000);
    curAcc.Print();
    curAcc.Withdraw(2000);
    curAcc.Print();
    SavingAccount saveAcc(datum, ime, adresa, 30000.0, 0.02, 10000);
    saveAcc.Print();
    saveAcc.Deposit(1000);
    saveAcc.Print();
    saveAcc.Withdraw(5000);
    saveAcc.Withdraw(5000);
    saveAcc.Withdraw(5000);
    saveAcc.Withdraw(5000);
    saveAcc.Print();
    CreditCardAccount creditAcc(datum, imeA, adresaA, 25000.0, 5000.0, 50000.0);
    creditAcc.Print();
    creditAcc.Withdraw(30000);
    creditAcc.Withdraw(5000);
    creditAcc.Print();
    TrustAccount trstAcc(datum, ime, adresa, 50000);
    trstAcc.Withdraw(30000);
    trstAcc.Print();
    trstAcc.Withdraw(30000);
    trstAcc.Print();

    Bank banka{};
    banka.OpenAccount(trstAcc);
    banka.OpenAccount(curAcc);
    banka.OpenAccount(saveAcc);
    banka.Print();
    banka.CloseAccount(curAcc);
    banka.Print();
  
    return 0;
}
