# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "/home/i505710/Downloads/Untitled Folder/clion-2018.3.3/bin/cmake/linux/bin/cmake"

# The command to remove a file.
RM = "/home/i505710/Downloads/Untitled Folder/clion-2018.3.3/bin/cmake/linux/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/i505710/CLionProjects/lcs-openmp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/i505710/CLionProjects/lcs-openmp/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/lcs_openmp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lcs_openmp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lcs_openmp.dir/flags.make

CMakeFiles/lcs_openmp.dir/src/main.cpp.o: CMakeFiles/lcs_openmp.dir/flags.make
CMakeFiles/lcs_openmp.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/i505710/CLionProjects/lcs-openmp/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lcs_openmp.dir/src/main.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lcs_openmp.dir/src/main.cpp.o -c /home/i505710/CLionProjects/lcs-openmp/src/main.cpp

CMakeFiles/lcs_openmp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lcs_openmp.dir/src/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/i505710/CLionProjects/lcs-openmp/src/main.cpp > CMakeFiles/lcs_openmp.dir/src/main.cpp.i

CMakeFiles/lcs_openmp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lcs_openmp.dir/src/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/i505710/CLionProjects/lcs-openmp/src/main.cpp -o CMakeFiles/lcs_openmp.dir/src/main.cpp.s

CMakeFiles/lcs_openmp.dir/src/solver.cpp.o: CMakeFiles/lcs_openmp.dir/flags.make
CMakeFiles/lcs_openmp.dir/src/solver.cpp.o: ../src/solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/i505710/CLionProjects/lcs-openmp/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lcs_openmp.dir/src/solver.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lcs_openmp.dir/src/solver.cpp.o -c /home/i505710/CLionProjects/lcs-openmp/src/solver.cpp

CMakeFiles/lcs_openmp.dir/src/solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lcs_openmp.dir/src/solver.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/i505710/CLionProjects/lcs-openmp/src/solver.cpp > CMakeFiles/lcs_openmp.dir/src/solver.cpp.i

CMakeFiles/lcs_openmp.dir/src/solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lcs_openmp.dir/src/solver.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/i505710/CLionProjects/lcs-openmp/src/solver.cpp -o CMakeFiles/lcs_openmp.dir/src/solver.cpp.s

# Object files for target lcs_openmp
lcs_openmp_OBJECTS = \
"CMakeFiles/lcs_openmp.dir/src/main.cpp.o" \
"CMakeFiles/lcs_openmp.dir/src/solver.cpp.o"

# External object files for target lcs_openmp
lcs_openmp_EXTERNAL_OBJECTS =

lcs_openmp: CMakeFiles/lcs_openmp.dir/src/main.cpp.o
lcs_openmp: CMakeFiles/lcs_openmp.dir/src/solver.cpp.o
lcs_openmp: CMakeFiles/lcs_openmp.dir/build.make
lcs_openmp: CMakeFiles/lcs_openmp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/i505710/CLionProjects/lcs-openmp/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lcs_openmp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lcs_openmp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lcs_openmp.dir/build: lcs_openmp

.PHONY : CMakeFiles/lcs_openmp.dir/build

CMakeFiles/lcs_openmp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lcs_openmp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lcs_openmp.dir/clean

CMakeFiles/lcs_openmp.dir/depend:
	cd /home/i505710/CLionProjects/lcs-openmp/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/i505710/CLionProjects/lcs-openmp /home/i505710/CLionProjects/lcs-openmp /home/i505710/CLionProjects/lcs-openmp/cmake-build-release /home/i505710/CLionProjects/lcs-openmp/cmake-build-release /home/i505710/CLionProjects/lcs-openmp/cmake-build-release/CMakeFiles/lcs_openmp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lcs_openmp.dir/depend

