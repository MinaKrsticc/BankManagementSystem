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
            CreditCardAccount(Data creationData, char* nameUser, char* adressUser, int amountMoney, int allowedMinus, int limitUsersMoney);
            ~CreditCardAccount();
            int Deposit(int amountMoney) override;
            int Withdraw(int amountMoney) override;
            friend ostream& operator<< (ostream& os, const CreditCardAccount& acc);

            void Print() const override;
     };

}