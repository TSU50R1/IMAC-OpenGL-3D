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
CMAKE_COMMAND = /snap/clion/137/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/137/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/laurine/Documents/IMAC2/OpenGL/Opengl_Projet_Capdeville_ChamotRooke_Rostoker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/laurine/Documents/IMAC2/OpenGL/Opengl_Projet_Capdeville_ChamotRooke_Rostoker/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Imacity.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Imacity.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Imacity.dir/flags.make

CMakeFiles/Imacity.dir/src/main.cpp.o: CMakeFiles/Imacity.dir/flags.make
CMakeFiles/Imacity.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laurine/Documents/IMAC2/OpenGL/Opengl_Projet_Capdeville_ChamotRooke_Rostoker/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Imacity.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Imacity.dir/src/main.cpp.o -c /home/laurine/Documents/IMAC2/OpenGL/Opengl_Projet_Capdeville_ChamotRooke_Rostoker/src/main.cpp

CMakeFiles/Imacity.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Imacity.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laurine/Documents/IMAC2/OpenGL/Opengl_Projet_Capdeville_ChamotRooke_Rostoker/src/main.cpp > CMakeFiles/Imacity.dir/src/main.cpp.i

CMakeFiles/Imacity.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Imacity.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laurine/Documents/IMAC2/OpenGL/Opengl_Projet_Capdeville_ChamotRooke_Rostoker/src/main.cpp -o CMakeFiles/Imacity.dir/src/main.cpp.s

# Object files for target Imacity
Imacity_OBJECTS = \
"CMakeFiles/Imacity.dir/src/main.cpp.o"

# External object files for target Imacity
Imacity_EXTERNAL_OBJECTS =

bin/Imacity: CMakeFiles/Imacity.dir/src/main.cpp.o
bin/Imacity: CMakeFiles/Imacity.dir/build.make
bin/Imacity: lib/glimac/libglimac.a
bin/Imacity: /usr/lib/x86_64-linux-gnu/libSDLmain.a
bin/Imacity: /usr/lib/x86_64-linux-gnu/libSDL.so
bin/Imacity: /usr/lib/x86_64-linux-gnu/libGL.so
bin/Imacity: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/Imacity: /usr/lib/x86_64-linux-gnu/libGLEW.so
bin/Imacity: CMakeFiles/Imacity.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/laurine/Documents/IMAC2/OpenGL/Opengl_Projet_Capdeville_ChamotRooke_Rostoker/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/Imacity"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Imacity.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Imacity.dir/build: bin/Imacity

.PHONY : CMakeFiles/Imacity.dir/build

CMakeFiles/Imacity.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Imacity.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Imacity.dir/clean

CMakeFiles/Imacity.dir/depend:
	cd /home/laurine/Documents/IMAC2/OpenGL/Opengl_Projet_Capdeville_ChamotRooke_Rostoker/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/laurine/Documents/IMAC2/OpenGL/Opengl_Projet_Capdeville_ChamotRooke_Rostoker /home/laurine/Documents/IMAC2/OpenGL/Opengl_Projet_Capdeville_ChamotRooke_Rostoker /home/laurine/Documents/IMAC2/OpenGL/Opengl_Projet_Capdeville_ChamotRooke_Rostoker/cmake-build-debug /home/laurine/Documents/IMAC2/OpenGL/Opengl_Projet_Capdeville_ChamotRooke_Rostoker/cmake-build-debug /home/laurine/Documents/IMAC2/OpenGL/Opengl_Projet_Capdeville_ChamotRooke_Rostoker/cmake-build-debug/CMakeFiles/Imacity.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Imacity.dir/depend

