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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo

# Include any dependencies generated for this target.
include CMakeFiles/raytracer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/raytracer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/raytracer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raytracer.dir/flags.make

CMakeFiles/raytracer.dir/src/Core/Core.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/src/Core/Core.cpp.o: src/Core/Core.cpp
CMakeFiles/raytracer.dir/src/Core/Core.cpp.o: CMakeFiles/raytracer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raytracer.dir/src/Core/Core.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raytracer.dir/src/Core/Core.cpp.o -MF CMakeFiles/raytracer.dir/src/Core/Core.cpp.o.d -o CMakeFiles/raytracer.dir/src/Core/Core.cpp.o -c /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/src/Core/Core.cpp

CMakeFiles/raytracer.dir/src/Core/Core.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/src/Core/Core.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/src/Core/Core.cpp > CMakeFiles/raytracer.dir/src/Core/Core.cpp.i

CMakeFiles/raytracer.dir/src/Core/Core.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/src/Core/Core.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/src/Core/Core.cpp -o CMakeFiles/raytracer.dir/src/Core/Core.cpp.s

CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.o: src/PPM_generator/Generation.cpp
CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.o: CMakeFiles/raytracer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.o -MF CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.o.d -o CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.o -c /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/src/PPM_generator/Generation.cpp

CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/src/PPM_generator/Generation.cpp > CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.i

CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/src/PPM_generator/Generation.cpp -o CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.s

CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.o: src/Scene/Scene.cpp
CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.o: CMakeFiles/raytracer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.o -MF CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.o.d -o CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.o -c /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/src/Scene/Scene.cpp

CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/src/Scene/Scene.cpp > CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.i

CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/src/Scene/Scene.cpp -o CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.s

# Object files for target raytracer
raytracer_OBJECTS = \
"CMakeFiles/raytracer.dir/src/Core/Core.cpp.o" \
"CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.o" \
"CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.o"

# External object files for target raytracer
raytracer_EXTERNAL_OBJECTS =

raytracer: CMakeFiles/raytracer.dir/src/Core/Core.cpp.o
raytracer: CMakeFiles/raytracer.dir/src/PPM_generator/Generation.cpp.o
raytracer: CMakeFiles/raytracer.dir/src/Scene/Scene.cpp.o
raytracer: CMakeFiles/raytracer.dir/build.make
raytracer: CMakeFiles/raytracer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable raytracer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raytracer.dir/build: raytracer
.PHONY : CMakeFiles/raytracer.dir/build

CMakeFiles/raytracer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raytracer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raytracer.dir/clean

CMakeFiles/raytracer.dir/depend:
	cd /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo /home/chris/delivery/OOP/B-OOP-400-TLS-4-1-raytracer-tom.laiolo/CMakeFiles/raytracer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/raytracer.dir/depend

