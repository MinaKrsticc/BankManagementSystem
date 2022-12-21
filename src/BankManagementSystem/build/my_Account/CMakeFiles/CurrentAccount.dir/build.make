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
CMAKE_SOURCE_DIR = /home/syrmia/BankManagementSystem /src/BankManagementSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/syrmia/BankManagementSystem /src/BankManagementSystem/build

# Include any dependencies generated for this target.
include my_Account/CMakeFiles/CurrentAccount.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include my_Account/CMakeFiles/CurrentAccount.dir/compiler_depend.make

# Include the progress variables for this target.
include my_Account/CMakeFiles/CurrentAccount.dir/progress.make

# Include the compile flags for this target's objects.
include my_Account/CMakeFiles/CurrentAccount.dir/flags.make

my_Account/CMakeFiles/CurrentAccount.dir/CurrentAccount.o: my_Account/CMakeFiles/CurrentAccount.dir/flags.make
my_Account/CMakeFiles/CurrentAccount.dir/CurrentAccount.o: ../my_Account/CurrentAccount.cpp
my_Account/CMakeFiles/CurrentAccount.dir/CurrentAccount.o: my_Account/CMakeFiles/CurrentAccount.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syrmia/BankManagementSystem /src/BankManagementSystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object my_Account/CMakeFiles/CurrentAccount.dir/CurrentAccount.o"
	cd /home/syrmia/BankManagementSystem /src/BankManagementSystem/build/my_Account && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT my_Account/CMakeFiles/CurrentAccount.dir/CurrentAccount.o -MF CMakeFiles/CurrentAccount.dir/CurrentAccount.o.d -o CMakeFiles/CurrentAccount.dir/CurrentAccount.o -c /home/syrmia/BankManagementSystem /src/BankManagementSystem/my_Account/CurrentAccount.cpp

my_Account/CMakeFiles/CurrentAccount.dir/CurrentAccount.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CurrentAccount.dir/CurrentAccount.i"
	cd /home/syrmia/BankManagementSystem /src/BankManagementSystem/build/my_Account && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syrmia/BankManagementSystem /src/BankManagementSystem/my_Account/CurrentAccount.cpp > CMakeFiles/CurrentAccount.dir/CurrentAccount.i

my_Account/CMakeFiles/CurrentAccount.dir/CurrentAccount.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CurrentAccount.dir/CurrentAccount.s"
	cd /home/syrmia/BankManagementSystem /src/BankManagementSystem/build/my_Account && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syrmia/BankManagementSystem /src/BankManagementSystem/my_Account/CurrentAccount.cpp -o CMakeFiles/CurrentAccount.dir/CurrentAccount.s

# Object files for target CurrentAccount
CurrentAccount_OBJECTS = \
"CMakeFiles/CurrentAccount.dir/CurrentAccount.o"

# External object files for target CurrentAccount
CurrentAccount_EXTERNAL_OBJECTS =

my_Account/libCurrentAccount.a: my_Account/CMakeFiles/CurrentAccount.dir/CurrentAccount.o
my_Account/libCurrentAccount.a: my_Account/CMakeFiles/CurrentAccount.dir/build.make
my_Account/libCurrentAccount.a: my_Account/CMakeFiles/CurrentAccount.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/syrmia/BankManagementSystem /src/BankManagementSystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libCurrentAccount.a"
	cd /home/syrmia/BankManagementSystem /src/BankManagementSystem/build/my_Account && $(CMAKE_COMMAND) -P CMakeFiles/CurrentAccount.dir/cmake_clean_target.cmake
	cd /home/syrmia/BankManagementSystem /src/BankManagementSystem/build/my_Account && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CurrentAccount.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
my_Account/CMakeFiles/CurrentAccount.dir/build: my_Account/libCurrentAccount.a
.PHONY : my_Account/CMakeFiles/CurrentAccount.dir/build

my_Account/CMakeFiles/CurrentAccount.dir/clean:
	cd /home/syrmia/BankManagementSystem /src/BankManagementSystem/build/my_Account && $(CMAKE_COMMAND) -P CMakeFiles/CurrentAccount.dir/cmake_clean.cmake
.PHONY : my_Account/CMakeFiles/CurrentAccount.dir/clean

my_Account/CMakeFiles/CurrentAccount.dir/depend:
	cd /home/syrmia/BankManagementSystem /src/BankManagementSystem/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/syrmia/BankManagementSystem /src/BankManagementSystem /home/syrmia/BankManagementSystem /src/BankManagementSystem/my_Account /home/syrmia/BankManagementSystem /src/BankManagementSystem/build /home/syrmia/BankManagementSystem /src/BankManagementSystem/build/my_Account /home/syrmia/BankManagementSystem /src/BankManagementSystem/build/my_Account/CMakeFiles/CurrentAccount.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : my_Account/CMakeFiles/CurrentAccount.dir/depend

