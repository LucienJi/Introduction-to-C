# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Lucien\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.7479.33\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Lucien\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.7479.33\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Lucien\CLionProjects\sort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Lucien\CLionProjects\sort\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sort.dir/flags.make

CMakeFiles/sort.dir/main.c.obj: CMakeFiles/sort.dir/flags.make
CMakeFiles/sort.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Lucien\CLionProjects\sort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sort.dir/main.c.obj"
	C:\min\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sort.dir\main.c.obj   -c C:\Users\Lucien\CLionProjects\sort\main.c

CMakeFiles/sort.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.dir/main.c.i"
	C:\min\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Lucien\CLionProjects\sort\main.c > CMakeFiles\sort.dir\main.c.i

CMakeFiles/sort.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.dir/main.c.s"
	C:\min\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Lucien\CLionProjects\sort\main.c -o CMakeFiles\sort.dir\main.c.s

# Object files for target sort
sort_OBJECTS = \
"CMakeFiles/sort.dir/main.c.obj"

# External object files for target sort
sort_EXTERNAL_OBJECTS =

sort.exe: CMakeFiles/sort.dir/main.c.obj
sort.exe: CMakeFiles/sort.dir/build.make
sort.exe: CMakeFiles/sort.dir/linklibs.rsp
sort.exe: CMakeFiles/sort.dir/objects1.rsp
sort.exe: CMakeFiles/sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Lucien\CLionProjects\sort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sort.dir/build: sort.exe

.PHONY : CMakeFiles/sort.dir/build

CMakeFiles/sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sort.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sort.dir/clean

CMakeFiles/sort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Lucien\CLionProjects\sort C:\Users\Lucien\CLionProjects\sort C:\Users\Lucien\CLionProjects\sort\cmake-build-debug C:\Users\Lucien\CLionProjects\sort\cmake-build-debug C:\Users\Lucien\CLionProjects\sort\cmake-build-debug\CMakeFiles\sort.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sort.dir/depend

