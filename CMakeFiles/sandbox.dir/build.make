# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kartikeygupta/Workspace/nes-emulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kartikeygupta/Workspace/nes-emulator

# Include any dependencies generated for this target.
include CMakeFiles/sandbox.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sandbox.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sandbox.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sandbox.dir/flags.make

CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.o: CMakeFiles/sandbox.dir/flags.make
CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.o: nes-emulator/sandbox.cpp
CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.o: CMakeFiles/sandbox.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/kartikeygupta/Workspace/nes-emulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.o -MF CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.o.d -o CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.o -c /Users/kartikeygupta/Workspace/nes-emulator/nes-emulator/sandbox.cpp

CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kartikeygupta/Workspace/nes-emulator/nes-emulator/sandbox.cpp > CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.i

CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kartikeygupta/Workspace/nes-emulator/nes-emulator/sandbox.cpp -o CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.s

# Object files for target sandbox
sandbox_OBJECTS = \
"CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.o"

# External object files for target sandbox
sandbox_EXTERNAL_OBJECTS =

sandbox: CMakeFiles/sandbox.dir/nes-emulator/sandbox.cpp.o
sandbox: CMakeFiles/sandbox.dir/build.make
sandbox: external/spdlog/libspdlog.a
sandbox: CMakeFiles/sandbox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/kartikeygupta/Workspace/nes-emulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sandbox"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sandbox.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sandbox.dir/build: sandbox
.PHONY : CMakeFiles/sandbox.dir/build

CMakeFiles/sandbox.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sandbox.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sandbox.dir/clean

CMakeFiles/sandbox.dir/depend:
	cd /Users/kartikeygupta/Workspace/nes-emulator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kartikeygupta/Workspace/nes-emulator /Users/kartikeygupta/Workspace/nes-emulator /Users/kartikeygupta/Workspace/nes-emulator /Users/kartikeygupta/Workspace/nes-emulator /Users/kartikeygupta/Workspace/nes-emulator/CMakeFiles/sandbox.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sandbox.dir/depend

