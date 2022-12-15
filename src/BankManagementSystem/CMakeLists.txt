include_directories(${PROJECT_SOURCE_DIR}/src/BankManagementSystem)

#dodaje se interface zato sto ima samo Accaunt.h tj imamo virtual klasu(roditeljsku)
add_library (accaunt INTERFACE)
target_link_directories (accaunt INTERFACE .)

# create library " libtools "
add_library (CreditCardAccount CreditCardAccount.cpp)
add_library (CurrentAccount CurrentAccount.cpp)
add_library (SavingsAccount SavingAccount.cpp)
add_library (TrustAccount TrustAccount.cpp)
add_library (Bank Bank.cpp)

find_library (SOME_LIB
 NAMES libio_tools.so
 PATHS "/home/BankManagementSystem/lib")

#add_executable main
add_executable (main main.cpp)

target_link_libraries (CreditCardAccount accaunt)
target_link_libraries (CurrentAccount accaunt)
target_link_libraries (SavingsAccount accaunt)
target_link_libraries (TrustAccount accaunt)
#target_link_libraries (Bank accaunt)

target_link_libraries (Bank CreditCardAccount CurrentAccount SavingsAccount TrustAccount)
target_link_libraries (main Bank CreditCardAccount CurrentAccount SavingsAccount TrustAccount)

enable_testing()
