# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dmitry/Desktop/Reverse-Polish-Notation-main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitry/Desktop/Reverse-Polish-Notation-main/build

# Include any dependencies generated for this target.
include CMakeFiles/RPN.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RPN.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RPN.dir/flags.make

CMakeFiles/RPN.dir/src/lexeme.cpp.o: CMakeFiles/RPN.dir/flags.make
CMakeFiles/RPN.dir/src/lexeme.cpp.o: ../src/lexeme.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/Desktop/Reverse-Polish-Notation-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RPN.dir/src/lexeme.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RPN.dir/src/lexeme.cpp.o -c /home/dmitry/Desktop/Reverse-Polish-Notation-main/src/lexeme.cpp

CMakeFiles/RPN.dir/src/lexeme.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RPN.dir/src/lexeme.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/Desktop/Reverse-Polish-Notation-main/src/lexeme.cpp > CMakeFiles/RPN.dir/src/lexeme.cpp.i

CMakeFiles/RPN.dir/src/lexeme.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RPN.dir/src/lexeme.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/Desktop/Reverse-Polish-Notation-main/src/lexeme.cpp -o CMakeFiles/RPN.dir/src/lexeme.cpp.s

CMakeFiles/RPN.dir/src/main.cpp.o: CMakeFiles/RPN.dir/flags.make
CMakeFiles/RPN.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/Desktop/Reverse-Polish-Notation-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RPN.dir/src/main.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RPN.dir/src/main.cpp.o -c /home/dmitry/Desktop/Reverse-Polish-Notation-main/src/main.cpp

CMakeFiles/RPN.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RPN.dir/src/main.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/Desktop/Reverse-Polish-Notation-main/src/main.cpp > CMakeFiles/RPN.dir/src/main.cpp.i

CMakeFiles/RPN.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RPN.dir/src/main.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/Desktop/Reverse-Polish-Notation-main/src/main.cpp -o CMakeFiles/RPN.dir/src/main.cpp.s

CMakeFiles/RPN.dir/src/statemachine.cpp.o: CMakeFiles/RPN.dir/flags.make
CMakeFiles/RPN.dir/src/statemachine.cpp.o: ../src/statemachine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/Desktop/Reverse-Polish-Notation-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RPN.dir/src/statemachine.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RPN.dir/src/statemachine.cpp.o -c /home/dmitry/Desktop/Reverse-Polish-Notation-main/src/statemachine.cpp

CMakeFiles/RPN.dir/src/statemachine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RPN.dir/src/statemachine.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/Desktop/Reverse-Polish-Notation-main/src/statemachine.cpp > CMakeFiles/RPN.dir/src/statemachine.cpp.i

CMakeFiles/RPN.dir/src/statemachine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RPN.dir/src/statemachine.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/Desktop/Reverse-Polish-Notation-main/src/statemachine.cpp -o CMakeFiles/RPN.dir/src/statemachine.cpp.s

# Object files for target RPN
RPN_OBJECTS = \
"CMakeFiles/RPN.dir/src/lexeme.cpp.o" \
"CMakeFiles/RPN.dir/src/main.cpp.o" \
"CMakeFiles/RPN.dir/src/statemachine.cpp.o"

# External object files for target RPN
RPN_EXTERNAL_OBJECTS =

RPN: CMakeFiles/RPN.dir/src/lexeme.cpp.o
RPN: CMakeFiles/RPN.dir/src/main.cpp.o
RPN: CMakeFiles/RPN.dir/src/statemachine.cpp.o
RPN: CMakeFiles/RPN.dir/build.make
RPN: CMakeFiles/RPN.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmitry/Desktop/Reverse-Polish-Notation-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable RPN"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RPN.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RPN.dir/build: RPN

.PHONY : CMakeFiles/RPN.dir/build

CMakeFiles/RPN.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RPN.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RPN.dir/clean

CMakeFiles/RPN.dir/depend:
	cd /home/dmitry/Desktop/Reverse-Polish-Notation-main/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/Desktop/Reverse-Polish-Notation-main /home/dmitry/Desktop/Reverse-Polish-Notation-main /home/dmitry/Desktop/Reverse-Polish-Notation-main/build /home/dmitry/Desktop/Reverse-Polish-Notation-main/build /home/dmitry/Desktop/Reverse-Polish-Notation-main/build/CMakeFiles/RPN.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RPN.dir/depend

