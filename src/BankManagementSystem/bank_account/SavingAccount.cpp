#include <string>
#include <string.h>
#include "SavingAccount.h"
#include "../Bank.h"

using namespace std;

namespace bank_account
{
    int counterSavingAcc;

    SavingAccount::SavingAccount()
    {
        this->minimumFunds = 1000;
        this->adress = "";
        this->name = "";
        this->availableFunds = 0;
        this->createDateTime.days = 1;
        this->createDateTime.month = 1;
        this->createDateTime.year = 2022;
        this->interestRate = 0.03;
        this->countWithdrawals = 0;
        this->countWithdrawals++;
    }

    SavingAccount::~SavingAccount()
    {
    }

    SavingAccount::SavingAccount(Date creationDate, string userName, string userAdress, float userAmountMoney, float userMinimumFunds)
    {
        this->adress = userAdress;
        this->name = userName;
        this->interestRate = 0.03;
        this->createDateTime.days = creationDate.days;
        this->createDateTime.month = creationDate.month;
        this->createDateTime.year = creationDate.year;
        this->availableFunds = userAmountMoney;
        this->minimumFunds = userMinimumFunds;
        this->countWithdrawals = 0;
    }

    void SavingAccount::Print()
    {
        cout << this->name << endl;
        cout << this->adress << endl;
        cout << this->availableFunds << endl;
        cout << "countWithdrawals  " << this->countWithdrawals << endl;
        cout << "SavingAccount:  Kamata je  " << this->interestRate << endl;
        cout << this->createDateTime.days << ". " << this->createDateTime.month << ". " << this->createDateTime.year << endl;
        cout << "SavingAccount" << endl;
    }

    float SavingAccount::Deposit(float amountMoney)
    {
        ApdateDate();
        this->availableFunds = this->availableFunds + amountMoney + (amountMoney * this->interestRate);

        ApdateDate();

        return this->availableFunds;
    }

    float SavingAccount::Withdraw(float amountMoney)
    {
        if (this->availableFunds >= amountMoney)
        {
            float remainingFounds = this->availableFunds - amountMoney;

            if (this->minimumFunds <= this->availableFunds)
            {
                if (this->countWithdrawals <= this->maxWithdrawals)
                {
                    this->countWithdrawals++;
                    this->availableFunds = remainingFounds;

                    ApdateDate();
                }
                else
                {
                    cout << "SavingAccount:  Podigli ste vec " << this->maxWithdrawals << "puta " << endl;
                }
            }
            else
            {
                cout << "SavingAccount:  Ne mozete podici novac, zato sto imate minimalna sredstva koja moraju biti na racunu" << endl;
            }
        }
        else
        {
            cout << " SavingAccount:  Ne mozete podici sredstva, nemate dovoljno" << endl;
        }

        return this->availableFunds;
    }

    void SavingAccount::ApdateDate()
    {
        time_t ttime = time(0);
        tm *local_time = localtime(&ttime);
        this->dateTransaction.year = 1900 + local_time->tm_year;
        this->dateTransaction.month = 1 + local_time->tm_mon;
        this->dateTransaction.days = local_time->tm_mday;
    }

    bool SavingAccount::FundsAvailableOnAccount(float amound)
    {
        if (this->availableFunds >= amound)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool SavingAccount::AvailableMinusOnAccount()
    {
        return false;
    }

    bool SavingAccount::AvaibleForWithdrawOnAccount()
    {
        if (this->availableFunds > 0 && this->countWithdrawals + 1 <= this->maxWithdrawals)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}