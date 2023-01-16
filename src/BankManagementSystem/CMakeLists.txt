include_directories(${PROJECT_SOURCE_DIR}/src/BankManagementSystem/bank_account)
add_subdirectory(bank_account)

add_library(Bank Bank.cpp)
#add_library(History History.cpp)

#add_executable main
add_executable(main main.cpp)

#target_link_libraries(History Bank CreditCardAccount CurrentAccount SavingsAccount TrustAccount)
target_link_libraries(Bank CreditCardAccount CurrentAccount SavingsAccount TrustAccount)
target_link_libraries(main bank_account CurrentAccount CreditCardAccount  SavingsAccount TrustAccount Bank)
