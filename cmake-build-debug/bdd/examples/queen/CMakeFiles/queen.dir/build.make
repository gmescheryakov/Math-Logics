# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Programming\ClionProjects\Math-Logics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Programming\ClionProjects\Math-Logics\cmake-build-debug

# Include any dependencies generated for this target.
include bdd/examples/queen/CMakeFiles/queen.dir/depend.make

# Include the progress variables for this target.
include bdd/examples/queen/CMakeFiles/queen.dir/progress.make

# Include the compile flags for this target's objects.
include bdd/examples/queen/CMakeFiles/queen.dir/flags.make

bdd/examples/queen/CMakeFiles/queen.dir/queen.cxx.obj: bdd/examples/queen/CMakeFiles/queen.dir/flags.make
bdd/examples/queen/CMakeFiles/queen.dir/queen.cxx.obj: bdd/examples/queen/CMakeFiles/queen.dir/includes_CXX.rsp
bdd/examples/queen/CMakeFiles/queen.dir/queen.cxx.obj: ../external/buddy/examples/queen/queen.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programming\ClionProjects\Math-Logics\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bdd/examples/queen/CMakeFiles/queen.dir/queen.cxx.obj"
	cd /d D:\Programming\ClionProjects\Math-Logics\cmake-build-debug\bdd\examples\queen && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\queen.dir\queen.cxx.obj -c D:\Programming\ClionProjects\Math-Logics\external\buddy\examples\queen\queen.cxx

bdd/examples/queen/CMakeFiles/queen.dir/queen.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queen.dir/queen.cxx.i"
	cd /d D:\Programming\ClionProjects\Math-Logics\cmake-build-debug\bdd\examples\queen && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programming\ClionProjects\Math-Logics\external\buddy\examples\queen\queen.cxx > CMakeFiles\queen.dir\queen.cxx.i

bdd/examples/queen/CMakeFiles/queen.dir/queen.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queen.dir/queen.cxx.s"
	cd /d D:\Programming\ClionProjects\Math-Logics\cmake-build-debug\bdd\examples\queen && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programming\ClionProjects\Math-Logics\external\buddy\examples\queen\queen.cxx -o CMakeFiles\queen.dir\queen.cxx.s

# Object files for target queen
queen_OBJECTS = \
"CMakeFiles/queen.dir/queen.cxx.obj"

# External object files for target queen
queen_EXTERNAL_OBJECTS =

bdd/examples/queen/queen.exe: bdd/examples/queen/CMakeFiles/queen.dir/queen.cxx.obj
bdd/examples/queen/queen.exe: bdd/examples/queen/CMakeFiles/queen.dir/build.make
bdd/examples/queen/queen.exe: bdd/src/libbdd.a
bdd/examples/queen/queen.exe: bdd/examples/queen/CMakeFiles/queen.dir/linklibs.rsp
bdd/examples/queen/queen.exe: bdd/examples/queen/CMakeFiles/queen.dir/objects1.rsp
bdd/examples/queen/queen.exe: bdd/examples/queen/CMakeFiles/queen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Programming\ClionProjects\Math-Logics\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable queen.exe"
	cd /d D:\Programming\ClionProjects\Math-Logics\cmake-build-debug\bdd\examples\queen && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\queen.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bdd/examples/queen/CMakeFiles/queen.dir/build: bdd/examples/queen/queen.exe

.PHONY : bdd/examples/queen/CMakeFiles/queen.dir/build

bdd/examples/queen/CMakeFiles/queen.dir/clean:
	cd /d D:\Programming\ClionProjects\Math-Logics\cmake-build-debug\bdd\examples\queen && $(CMAKE_COMMAND) -P CMakeFiles\queen.dir\cmake_clean.cmake
.PHONY : bdd/examples/queen/CMakeFiles/queen.dir/clean

bdd/examples/queen/CMakeFiles/queen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Programming\ClionProjects\Math-Logics D:\Programming\ClionProjects\Math-Logics\external\buddy\examples\queen D:\Programming\ClionProjects\Math-Logics\cmake-build-debug D:\Programming\ClionProjects\Math-Logics\cmake-build-debug\bdd\examples\queen D:\Programming\ClionProjects\Math-Logics\cmake-build-debug\bdd\examples\queen\CMakeFiles\queen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : bdd/examples/queen/CMakeFiles/queen.dir/depend

