# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Projects\ZepelinGraphics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Projects\ZepelinGraphics

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	"C:\Program Files\CMake\bin\cmake-gui.exe" -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\CMake\bin\cmake.exe" --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start E:\Projects\ZepelinGraphics\CMakeFiles E:\Projects\ZepelinGraphics\\CMakeFiles\progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start E:\Projects\ZepelinGraphics\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ZepelinGraphics

# Build rule for target.
ZepelinGraphics: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ZepelinGraphics
.PHONY : ZepelinGraphics

# fast build rule for target.
ZepelinGraphics/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/build
.PHONY : ZepelinGraphics/fast

src/Zepelin.obj: src/Zepelin.c.obj

.PHONY : src/Zepelin.obj

# target to build an object file
src/Zepelin.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/Zepelin.c.obj
.PHONY : src/Zepelin.c.obj

src/Zepelin.i: src/Zepelin.c.i

.PHONY : src/Zepelin.i

# target to preprocess a source file
src/Zepelin.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/Zepelin.c.i
.PHONY : src/Zepelin.c.i

src/Zepelin.s: src/Zepelin.c.s

.PHONY : src/Zepelin.s

# target to generate assembly for a file
src/Zepelin.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/Zepelin.c.s
.PHONY : src/Zepelin.c.s

src/input.obj: src/input.c.obj

.PHONY : src/input.obj

# target to build an object file
src/input.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/input.c.obj
.PHONY : src/input.c.obj

src/input.i: src/input.c.i

.PHONY : src/input.i

# target to preprocess a source file
src/input.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/input.c.i
.PHONY : src/input.c.i

src/input.s: src/input.c.s

.PHONY : src/input.s

# target to generate assembly for a file
src/input.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/input.c.s
.PHONY : src/input.c.s

src/main.obj: src/main.c.obj

.PHONY : src/main.obj

# target to build an object file
src/main.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/main.c.obj
.PHONY : src/main.c.obj

src/main.i: src/main.c.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/main.c.s
.PHONY : src/main.c.s

src/statemachine.obj: src/statemachine.c.obj

.PHONY : src/statemachine.obj

# target to build an object file
src/statemachine.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/statemachine.c.obj
.PHONY : src/statemachine.c.obj

src/statemachine.i: src/statemachine.c.i

.PHONY : src/statemachine.i

# target to preprocess a source file
src/statemachine.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/statemachine.c.i
.PHONY : src/statemachine.c.i

src/statemachine.s: src/statemachine.c.s

.PHONY : src/statemachine.s

# target to generate assembly for a file
src/statemachine.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/statemachine.c.s
.PHONY : src/statemachine.c.s

src/surface.obj: src/surface.c.obj

.PHONY : src/surface.obj

# target to build an object file
src/surface.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/surface.c.obj
.PHONY : src/surface.c.obj

src/surface.i: src/surface.c.i

.PHONY : src/surface.i

# target to preprocess a source file
src/surface.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/surface.c.i
.PHONY : src/surface.c.i

src/surface.s: src/surface.c.s

.PHONY : src/surface.s

# target to generate assembly for a file
src/surface.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/surface.c.s
.PHONY : src/surface.c.s

src/texture.obj: src/texture.c.obj

.PHONY : src/texture.obj

# target to build an object file
src/texture.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/texture.c.obj
.PHONY : src/texture.c.obj

src/texture.i: src/texture.c.i

.PHONY : src/texture.i

# target to preprocess a source file
src/texture.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/texture.c.i
.PHONY : src/texture.c.i

src/texture.s: src/texture.c.s

.PHONY : src/texture.s

# target to generate assembly for a file
src/texture.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/texture.c.s
.PHONY : src/texture.c.s

src/vec4.obj: src/vec4.c.obj

.PHONY : src/vec4.obj

# target to build an object file
src/vec4.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/vec4.c.obj
.PHONY : src/vec4.c.obj

src/vec4.i: src/vec4.c.i

.PHONY : src/vec4.i

# target to preprocess a source file
src/vec4.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/vec4.c.i
.PHONY : src/vec4.c.i

src/vec4.s: src/vec4.c.s

.PHONY : src/vec4.s

# target to generate assembly for a file
src/vec4.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/vec4.c.s
.PHONY : src/vec4.c.s

src/window.obj: src/window.c.obj

.PHONY : src/window.obj

# target to build an object file
src/window.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/window.c.obj
.PHONY : src/window.c.obj

src/window.i: src/window.c.i

.PHONY : src/window.i

# target to preprocess a source file
src/window.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/window.c.i
.PHONY : src/window.c.i

src/window.s: src/window.c.s

.PHONY : src/window.s

# target to generate assembly for a file
src/window.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ZepelinGraphics.dir\build.make CMakeFiles/ZepelinGraphics.dir/src/window.c.s
.PHONY : src/window.c.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... edit_cache
	@echo ... rebuild_cache
	@echo ... ZepelinGraphics
	@echo ... src/Zepelin.obj
	@echo ... src/Zepelin.i
	@echo ... src/Zepelin.s
	@echo ... src/input.obj
	@echo ... src/input.i
	@echo ... src/input.s
	@echo ... src/main.obj
	@echo ... src/main.i
	@echo ... src/main.s
	@echo ... src/statemachine.obj
	@echo ... src/statemachine.i
	@echo ... src/statemachine.s
	@echo ... src/surface.obj
	@echo ... src/surface.i
	@echo ... src/surface.s
	@echo ... src/texture.obj
	@echo ... src/texture.i
	@echo ... src/texture.s
	@echo ... src/vec4.obj
	@echo ... src/vec4.i
	@echo ... src/vec4.s
	@echo ... src/window.obj
	@echo ... src/window.i
	@echo ... src/window.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system

