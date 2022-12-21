include_directories(${PROJECT_SOURCE_DIR}/src/BankManagementSystem/my_Account)
add_subdirectory(my_Account)

add_library(Bank Bank.cpp)

#add_executable main
add_executable(main main.cpp)

target_link_libraries(Bank CreditCardAccount CurrentAccount SavingsAccount TrustAccount)
target_link_libraries(main my_Account CurrentAccount CreditCardAccount  SavingsAccount TrustAccount Bank )

