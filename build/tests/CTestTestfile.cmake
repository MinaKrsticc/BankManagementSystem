# CMake generated Testfile for 
# Source directory: /home/syrmia/BankManagementSystem /tests
# Build directory: /home/syrmia/BankManagementSystem /build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(BankManagementSystem_test "/home/syrmia/BankManagementSystem /bin/BankManagementSystem_test")
set_tests_properties(BankManagementSystem_test PROPERTIES  _BACKTRACE_TRIPLES "/home/syrmia/BankManagementSystem /tests/CMakeLists.txt;13;add_test;/home/syrmia/BankManagementSystem /tests/CMakeLists.txt;0;")
subdirs("../gtest")
