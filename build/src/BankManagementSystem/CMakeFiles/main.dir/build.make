# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/syrmia/BankManagementSystem 

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/syrmia/BankManagementSystem /build

# Include any dependencies generated for this target.
include src/BankManagementSystem/CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/BankManagementSystem/CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include src/BankManagementSystem/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/BankManagementSystem/CMakeFiles/main.dir/flags.make

src/BankManagementSystem/CMakeFiles/main.dir/main.cpp.o: src/BankManagementSystem/CMakeFiles/main.dir/flags.make
src/BankManagementSystem/CMakeFiles/main.dir/main.cpp.o: ../src/BankManagementSystem/main.cpp
src/BankManagementSystem/CMakeFiles/main.dir/main.cpp.o: src/BankManagementSystem/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syrmia/BankManagementSystem /build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/BankManagementSystem/CMakeFiles/main.dir/main.cpp.o"
	cd /home/syrmia/BankManagementSystem /build/src/BankManagementSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/BankManagementSystem/CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /home/syrmia/BankManagementSystem /src/BankManagementSystem/main.cpp

src/BankManagementSystem/CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	cd /home/syrmia/BankManagementSystem /build/src/BankManagementSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syrmia/BankManagementSystem /src/BankManagementSystem/main.cpp > CMakeFiles/main.dir/main.cpp.i

src/BankManagementSystem/CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	cd /home/syrmia/BankManagementSystem /build/src/BankManagementSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syrmia/BankManagementSystem /src/BankManagementSystem/main.cpp -o CMakeFiles/main.dir/main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

../bin/main: src/BankManagementSystem/CMakeFiles/main.dir/main.cpp.o
../bin/main: src/BankManagementSystem/CMakeFiles/main.dir/build.make
../bin/main: ../lib/libCreditCardAccount.a
../bin/main: ../lib/libCurrentAccount.a
../bin/main: ../lib/libSavingsAccount.a
../bin/main: ../lib/libTrustAccount.a
../bin/main: src/BankManagementSystem/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/syrmia/BankManagementSystem /build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/main"
	cd /home/syrmia/BankManagementSystem /build/src/BankManagementSystem && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/BankManagementSystem/CMakeFiles/main.dir/build: ../bin/main
.PHONY : src/BankManagementSystem/CMakeFiles/main.dir/build

src/BankManagementSystem/CMakeFiles/main.dir/clean:
	cd /home/syrmia/BankManagementSystem /build/src/BankManagementSystem && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/BankManagementSystem/CMakeFiles/main.dir/clean

src/BankManagementSystem/CMakeFiles/main.dir/depend:
	cd /home/syrmia/BankManagementSystem /build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/syrmia/BankManagementSystem  /home/syrmia/BankManagementSystem /src/BankManagementSystem /home/syrmia/BankManagementSystem /build /home/syrmia/BankManagementSystem /build/src/BankManagementSystem /home/syrmia/BankManagementSystem /build/src/BankManagementSystem/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/BankManagementSystem/CMakeFiles/main.dir/depend

