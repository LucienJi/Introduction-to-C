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
CMAKE_SOURCE_DIR = C:\Users\Lucien\CLionProjects\linkedlist

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Lucien\CLionProjects\linkedlist\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/linkedlist.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linkedlist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linkedlist.dir/flags.make

CMakeFiles/linkedlist.dir/main.c.obj: CMakeFiles/linkedlist.dir/flags.make
CMakeFiles/linkedlist.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Lucien\CLionProjects\linkedlist\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/linkedlist.dir/main.c.obj"
	C:\min\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\linkedlist.dir\main.c.obj   -c C:\Users\Lucien\CLionProjects\linkedlist\main.c

CMakeFiles/linkedlist.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linkedlist.dir/main.c.i"
	C:\min\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Lucien\CLionProjects\linkedlist\main.c > CMakeFiles\linkedlist.dir\main.c.i

CMakeFiles/linkedlist.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linkedlist.dir/main.c.s"
	C:\min\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Lucien\CLionProjects\linkedlist\main.c -o CMakeFiles\linkedlist.dir\main.c.s

CMakeFiles/linkedlist.dir/Linked_List_function.c.obj: CMakeFiles/linkedlist.dir/flags.make
CMakeFiles/linkedlist.dir/Linked_List_function.c.obj: ../Linked_List_function.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Lucien\CLionProjects\linkedlist\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/linkedlist.dir/Linked_List_function.c.obj"
	C:\min\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\linkedlist.dir\Linked_List_function.c.obj   -c C:\Users\Lucien\CLionProjects\linkedlist\Linked_List_function.c

CMakeFiles/linkedlist.dir/Linked_List_function.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linkedlist.dir/Linked_List_function.c.i"
	C:\min\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Lucien\CLionProjects\linkedlist\Linked_List_function.c > CMakeFiles\linkedlist.dir\Linked_List_function.c.i

CMakeFiles/linkedlist.dir/Linked_List_function.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linkedlist.dir/Linked_List_function.c.s"
	C:\min\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Lucien\CLionProjects\linkedlist\Linked_List_function.c -o CMakeFiles\linkedlist.dir\Linked_List_function.c.s

# Object files for target linkedlist
linkedlist_OBJECTS = \
"CMakeFiles/linkedlist.dir/main.c.obj" \
"CMakeFiles/linkedlist.dir/Linked_List_function.c.obj"

# External object files for target linkedlist
linkedlist_EXTERNAL_OBJECTS =

linkedlist.exe: CMakeFiles/linkedlist.dir/main.c.obj
linkedlist.exe: CMakeFiles/linkedlist.dir/Linked_List_function.c.obj
linkedlist.exe: CMakeFiles/linkedlist.dir/build.make
linkedlist.exe: CMakeFiles/linkedlist.dir/linklibs.rsp
linkedlist.exe: CMakeFiles/linkedlist.dir/objects1.rsp
linkedlist.exe: CMakeFiles/linkedlist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Lucien\CLionProjects\linkedlist\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable linkedlist.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\linkedlist.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linkedlist.dir/build: linkedlist.exe

.PHONY : CMakeFiles/linkedlist.dir/build

CMakeFiles/linkedlist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\linkedlist.dir\cmake_clean.cmake
.PHONY : CMakeFiles/linkedlist.dir/clean

CMakeFiles/linkedlist.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Lucien\CLionProjects\linkedlist C:\Users\Lucien\CLionProjects\linkedlist C:\Users\Lucien\CLionProjects\linkedlist\cmake-build-debug C:\Users\Lucien\CLionProjects\linkedlist\cmake-build-debug C:\Users\Lucien\CLionProjects\linkedlist\cmake-build-debug\CMakeFiles\linkedlist.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linkedlist.dir/depend

