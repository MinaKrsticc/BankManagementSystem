#pragma once
#include <iostream>
#include "Account.h"
using namespace std;
namespace my_Account
{
    class CreditCardAccount : public Account
    {  
        private:
        int allowedMinus; //dozvoljeni minus
        int limitMoney; // ogranicenje novca koji se moze podici

        public:
            CreditCardAccount();
            CreditCardAccount(Data creationData, char* nameUser, char* adressUser, float amountMoney, int allowedMinus, int limitUsersMoney);
            ~CreditCardAccount();
            float Deposit(float amountMoney) override;
            float Withdraw(float amountMoney) override;
            void Print() const override;
     };

}