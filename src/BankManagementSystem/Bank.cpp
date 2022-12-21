#pragma once
#include <iostream>
#include <vector>
#include "Bank.h"
#include <iostream>
#include "my_Account/Account.h"
#include "my_Account/CurrentAccount.h"
#include "my_Account/SavingAccount.h"
#include "my_Account/CreditCardAccount.h"
#include "my_Account/TrustAccount.h"
using namespace std;
using namespace my_Account;

Bank::Bank()
{
    // Account *acc = new CurrentAccount();
    // this->account.push_back(acc);
}

Bank::~Bank()
{
    if(this->account.size() != 0)
    {
        for (int i = 0; i < this->account.size(); i++)
        {
            this->account[i] = nullptr;
        }
    }
}

Bank::Bank(Account &acc)
{
    Account *accountNew = &acc;
    this->account.push_back(accountNew);
}

void Bank::OpenAccount(Account &acc)
{
    Account *accountNew = &acc;
    this->account.push_back(accountNew);
}

void Bank::CloseAccount(Account &acc)
{
    //Account *accountNew = &acc;
    int len = this->account.size();
    int i = 0;
    while (this->account[i] != &acc && this->account[i] != nullptr)
    {
        i++;
    }
    if(this->account[i] == &acc)
    {
        Account *pomAcc = this->account[i];
        while (this->account[i + 1] != nullptr)
        {
            this->account[i] = this->account[i + 1];
            i++;
        }
        this->account.pop_back();
        pomAcc = nullptr;
        delete(pomAcc);  
    }
}

void Bank::Print()
{
    int len =  this->account.size();
    for (int i = 0; i < len; i++)
    {
        this->account[i]->Print();
    }
}
