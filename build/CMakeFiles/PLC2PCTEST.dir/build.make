# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\github\gtk3.0\gtk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\github\gtk3.0\gtk\build

# Include any dependencies generated for this target.
include CMakeFiles/PLC2PCTEST.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PLC2PCTEST.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PLC2PCTEST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PLC2PCTEST.dir/flags.make

CMakeFiles/PLC2PCTEST.dir/test.c.obj: CMakeFiles/PLC2PCTEST.dir/flags.make
CMakeFiles/PLC2PCTEST.dir/test.c.obj: CMakeFiles/PLC2PCTEST.dir/includes_C.rsp
CMakeFiles/PLC2PCTEST.dir/test.c.obj: ../test.c
CMakeFiles/PLC2PCTEST.dir/test.c.obj: CMakeFiles/PLC2PCTEST.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\gtk3.0\gtk\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PLC2PCTEST.dir/test.c.obj"
	D:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PLC2PCTEST.dir/test.c.obj -MF CMakeFiles\PLC2PCTEST.dir\test.c.obj.d -o CMakeFiles\PLC2PCTEST.dir\test.c.obj -c D:\github\gtk3.0\gtk\test.c

CMakeFiles/PLC2PCTEST.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PLC2PCTEST.dir/test.c.i"
	D:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\github\gtk3.0\gtk\test.c > CMakeFiles\PLC2PCTEST.dir\test.c.i

CMakeFiles/PLC2PCTEST.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PLC2PCTEST.dir/test.c.s"
	D:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\github\gtk3.0\gtk\test.c -o CMakeFiles\PLC2PCTEST.dir\test.c.s

CMakeFiles/PLC2PCTEST.dir/mylog.c.obj: CMakeFiles/PLC2PCTEST.dir/flags.make
CMakeFiles/PLC2PCTEST.dir/mylog.c.obj: CMakeFiles/PLC2PCTEST.dir/includes_C.rsp
CMakeFiles/PLC2PCTEST.dir/mylog.c.obj: ../mylog.c
CMakeFiles/PLC2PCTEST.dir/mylog.c.obj: CMakeFiles/PLC2PCTEST.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\gtk3.0\gtk\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/PLC2PCTEST.dir/mylog.c.obj"
	D:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PLC2PCTEST.dir/mylog.c.obj -MF CMakeFiles\PLC2PCTEST.dir\mylog.c.obj.d -o CMakeFiles\PLC2PCTEST.dir\mylog.c.obj -c D:\github\gtk3.0\gtk\mylog.c

CMakeFiles/PLC2PCTEST.dir/mylog.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PLC2PCTEST.dir/mylog.c.i"
	D:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\github\gtk3.0\gtk\mylog.c > CMakeFiles\PLC2PCTEST.dir\mylog.c.i

CMakeFiles/PLC2PCTEST.dir/mylog.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PLC2PCTEST.dir/mylog.c.s"
	D:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\github\gtk3.0\gtk\mylog.c -o CMakeFiles\PLC2PCTEST.dir\mylog.c.s

CMakeFiles/PLC2PCTEST.dir/mymalloc/mymalloc.c.obj: CMakeFiles/PLC2PCTEST.dir/flags.make
CMakeFiles/PLC2PCTEST.dir/mymalloc/mymalloc.c.obj: CMakeFiles/PLC2PCTEST.dir/includes_C.rsp
CMakeFiles/PLC2PCTEST.dir/mymalloc/mymalloc.c.obj: ../mymalloc/mymalloc.c
CMakeFiles/PLC2PCTEST.dir/mymalloc/mymalloc.c.obj: CMakeFiles/PLC2PCTEST.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\gtk3.0\gtk\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/PLC2PCTEST.dir/mymalloc/mymalloc.c.obj"
	D:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PLC2PCTEST.dir/mymalloc/mymalloc.c.obj -MF CMakeFiles\PLC2PCTEST.dir\mymalloc\mymalloc.c.obj.d -o CMakeFiles\PLC2PCTEST.dir\mymalloc\mymalloc.c.obj -c D:\github\gtk3.0\gtk\mymalloc\mymalloc.c

CMakeFiles/PLC2PCTEST.dir/mymalloc/mymalloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PLC2PCTEST.dir/mymalloc/mymalloc.c.i"
	D:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\github\gtk3.0\gtk\mymalloc\mymalloc.c > CMakeFiles\PLC2PCTEST.dir\mymalloc\mymalloc.c.i

