# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "/Users/houor/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/181.5281.33/CLion.app/Contents/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/Users/houor/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/181.5281.33/CLion.app/Contents/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/adjacency_matrix_graph.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/adjacency_matrix_graph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/adjacency_matrix_graph.dir/flags.make

CMakeFiles/adjacency_matrix_graph.dir/main.c.o: CMakeFiles/adjacency_matrix_graph.dir/flags.make
CMakeFiles/adjacency_matrix_graph.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/adjacency_matrix_graph.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/adjacency_matrix_graph.dir/main.c.o   -c /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/main.c

CMakeFiles/adjacency_matrix_graph.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/adjacency_matrix_graph.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/main.c > CMakeFiles/adjacency_matrix_graph.dir/main.c.i

CMakeFiles/adjacency_matrix_graph.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/adjacency_matrix_graph.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/main.c -o CMakeFiles/adjacency_matrix_graph.dir/main.c.s

CMakeFiles/adjacency_matrix_graph.dir/main.c.o.requires:

.PHONY : CMakeFiles/adjacency_matrix_graph.dir/main.c.o.requires

CMakeFiles/adjacency_matrix_graph.dir/main.c.o.provides: CMakeFiles/adjacency_matrix_graph.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/adjacency_matrix_graph.dir/build.make CMakeFiles/adjacency_matrix_graph.dir/main.c.o.provides.build
.PHONY : CMakeFiles/adjacency_matrix_graph.dir/main.c.o.provides

CMakeFiles/adjacency_matrix_graph.dir/main.c.o.provides.build: CMakeFiles/adjacency_matrix_graph.dir/main.c.o


CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o: CMakeFiles/adjacency_matrix_graph.dir/flags.make
CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o: ../adjacencymatrixgraph.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o   -c /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/adjacencymatrixgraph.c

CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/adjacencymatrixgraph.c > CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.i

CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/adjacencymatrixgraph.c -o CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.s

CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o.requires:

.PHONY : CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o.requires

CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o.provides: CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o.requires
	$(MAKE) -f CMakeFiles/adjacency_matrix_graph.dir/build.make CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o.provides.build
.PHONY : CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o.provides

CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o.provides.build: CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o


CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o: CMakeFiles/adjacency_matrix_graph.dir/flags.make
CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o: /Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o   -c /Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c

CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c > CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.i

CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c -o CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.s

CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o.requires:

.PHONY : CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o.requires

CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o.provides: CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o.requires
	$(MAKE) -f CMakeFiles/adjacency_matrix_graph.dir/build.make CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o.provides.build
.PHONY : CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o.provides

CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o.provides.build: CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o


# Object files for target adjacency_matrix_graph
adjacency_matrix_graph_OBJECTS = \
"CMakeFiles/adjacency_matrix_graph.dir/main.c.o" \
"CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o" \
"CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o"

# External object files for target adjacency_matrix_graph
adjacency_matrix_graph_EXTERNAL_OBJECTS =

adjacency_matrix_graph: CMakeFiles/adjacency_matrix_graph.dir/main.c.o
adjacency_matrix_graph: CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o
adjacency_matrix_graph: CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o
adjacency_matrix_graph: CMakeFiles/adjacency_matrix_graph.dir/build.make
adjacency_matrix_graph: CMakeFiles/adjacency_matrix_graph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable adjacency_matrix_graph"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/adjacency_matrix_graph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/adjacency_matrix_graph.dir/build: adjacency_matrix_graph

.PHONY : CMakeFiles/adjacency_matrix_graph.dir/build

CMakeFiles/adjacency_matrix_graph.dir/requires: CMakeFiles/adjacency_matrix_graph.dir/main.c.o.requires
CMakeFiles/adjacency_matrix_graph.dir/requires: CMakeFiles/adjacency_matrix_graph.dir/adjacencymatrixgraph.c.o.requires
CMakeFiles/adjacency_matrix_graph.dir/requires: CMakeFiles/adjacency_matrix_graph.dir/Users/houor/practices/CLionProjects/data-structure/linked-queue/linkedqueue.c.o.requires

.PHONY : CMakeFiles/adjacency_matrix_graph.dir/requires

CMakeFiles/adjacency_matrix_graph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/adjacency_matrix_graph.dir/cmake_clean.cmake
.PHONY : CMakeFiles/adjacency_matrix_graph.dir/clean

CMakeFiles/adjacency_matrix_graph.dir/depend:
	cd /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/cmake-build-debug /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/cmake-build-debug /Users/houor/practices/CLionProjects/data-structure/adjacency-matrix-graph/cmake-build-debug/CMakeFiles/adjacency_matrix_graph.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/adjacency_matrix_graph.dir/depend

