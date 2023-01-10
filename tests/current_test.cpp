#include<gtest/gtest.h>
#include "../src/BankManagementSystem/bank_account/CurrentAccount.h"
#include "../src/BankManagementSystem/bank_account/Account.h"

using namespace bank_account;

TEST(CurrentAccount, TestDeposit)
{
	Date datum;
	datum.days = 2;
	datum.month = 3;
	datum.year = 2022;
	string ime = "Jovan";
	string adresa = "Bulevar";
	CurrentAccount curAcc(datum, adresa, ime, 10000.0, 15000);
	curAcc.Deposit(2000);
	EXPECT_EQ(12000, curAcc.Deposit(2000));
}