CMakeFiles/PLC2PCTEST.dir/mymalloc/mymalloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PLC2PCTEST.dir/mymalloc/mymalloc.c.s"
	D:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\github\gtk3.0\gtk\mymalloc\mymalloc.c -o CMakeFiles\PLC2PCTEST.dir\mymalloc\mymalloc.c.s

CMakeFiles/PLC2PCTEST.dir/myobject/myobject.c.obj: CMakeFiles/PLC2PCTEST.dir/flags.make
CMakeFiles/PLC2PCTEST.dir/myobject/myobject.c.obj: CMakeFiles/PLC2PCTEST.dir/includes_C.rsp
CMakeFiles/PLC2PCTEST.dir/myobject/myobject.c.obj: ../myobject/myobject.c
CMakeFiles/PLC2PCTEST.dir/myobject/myobject.c.obj: CMakeFiles/PLC2PCTEST.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\gtk3.0\gtk\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/PLC2PCTEST.dir/myobject/myobject.c.obj"
	D:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PLC2PCTEST.dir/myobject/myobject.c.obj -MF CMakeFiles\PLC2PCTEST.dir\myobject\myobject.c.obj.d -o CMakeFiles\PLC2PCTEST.dir\myobject\myobject.c.obj -c D:\github\gtk3.0\gtk\myobject\myobject.c

CMakeFiles/PLC2PCTEST.dir/myobject/myobject.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PLC2PCTEST.dir/myobject/myobject.c.i"
	D:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\github\gtk3.0\gtk\myobject\myobject.c > CMakeFiles\PLC2PCTEST.dir\myobject\myobject.c.i

CMakeFiles/PLC2PCTEST.dir/myobject/myobject.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PLC2PCTEST.dir/myobject/myobject.c.s"
	D:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\github\gtk3.0\gtk\myobject\myobject.c -o CMakeFiles\PLC2PCTEST.dir\myobject\myobject.c.s

# Object files for target PLC2PCTEST
PLC2PCTEST_OBJECTS = \
"CMakeFiles/PLC2PCTEST.dir/test.c.obj" \
"CMakeFiles/PLC2PCTEST.dir/mylog.c.obj" \
"CMakeFiles/PLC2PCTEST.dir/mymalloc/mymalloc.c.obj" \
"CMakeFiles/PLC2PCTEST.dir/myobject/myobject.c.obj"

# External object files for target PLC2PCTEST
PLC2PCTEST_EXTERNAL_OBJECTS =

PLC2PCTEST.exe: CMakeFiles/PLC2PCTEST.dir/test.c.obj
PLC2PCTEST.exe: CMakeFiles/PLC2PCTEST.dir/mylog.c.obj
PLC2PCTEST.exe: CMakeFiles/PLC2PCTEST.dir/mymalloc/mymalloc.c.obj
PLC2PCTEST.exe: CMakeFiles/PLC2PCTEST.dir/myobject/myobject.c.obj
PLC2PCTEST.exe: CMakeFiles/PLC2PCTEST.dir/build.make
PLC2PCTEST.exe: D:/msys64/mingw64/lib/libgsl.dll.a
PLC2PCTEST.exe: D:/msys64/mingw64/lib/libgslcblas.dll.a
PLC2PCTEST.exe: CMakeFiles/PLC2PCTEST.dir/linklibs.rsp
PLC2PCTEST.exe: CMakeFiles/PLC2PCTEST.dir/objects1.rsp
PLC2PCTEST.exe: CMakeFiles/PLC2PCTEST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\github\gtk3.0\gtk\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable PLC2PCTEST.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PLC2PCTEST.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PLC2PCTEST.dir/build: PLC2PCTEST.exe
.PHONY : CMakeFiles/PLC2PCTEST.dir/build

CMakeFiles/PLC2PCTEST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PLC2PCTEST.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PLC2PCTEST.dir/clean

CMakeFiles/PLC2PCTEST.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\github\gtk3.0\gtk D:\github\gtk3.0\gtk D:\github\gtk3.0\gtk\build D:\github\gtk3.0\gtk\build D:\github\gtk3.0\gtk\build\CMakeFiles\PLC2PCTEST.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PLC2PCTEST.dir/depend

