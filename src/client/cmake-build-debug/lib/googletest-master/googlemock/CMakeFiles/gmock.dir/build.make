# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/yarin/Downloads/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/yarin/Downloads/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug"

# Include any dependencies generated for this target.
include lib/googletest-master/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include lib/googletest-master/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include lib/googletest-master/googlemock/CMakeFiles/gmock.dir/flags.make

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/flags.make
lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o: ../lib/googletest-master/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o"
	cd "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/lib/googletest-master/googlemock" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o -c "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/lib/googletest-master/googletest/src/gtest-all.cc"

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i"
	cd "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/lib/googletest-master/googlemock" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/lib/googletest-master/googletest/src/gtest-all.cc" > CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s"
	cd "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/lib/googletest-master/googlemock" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/lib/googletest-master/googletest/src/gtest-all.cc" -o CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires:

.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires
	$(MAKE) -f lib/googletest-master/googlemock/CMakeFiles/gmock.dir/build.make lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides.build
.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides.build: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o


lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/flags.make
lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../lib/googletest-master/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/lib/googletest-master/googlemock" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/lib/googletest-master/googlemock/src/gmock-all.cc"

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/lib/googletest-master/googlemock" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/lib/googletest-master/googlemock/src/gmock-all.cc" > CMakeFiles/gmock.dir/src/gmock-all.cc.i

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/lib/googletest-master/googlemock" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/lib/googletest-master/googlemock/src/gmock-all.cc" -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires:

.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires
	$(MAKE) -f lib/googletest-master/googlemock/CMakeFiles/gmock.dir/build.make lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build
.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o


# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o" \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/googletest-master/googlemock/libgmockd.a: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o
lib/googletest-master/googlemock/libgmockd.a: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
lib/googletest-master/googlemock/libgmockd.a: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/build.make
lib/googletest-master/googlemock/libgmockd.a: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libgmockd.a"
	cd "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/lib/googletest-master/googlemock" && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/lib/googletest-master/googlemock" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/googletest-master/googlemock/CMakeFiles/gmock.dir/build: lib/googletest-master/googlemock/libgmockd.a

.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/build

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/requires: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires
lib/googletest-master/googlemock/CMakeFiles/gmock.dir/requires: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/requires

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/clean:
	cd "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/lib/googletest-master/googlemock" && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/clean

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/depend:
	cd "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client" "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/lib/googletest-master/googlemock" "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug" "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/lib/googletest-master/googlemock" "/home/yarin/CLionProjects/program adventure/reversiProject/Reversi/src/client/cmake-build-debug/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/depend

