# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /cygdrive/c/Users/lucia/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/lucia/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/lucia/Documents/GitHub/graph-project-losasintomaticos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/lucia/Documents/GitHub/graph-project-losasintomaticos/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/graph-project-losasintomaticos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/graph-project-losasintomaticos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graph-project-losasintomaticos.dir/flags.make

CMakeFiles/graph-project-losasintomaticos.dir/main.cpp.o: CMakeFiles/graph-project-losasintomaticos.dir/flags.make
CMakeFiles/graph-project-losasintomaticos.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/lucia/Documents/GitHub/graph-project-losasintomaticos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graph-project-losasintomaticos.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graph-project-losasintomaticos.dir/main.cpp.o -c /cygdrive/c/Users/lucia/Documents/GitHub/graph-project-losasintomaticos/main.cpp

CMakeFiles/graph-project-losasintomaticos.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph-project-losasintomaticos.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/lucia/Documents/GitHub/graph-project-losasintomaticos/main.cpp > CMakeFiles/graph-project-losasintomaticos.dir/main.cpp.i

CMakeFiles/graph-project-losasintomaticos.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph-project-losasintomaticos.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/lucia/Documents/GitHub/graph-project-losasintomaticos/main.cpp -o CMakeFiles/graph-project-losasintomaticos.dir/main.cpp.s

# Object files for target graph-project-losasintomaticos
graph__project__losasintomaticos_OBJECTS = \
"CMakeFiles/graph-project-losasintomaticos.dir/main.cpp.o"

# External object files for target graph-project-losasintomaticos
graph__project__losasintomaticos_EXTERNAL_OBJECTS =

graph-project-losasintomaticos.exe: CMakeFiles/graph-project-losasintomaticos.dir/main.cpp.o
graph-project-losasintomaticos.exe: CMakeFiles/graph-project-losasintomaticos.dir/build.make
graph-project-losasintomaticos.exe: CMakeFiles/graph-project-losasintomaticos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/lucia/Documents/GitHub/graph-project-losasintomaticos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable graph-project-losasintomaticos.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graph-project-losasintomaticos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graph-project-losasintomaticos.dir/build: graph-project-losasintomaticos.exe

.PHONY : CMakeFiles/graph-project-losasintomaticos.dir/build

CMakeFiles/graph-project-losasintomaticos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graph-project-losasintomaticos.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graph-project-losasintomaticos.dir/clean

CMakeFiles/graph-project-losasintomaticos.dir/depend:
	cd /cygdrive/c/Users/lucia/Documents/GitHub/graph-project-losasintomaticos/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/lucia/Documents/GitHub/graph-project-losasintomaticos /cygdrive/c/Users/lucia/Documents/GitHub/graph-project-losasintomaticos /cygdrive/c/Users/lucia/Documents/GitHub/graph-project-losasintomaticos/cmake-build-debug /cygdrive/c/Users/lucia/Documents/GitHub/graph-project-losasintomaticos/cmake-build-debug /cygdrive/c/Users/lucia/Documents/GitHub/graph-project-losasintomaticos/cmake-build-debug/CMakeFiles/graph-project-losasintomaticos.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graph-project-losasintomaticos.dir/depend

