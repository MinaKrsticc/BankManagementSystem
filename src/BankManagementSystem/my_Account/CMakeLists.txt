#dodaje se interface zato sto ima samo Accaunt.h tj imamo virtual klasu(roditeljsku)
add_library(my_Account INTERFACE)
target_link_directories(my_Account INTERFACE .)

# create library " libtools "
add_library(CreditCardAccount CreditCardAccount.cpp)
add_library(CurrentAccount CurrentAccount.cpp)
add_library(SavingsAccount SavingAccount.cpp)
add_library(TrustAccount TrustAccount.cpp)

target_link_libraries(CreditCardAccount my_Account)
target_link_libraries(CurrentAccount my_Account)
target_link_libraries(SavingsAccount my_Account)
target_link_libraries(TrustAccount my_Account)
