# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\JetBrains\CLion2023.3\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = D:\JetBrains\CLion2023.3\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\anton\Documents\GitHub\ItC-BP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\anton\Documents\GitHub\ItC-BP\cmake-build-debug-mingw

# Include any dependencies generated for this target.
include CMakeFiles/lab2.secondExample.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab2.secondExample.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab2.secondExample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab2.secondExample.dir/flags.make

CMakeFiles/lab2.secondExample.dir/lab_num2/SecondExample.cpp.obj: CMakeFiles/lab2.secondExample.dir/flags.make
CMakeFiles/lab2.secondExample.dir/lab_num2/SecondExample.cpp.obj: C:/Users/anton/Documents/GitHub/ItC-BP/lab_num2/SecondExample.cpp
CMakeFiles/lab2.secondExample.dir/lab_num2/SecondExample.cpp.obj: CMakeFiles/lab2.secondExample.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\anton\Documents\GitHub\ItC-BP\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab2.secondExample.dir/lab_num2/SecondExample.cpp.obj"
	D:\JetBrains\CLion2023.3\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab2.secondExample.dir/lab_num2/SecondExample.cpp.obj -MF CMakeFiles\lab2.secondExample.dir\lab_num2\SecondExample.cpp.obj.d -o CMakeFiles\lab2.secondExample.dir\lab_num2\SecondExample.cpp.obj -c C:\Users\anton\Documents\GitHub\ItC-BP\lab_num2\SecondExample.cpp

CMakeFiles/lab2.secondExample.dir/lab_num2/SecondExample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab2.secondExample.dir/lab_num2/SecondExample.cpp.i"
	D:\JetBrains\CLion2023.3\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\anton\Documents\GitHub\ItC-BP\lab_num2\SecondExample.cpp > CMakeFiles\lab2.secondExample.dir\lab_num2\SecondExample.cpp.i

CMakeFiles/lab2.secondExample.dir/lab_num2/SecondExample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab2.secondExample.dir/lab_num2/SecondExample.cpp.s"
	D:\JetBrains\CLion2023.3\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\anton\Documents\GitHub\ItC-BP\lab_num2\SecondExample.cpp -o CMakeFiles\lab2.secondExample.dir\lab_num2\SecondExample.cpp.s

# Object files for target lab2.secondExample
lab2_secondExample_OBJECTS = \
"CMakeFiles/lab2.secondExample.dir/lab_num2/SecondExample.cpp.obj"

# External object files for target lab2.secondExample
lab2_secondExample_EXTERNAL_OBJECTS =

lab2.secondExample.exe: CMakeFiles/lab2.secondExample.dir/lab_num2/SecondExample.cpp.obj
lab2.secondExample.exe: CMakeFiles/lab2.secondExample.dir/build.make
lab2.secondExample.exe: CMakeFiles/lab2.secondExample.dir/linkLibs.rsp
lab2.secondExample.exe: CMakeFiles/lab2.secondExample.dir/objects1.rsp
lab2.secondExample.exe: CMakeFiles/lab2.secondExample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\anton\Documents\GitHub\ItC-BP\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab2.secondExample.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab2.secondExample.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab2.secondExample.dir/build: lab2.secondExample.exe
.PHONY : CMakeFiles/lab2.secondExample.dir/build

CMakeFiles/lab2.secondExample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab2.secondExample.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab2.secondExample.dir/clean

CMakeFiles/lab2.secondExample.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\anton\Documents\GitHub\ItC-BP C:\Users\anton\Documents\GitHub\ItC-BP C:\Users\anton\Documents\GitHub\ItC-BP\cmake-build-debug-mingw C:\Users\anton\Documents\GitHub\ItC-BP\cmake-build-debug-mingw C:\Users\anton\Documents\GitHub\ItC-BP\cmake-build-debug-mingw\CMakeFiles\lab2.secondExample.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab2.secondExample.dir/depend

