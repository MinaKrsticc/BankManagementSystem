# create library " libtools "
add_library (CreditCardAccount CreditCardAccount.cpp)
add_library (CurrentAccount CurrentAccount.cpp)
add_library (SavingsAccount SavingAccount.cpp)
add_library (TrustAccount TrustAccount.cpp)
add_library (bank Bank.cpp)
#add_executable main
add_executable (main main.cpp)
# tell the linker to bind these objects together
target_link_libraries (main  Bank CreditCardAccount CurrentAccount SavingsAccount TrustAccount)

enable_testing()
