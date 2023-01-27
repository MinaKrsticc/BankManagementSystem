#include "Bank.h"
#include "bank_account/Account.h"
#include "bank_account/CurrentAccount.h"
#include "bank_account/SavingAccount.h"
#include "bank_account/CreditCardAccount.h"
#include "bank_account/TrustAccount.h"

using namespace bank_account;

AccountTransaction::AccountTransaction(Account* account, float amount)
{
    this->accountTransaction = account;
    this->dateTransaction.TimeTransaction();
    this->amountMoney = amount;
    this->transactionIdentifierDeposit = false;
    this->transactionIdentifierWithdraw = false;
}

AccountTransaction::AccountTransaction()
{

}
AccountTransaction::~AccountTransaction()
{

}