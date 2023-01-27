#pragma once
#include <vector>
#include "bank_account/Account.h"
#include "AccountTransaction.h"

using namespace std;
using namespace bank_account;

class Bank
{
private:
    vector<Account *> accounts;
    vector<AccountTransaction *> accountTransactionBank;

public:

    Bank();
    ~Bank();
    void OpenAccount(Account &accountOpen);
    void CloseAccount(Account &accountClose);
    void PrintAccounts();
    void StatisticOfAccount();
    void PrintAccountThatHaveMoreThanAmount(float amount);
    void PrintAccountThatHasAvailableMinus();
    void PrintAccountAvaibleForWithdraw();
    void SortByAmount();
    void SortByDate();
    void SortByName();

    void ExecutionOfDeposits(float amound, Account &account);
    void ExecutionOfWithdraw(float amound, Account &account);
    void PrintAccountsThatMadeTranslation();

};
