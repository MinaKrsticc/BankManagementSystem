#pragma once
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

    CurrentAccount curAcc(datumm, adresa, ime, 10000.0, 15000);
    CurrentAccount curAccount(datum, adresac, imec, 10000.0, 15000);
    SavingAccount saveAcc(datum, ime, adresa, 30000.0, 10000);
    CreditCardAccount creditAcc(datumi, imeA, adresaA, 25000.0, 5000.0, 50000.0);
    CreditCardAccount creditA(datumm, imee, adresaa, 12000.0, 5000.0, 50000.0);
    TrustAccount trstAcc(datum, ime, adresa, 50000);

    Account &cur = curAcc;
    cur.Deposit(2000);
    cur.Withdraw(1500);
    Account &credit = creditAcc;
    credit.Withdraw(10000);
    credit.Withdraw(50000);
    credit.Withdraw(5000);
    credit.Withdraw(5000);
    credit.Withdraw(7000);
    Account &saveing = saveAcc;
    saveing.Deposit(1000);
    saveing.Withdraw(5000);
    saveing.Withdraw(5000);
    saveing.Withdraw(5000);
    saveing.Withdraw(5000);
    Account &trust = trstAcc;
    trust.Withdraw(30000);
    trust.Withdraw(30000);
    Account &creditacc= creditA;
    creditacc.Withdraw(13000);

    Bank banka{};
    banka.OpenAccount(creditA);
    banka.OpenAccount(trstAcc);
    banka.OpenAccount(creditAcc);
    banka.OpenAccount(curAccount);
    banka.OpenAccount(curAcc);
    banka.OpenAccount(saveAcc);
    // banka.Print();
    banka.StatisticOfAccount();
    banka.FundsAvailable(5000);
    banka.AvailableMinus();
    banka.AvaibleForWithdraw();
    banka.CloseAccount(curAcc);
    banka.Print();
    banka.SortAndPrintForAmount();
    banka.SortAndPrintForDate();
    banka.SortAndPrintForName();

    CurrentAccount curAcca(datumm, adresa, ime, 10000.0, 15000);
    CurrentAccount curAccounts(datum, adresac, imec, 10000.0, 15000);
    SavingAccount saveAcca(datum, ime, adresa, 30000.0, 10000);
    CreditCardAccount creditAcca(datumi, imeA, adresaA, 25000.0, 5000.0, 50000.0);
    CreditCardAccount creditAc(datumm, imee, adresaa, 12000.0, 5000.0, 50000.0);
    TrustAccount trstAcca(datum, ime, adresa, 50000);

    Bank bank{};
    bank.OpenAccount(curAcca);
    bank.OpenAccount(curAccounts);
    bank.OpenAccount(saveAcca);
    bank.StatisticOfAccount();

    return 0;
}
