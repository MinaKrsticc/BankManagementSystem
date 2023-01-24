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
    string ime = "Jovan";
    string adresa = "Bulevar";
    string imeA = "Aleksa";
    string adresaA = "Slavija";
    string imec = "Natasa";
    string adresac = "Sedmi Juli";
    string imee = "Petar";
    string adresaa = "Jablanicka";

    Date datum;
    datum.days = 2;
    datum.month = 3;
    datum.year = 2023;

    Date datumm;
    datumm.days = 14;
    datumm.month = 6;
    datumm.year = 2022;

    Date datumi;
    datumi.days = 2;
    datumi.month = 8;
    datumi.year = 2022;

    CurrentAccount curAcc(datumm, ime, adresa, 10000.0, 15000);
    CurrentAccount curAccount(datum, imec, adresac, 10000.0, 15000);
    SavingAccount saveAcc(datum, ime, adresa, 30000.0, 10000);
    CreditCardAccount creditAcc(datumi, imeA, adresaA, 25000.0, 5000.0, 50000.0);
    CreditCardAccount creditA(datumm, imee, adresaa, 12000.0, 5000.0, 50000.0);
    TrustAccount trstAcc(datum, ime, adresa, 50000);

    Bank banka{};
    banka.OpenAccount(creditA);
    banka.OpenAccount(trstAcc);
    banka.OpenAccount(creditAcc);
    banka.OpenAccount(curAccount);
    banka.OpenAccount(curAcc);
    banka.OpenAccount(saveAcc);

    Account &trust = trstAcc;
    Account &cur = curAcc;
    Account &credit = creditAcc;

    banka.AccountDeposit(2000, trust);
    banka.AccountDeposit(12000, cur);
    banka.AccountWithdraw(27000, creditAcc);
    banka.AccountWithdraw(5000, saveAcc);
    banka.AccountWithdraw(6000, saveAcc);
    banka.AccountWithdraw(3000, saveAcc);

    banka.StatisticOfAccount();
    banka.FundsAvailable(5000);
    banka.AvailableMinus();
    banka.AvaibleForWithdraw();
    banka.CloseAccount(curAcc);
    banka.SortAndPrintForAmount();
    banka.SortAndPrintForDate();
    banka.SortAndPrintForName();
 
    banka.PrintTranslation();

    // CurrentAccount curAcca(datumm, adresa, ime, 10000.0, 15000);
    // CurrentAccount curAccounts(datum, adresac, imec, 10000.0, 15000);
    // SavingAccount saveAcca(datum, ime, adresa, 30000.0, 10000);
    // TrustAccount trstAcca(datum, ime, adresa, 50000);
    // TrustAccount trstAccSec(datum, ime, adresa, 54000);

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
