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
CMAKE_SOURCE_DIR = /home/jdp/custom-scripts/num-conv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jdp/custom-scripts/num-conv/build-linux

# Include any dependencies generated for this target.
include CMakeFiles/num-conv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/num-conv.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/num-conv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/num-conv.dir/flags.make

CMakeFiles/num-conv.dir/main.cpp.o: CMakeFiles/num-conv.dir/flags.make
CMakeFiles/num-conv.dir/main.cpp.o: /home/jdp/custom-scripts/num-conv/main.cpp
CMakeFiles/num-conv.dir/main.cpp.o: CMakeFiles/num-conv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jdp/custom-scripts/num-conv/build-linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/num-conv.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/num-conv.dir/main.cpp.o -MF CMakeFiles/num-conv.dir/main.cpp.o.d -o CMakeFiles/num-conv.dir/main.cpp.o -c /home/jdp/custom-scripts/num-conv/main.cpp

CMakeFiles/num-conv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/num-conv.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jdp/custom-scripts/num-conv/main.cpp > CMakeFiles/num-conv.dir/main.cpp.i

CMakeFiles/num-conv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/num-conv.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jdp/custom-scripts/num-conv/main.cpp -o CMakeFiles/num-conv.dir/main.cpp.s

CMakeFiles/num-conv.dir/src/conversion.cpp.o: CMakeFiles/num-conv.dir/flags.make
CMakeFiles/num-conv.dir/src/conversion.cpp.o: /home/jdp/custom-scripts/num-conv/src/conversion.cpp
CMakeFiles/num-conv.dir/src/conversion.cpp.o: CMakeFiles/num-conv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jdp/custom-scripts/num-conv/build-linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/num-conv.dir/src/conversion.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/num-conv.dir/src/conversion.cpp.o -MF CMakeFiles/num-conv.dir/src/conversion.cpp.o.d -o CMakeFiles/num-conv.dir/src/conversion.cpp.o -c /home/jdp/custom-scripts/num-conv/src/conversion.cpp

CMakeFiles/num-conv.dir/src/conversion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/num-conv.dir/src/conversion.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jdp/custom-scripts/num-conv/src/conversion.cpp > CMakeFiles/num-conv.dir/src/conversion.cpp.i

CMakeFiles/num-conv.dir/src/conversion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/num-conv.dir/src/conversion.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jdp/custom-scripts/num-conv/src/conversion.cpp -o CMakeFiles/num-conv.dir/src/conversion.cpp.s

# Object files for target num-conv
num__conv_OBJECTS = \
"CMakeFiles/num-conv.dir/main.cpp.o" \
"CMakeFiles/num-conv.dir/src/conversion.cpp.o"

# External object files for target num-conv
num__conv_EXTERNAL_OBJECTS =

/home/jdp/custom-scripts/num-conv/num-conv: CMakeFiles/num-conv.dir/main.cpp.o
/home/jdp/custom-scripts/num-conv/num-conv: CMakeFiles/num-conv.dir/src/conversion.cpp.o
/home/jdp/custom-scripts/num-conv/num-conv: CMakeFiles/num-conv.dir/build.make
/home/jdp/custom-scripts/num-conv/num-conv: CMakeFiles/num-conv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jdp/custom-scripts/num-conv/build-linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable /home/jdp/custom-scripts/num-conv/num-conv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/num-conv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/num-conv.dir/build: /home/jdp/custom-scripts/num-conv/num-conv
.PHONY : CMakeFiles/num-conv.dir/build

CMakeFiles/num-conv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/num-conv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/num-conv.dir/clean

CMakeFiles/num-conv.dir/depend:
	cd /home/jdp/custom-scripts/num-conv/build-linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jdp/custom-scripts/num-conv /home/jdp/custom-scripts/num-conv /home/jdp/custom-scripts/num-conv/build-linux /home/jdp/custom-scripts/num-conv/build-linux /home/jdp/custom-scripts/num-conv/build-linux/CMakeFiles/num-conv.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/num-conv.dir/depend

