#pragma once
#include <vector>
#include "bank_account/Account.h"
#include "Bank.h"
#include <bits/stdc++.h>

using namespace std;
using namespace bank_account;

class AccountTranslation
{
public:
    AccountTranslation();
    ~AccountTranslation();

        string name;
        string adress;
        float availableFunds;
        float amountMoney;
        Date apdateDateTime;

private:

};