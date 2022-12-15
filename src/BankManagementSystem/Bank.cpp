#include <iostream>
#include <vector>
#include "Bank.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingAccount.h"
#include "CreditCardAccount.h"
#include "TrustAccount.h"
using namespace std;
using namespace my_Account;

Bank::Bank()
{
    Account *acc = new CurrentAccount();
    this->accaunt = acc;
}

Bank::Bank(Account &accaunt)
{
    this->accaunt = &accaunt;
}

Bank::~Bank()
{
    if(this->accaunt != nullptr)
    {
        delete this->accaunt;
        this->accaunt = nullptr;
    }
}

void Bank::OpenAccount(Account &acc)
{
    this->accaunt = &acc;
}

void Bank::CloseAccount()
{
    this->accaunt = nullptr;
}
