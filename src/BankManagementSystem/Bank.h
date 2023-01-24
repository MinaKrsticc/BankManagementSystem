#pragma once
#include <vector>
#include "bank_account/Account.h"
#include "AccountTransaction.h"
#include <bits/stdc++.h>

using namespace std;
using namespace bank_account;

class Bank
{
private:
    vector<Account *> accounts;

public:
    vector<AccountTransaction *> accountTransaction;

    Bank();
    ~Bank();
    void OpenAccount(Account &accountOpen);
    void CloseAccount(Account &accountClose);
    void Print();
    void StatisticOfAccount();
    void FundsAvailable(float amound);
    void AvailableMinus();
    void AvaibleForWithdraw();
    void SortAndPrintForAmount();
    void SortAndPrintForDate();
    void SortAndPrintForName();

    void AccountDeposit(float amound, Account &account);
    void AccountWithdraw(float amound, Account &account);
    void PrintTranslation();
};
