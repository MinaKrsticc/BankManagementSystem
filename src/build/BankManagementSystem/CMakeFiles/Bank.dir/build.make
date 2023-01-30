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
CMAKE_SOURCE_DIR = /home/syrmia/BankManagementSystem /src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/syrmia/BankManagementSystem /src/build

# Include any dependencies generated for this target.
include BankManagementSystem/CMakeFiles/Bank.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include BankManagementSystem/CMakeFiles/Bank.dir/compiler_depend.make

# Include the progress variables for this target.
include BankManagementSystem/CMakeFiles/Bank.dir/progress.make

# Include the compile flags for this target's objects.
include BankManagementSystem/CMakeFiles/Bank.dir/flags.make

BankManagementSystem/CMakeFiles/Bank.dir/Bank.o: BankManagementSystem/CMakeFiles/Bank.dir/flags.make
BankManagementSystem/CMakeFiles/Bank.dir/Bank.o: ../BankManagementSystem/Bank.cpp
BankManagementSystem/CMakeFiles/Bank.dir/Bank.o: BankManagementSystem/CMakeFiles/Bank.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syrmia/BankManagementSystem /src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object BankManagementSystem/CMakeFiles/Bank.dir/Bank.o"
	cd /home/syrmia/BankManagementSystem /src/build/BankManagementSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT BankManagementSystem/CMakeFiles/Bank.dir/Bank.o -MF CMakeFiles/Bank.dir/Bank.o.d -o CMakeFiles/Bank.dir/Bank.o -c /home/syrmia/BankManagementSystem /src/BankManagementSystem/Bank.cpp

BankManagementSystem/CMakeFiles/Bank.dir/Bank.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bank.dir/Bank.i"
	cd /home/syrmia/BankManagementSystem /src/build/BankManagementSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syrmia/BankManagementSystem /src/BankManagementSystem/Bank.cpp > CMakeFiles/Bank.dir/Bank.i

BankManagementSystem/CMakeFiles/Bank.dir/Bank.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bank.dir/Bank.s"
	cd /home/syrmia/BankManagementSystem /src/build/BankManagementSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syrmia/BankManagementSystem /src/BankManagementSystem/Bank.cpp -o CMakeFiles/Bank.dir/Bank.s

# Object files for target Bank
Bank_OBJECTS = \
"CMakeFiles/Bank.dir/Bank.o"

# External object files for target Bank
Bank_EXTERNAL_OBJECTS =

BankManagementSystem/libBank.a: BankManagementSystem/CMakeFiles/Bank.dir/Bank.o
BankManagementSystem/libBank.a: BankManagementSystem/CMakeFiles/Bank.dir/build.make
BankManagementSystem/libBank.a: BankManagementSystem/CMakeFiles/Bank.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/syrmia/BankManagementSystem /src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libBank.a"
	cd /home/syrmia/BankManagementSystem /src/build/BankManagementSystem && $(CMAKE_COMMAND) -P CMakeFiles/Bank.dir/cmake_clean_target.cmake
	cd /home/syrmia/BankManagementSystem /src/build/BankManagementSystem && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bank.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
BankManagementSystem/CMakeFiles/Bank.dir/build: BankManagementSystem/libBank.a
.PHONY : BankManagementSystem/CMakeFiles/Bank.dir/build

BankManagementSystem/CMakeFiles/Bank.dir/clean:
	cd /home/syrmia/BankManagementSystem /src/build/BankManagementSystem && $(CMAKE_COMMAND) -P CMakeFiles/Bank.dir/cmake_clean.cmake
.PHONY : BankManagementSystem/CMakeFiles/Bank.dir/clean

BankManagementSystem/CMakeFiles/Bank.dir/depend:
	cd /home/syrmia/BankManagementSystem /src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/syrmia/BankManagementSystem /src /home/syrmia/BankManagementSystem /src/BankManagementSystem /home/syrmia/BankManagementSystem /src/build /home/syrmia/BankManagementSystem /src/build/BankManagementSystem /home/syrmia/BankManagementSystem /src/build/BankManagementSystem/CMakeFiles/Bank.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : BankManagementSystem/CMakeFiles/Bank.dir/depend
