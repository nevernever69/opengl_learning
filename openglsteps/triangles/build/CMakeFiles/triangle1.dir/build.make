# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/never/opengl/openglsteps/triangles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/never/opengl/openglsteps/triangles/build

# Include any dependencies generated for this target.
include CMakeFiles/triangle1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/triangle1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/triangle1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/triangle1.dir/flags.make

CMakeFiles/triangle1.dir/triangle1.cpp.o: CMakeFiles/triangle1.dir/flags.make
CMakeFiles/triangle1.dir/triangle1.cpp.o: /home/never/opengl/openglsteps/triangles/triangle1.cpp
CMakeFiles/triangle1.dir/triangle1.cpp.o: CMakeFiles/triangle1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/never/opengl/openglsteps/triangles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/triangle1.dir/triangle1.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/triangle1.dir/triangle1.cpp.o -MF CMakeFiles/triangle1.dir/triangle1.cpp.o.d -o CMakeFiles/triangle1.dir/triangle1.cpp.o -c /home/never/opengl/openglsteps/triangles/triangle1.cpp

CMakeFiles/triangle1.dir/triangle1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/triangle1.dir/triangle1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/never/opengl/openglsteps/triangles/triangle1.cpp > CMakeFiles/triangle1.dir/triangle1.cpp.i

CMakeFiles/triangle1.dir/triangle1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/triangle1.dir/triangle1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/never/opengl/openglsteps/triangles/triangle1.cpp -o CMakeFiles/triangle1.dir/triangle1.cpp.s

CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.o: CMakeFiles/triangle1.dir/flags.make
CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.o: /home/never/opengl/openglsteps/otherlib/src/glad.c
CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.o: CMakeFiles/triangle1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/never/opengl/openglsteps/triangles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.o -MF CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.o.d -o CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.o -c /home/never/opengl/openglsteps/otherlib/src/glad.c

CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/never/opengl/openglsteps/otherlib/src/glad.c > CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.i

CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/never/opengl/openglsteps/otherlib/src/glad.c -o CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.s

# Object files for target triangle1
triangle1_OBJECTS = \
"CMakeFiles/triangle1.dir/triangle1.cpp.o" \
"CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.o"

# External object files for target triangle1
triangle1_EXTERNAL_OBJECTS =

triangle1: CMakeFiles/triangle1.dir/triangle1.cpp.o
triangle1: CMakeFiles/triangle1.dir/home/never/opengl/openglsteps/otherlib/src/glad.c.o
triangle1: CMakeFiles/triangle1.dir/build.make
triangle1: CMakeFiles/triangle1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/never/opengl/openglsteps/triangles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable triangle1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/triangle1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/triangle1.dir/build: triangle1
.PHONY : CMakeFiles/triangle1.dir/build

CMakeFiles/triangle1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/triangle1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/triangle1.dir/clean

CMakeFiles/triangle1.dir/depend:
	cd /home/never/opengl/openglsteps/triangles/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/never/opengl/openglsteps/triangles /home/never/opengl/openglsteps/triangles /home/never/opengl/openglsteps/triangles/build /home/never/opengl/openglsteps/triangles/build /home/never/opengl/openglsteps/triangles/build/CMakeFiles/triangle1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/triangle1.dir/depend
