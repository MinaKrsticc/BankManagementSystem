#include "Bank.h"
#include "bank_account/Account.h"
#include "bank_account/CurrentAccount.h"
#include "bank_account/SavingAccount.h"
#include "bank_account/CreditCardAccount.h"
#include "bank_account/TrustAccount.h"
#include <typeinfo>

using namespace std;
using namespace bank_account;

int main()
{
    string name = "Jovan";
    string address = "Bulevar";
    string nameA = "Aleksa";
    string addressA = "Slavija";
    string namec = "Natasa";
    string addressc = "Sedmi Juli";
    string namee = "Petar";
    string addressa = "Jablanicka";

    Date date;
    date.days = 2;
    date.month = 3;
    date.year = 2023;

    Date datem;
    datem.days = 14;
    datem.month = 6;
    datem.year = 2022;

    Date datei;
    datei.days = 2;
    datei.month = 8;
    datei.year = 2022;

    CurrentAccount curAcc(datem, name, address, 10000.0, 15000);
    CurrentAccount curAccount(date, namec, addressc, 10000.0, 15000);
    SavingAccount saveAcc(date, name, address, 30000.0, 10000);
    CreditCardAccount creditAcc(datei, nameA, addressA, 25000.0, 5000.0, 50000.0);
    CreditCardAccount creditA(datem, namee, addressa, 12000.0, 5000.0, 50000.0);
    TrustAccount trstAcc(date, name, address, 50000);

    Bank banka{};
    banka.OpenAccount(creditA);
    banka.OpenAccount(trstAcc);
    banka.OpenAccount(creditAcc);
    banka.OpenAccount(curAccount);
    banka.OpenAccount(curAcc);
    banka.OpenAccount(saveAcc);
    banka.PrintAccounts();

    Account &trust = trstAcc;
    Account &cur = curAcc;
    Account &credit = creditAcc;

    banka.ExecutionOfDeposits(2000, trust);
    banka.ExecutionOfDeposits(12000, cur);
    banka.ExecutionOfWithdraw(27000, credit);
    banka.ExecutionOfWithdraw(5000, saveAcc);
    banka.ExecutionOfWithdraw(6000, saveAcc);
    banka.ExecutionOfWithdraw(3000, saveAcc);

    banka.StatisticOfAccount();
    banka.PrintAccountThatHaveMoreThanAmount(5000);
    banka.PrintAccountThatHasAvailableMinus();
    banka.PrintAccountAvaibleForWithdraw();
    banka.PrintAccounts();
    banka.CloseAccount(curAcc);
    banka.PrintAccounts();
    banka.SortByAmount();
    banka.SortByDate();
    banka.SortByName();

    banka.PrintAccountsThatMadeTranslation();

    // CurrentAccount curAcca(datem, address, name, 10000.0, 15000);
    // CurrentAccount curAccounts(date, addressc, namec, 10000.0, 15000);
    // SavingAccount saveAcca(date, name, address, 30000.0, 10000);
    // TrustAccount trstAcca(date, name, address, 50000);
    // TrustAccount trstAccSec(date, name, address, 54000);

    // Account &accountTrstAccSec = trstAccSec;
    // accountTrstAccSec.Withdraw(3000);
    // accountTrstAccSec.Withdraw(3200);
    // Account &accountSaveAcca = saveAcca;
    // accountSaveAcca.Withdraw(4000);
    // accountSaveAcca.Withdraw(600);

    // Bank bank{};
    // bank.OpenAccount(curAcca);
    // bank.OpenAccount(curAccounts);
    // bank.OpenAccount(saveAcca);
    // bank.OpenAccount(trstAccSec);
    // bank.OpenAccount(trstAcca);
    // bank.Print();

    // bank.StatisticOfAccount();

    return 0;
}
