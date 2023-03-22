#pragma once
#include "bank_account/Account.h"
#include "Bank.h"

using namespace bank_account;

class AccountTransaction
{
public:

    static Account *accountTransaction;
    Date dateTransaction;
    float amountMoney;
    bool transactionIdentifierDeposit;
    bool transactionIdentifierWithdraw;

    AccountTransaction();
    AccountTransaction(Account *account, float amount);

    ~AccountTransaction();
};