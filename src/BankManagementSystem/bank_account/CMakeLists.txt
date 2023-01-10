#dodaje se interface zato sto ima samo Accaunt.h tj imamo virtual klasu(roditeljsku)
add_library(bank_account INTERFACE)
target_link_directories(bank_account INTERFACE .)

# create library " libtools "
add_library(CreditCardAccount CreditCardAccount.cpp)
add_library(CurrentAccount CurrentAccount.cpp)
add_library(SavingsAccount SavingAccount.cpp)
add_library(TrustAccount TrustAccount.cpp)

target_link_libraries(CreditCardAccount bank_account)
target_link_libraries(CurrentAccount bank_account)
target_link_libraries(SavingsAccount bank_account)
target_link_libraries(TrustAccount bank_account)
