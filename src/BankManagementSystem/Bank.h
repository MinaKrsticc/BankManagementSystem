#pragma once
#include <vector>
#include "bank_account/Account.h"
#include <bits/stdc++.h>

using namespace std;
using namespace bank_account;

class Bank
{
private:
    vector<Account *> accounts;

public:
    Bank();
    ~Bank();
    void OpenAccount(Account &acc);
    void CloseAccount(Account &acc);
    void Print();
    void StatisticOfAccount();
    void FundsAvailable (float amound);
    void AvailableMinus();
    void AvaibleForWithdraw();
    void SortAndPrintForAmount();
    void SortAndPrintForDate();
    void SortAndPrintForName();

};
