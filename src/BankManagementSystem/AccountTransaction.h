#pragma once
#include <vector>
#include "bank_account/Account.h"
#include "Bank.h"
#include <bits/stdc++.h>

using namespace std;
using namespace bank_account;

class AccountTransaction
{
public:
    AccountTransaction();
    ~AccountTransaction();

    string name;
    string adress;
    float availableFunds;
    float amountMoney;
    Date apdateDateTime;

private:
};