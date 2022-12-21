#pragma once
#include <iostream>
using namespace std;
namespace my_Account
{
    struct Data
    {
        int days;
        int year;
        int month;
    };

    class Account
    {
        protected:
            string name;
            string adress;
            string type;
            float availableFunds;
            Data dataTime;

        public:
            float Deposit(float amountMoney);
            float Withdraw(float amountMoney);
            void Print();
            Account() = default;
            ~Account()
            {
                this->adress = "";
                this->name = "";
                this->availableFunds = 10000;
                this->dataTime.days = 1;
                this->dataTime.month = 1;
                this->dataTime.year = 2023;
            };
    };

}