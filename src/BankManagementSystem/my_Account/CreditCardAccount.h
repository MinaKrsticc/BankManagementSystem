#pragma once
#include <iostream>
#include "Account.h"
using namespace std;
namespace my_Account
{
    class CreditCardAccount : public Account
    {
    private:
        float allowedMinus; // dozvoljeni minus
        float limitMoney;   // ogranicenje novca koji se moze podici

    public:
        CreditCardAccount();
        CreditCardAccount(Data creationData, string nameUser, string adressUser, float amountMoney, float allowedMinus, float limitUsersMoney);
        ~CreditCardAccount();
        float Deposit(float amountMoney);
        float Withdraw(float amountMoney);
        // void Print() ;
    };
}