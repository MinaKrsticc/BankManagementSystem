#project(Bank)
#cmake_minimum_required(VERSION 3.2)

message(STATUS "!!!!!!!!!!! $[PROJECT_SORCE_DIR]")

#include_directories (${PROJECT_SOURCE_DIR}/BankManagementSystem)

add_subdirectory (BankManagementSystem)
enable_testing ()
