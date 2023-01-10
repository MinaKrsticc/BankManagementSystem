add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)
include(CTest) # Include testing cmake package.
set(TEST_BINARY ${PROJECT_NAME}_test)
add_executable(
	${TEST_BINARY}
	current_test.cpp

)
 target_link_libraries(${TEST_BINARY}
  CurrentAccount
 )
 add_test(
	  NAME ${TEST_BINARY}
	  COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST_BINARY})
