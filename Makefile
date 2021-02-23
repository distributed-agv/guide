# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sijinze/Desktop/guide

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sijinze/Desktop/guide

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.17.2/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.17.2/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.17.2/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.17.2/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.17.2/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.17.2/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target package_source
package_source:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool for source..."
	/usr/local/Cellar/cmake/3.17.2/bin/cpack --config ./CPackSourceConfig.cmake /Users/sijinze/Desktop/guide/CPackSourceConfig.cmake
.PHONY : package_source

# Special rule for the target package_source
package_source/fast: package_source

.PHONY : package_source/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.17.2/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.17.2/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target package
package: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool..."
	/usr/local/Cellar/cmake/3.17.2/bin/cpack --config ./CPackConfig.cmake
.PHONY : package

# Special rule for the target package
package/fast: package

.PHONY : package/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/sijinze/Desktop/guide/CMakeFiles /Users/sijinze/Desktop/guide/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/sijinze/Desktop/guide/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named guidepy

# Build rule for target.
guidepy: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 guidepy
.PHONY : guidepy

# fast build rule for target.
guidepy/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/guidepy.dir/build.make CMakeFiles/guidepy.dir/build
.PHONY : guidepy/fast

#=============================================================================
# Target rules for targets named hiredis

# Build rule for target.
hiredis: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 hiredis
.PHONY : hiredis

# fast build rule for target.
hiredis/fast:
	$(MAKE) $(MAKESILENT) -f hiredis/CMakeFiles/hiredis.dir/build.make hiredis/CMakeFiles/hiredis.dir/build
.PHONY : hiredis/fast

#=============================================================================
# Target rules for targets named hiredis-test

# Build rule for target.
hiredis-test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 hiredis-test
.PHONY : hiredis-test

# fast build rule for target.
hiredis-test/fast:
	$(MAKE) $(MAKESILENT) -f hiredis/CMakeFiles/hiredis-test.dir/build.make hiredis/CMakeFiles/hiredis-test.dir/build
.PHONY : hiredis-test/fast

#=============================================================================
# Target rules for targets named hiredis_static

# Build rule for target.
hiredis_static: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 hiredis_static
.PHONY : hiredis_static

# fast build rule for target.
hiredis_static/fast:
	$(MAKE) $(MAKESILENT) -f hiredis/CMakeFiles/hiredis_static.dir/build.make hiredis/CMakeFiles/hiredis_static.dir/build
.PHONY : hiredis_static/fast

Astar.o: Astar.cc.o

.PHONY : Astar.o

# target to build an object file
Astar.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/guidepy.dir/build.make CMakeFiles/guidepy.dir/Astar.cc.o
.PHONY : Astar.cc.o

Astar.i: Astar.cc.i

.PHONY : Astar.i

# target to preprocess a source file
Astar.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/guidepy.dir/build.make CMakeFiles/guidepy.dir/Astar.cc.i
.PHONY : Astar.cc.i

Astar.s: Astar.cc.s

.PHONY : Astar.s

# target to generate assembly for a file
Astar.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/guidepy.dir/build.make CMakeFiles/guidepy.dir/Astar.cc.s
.PHONY : Astar.cc.s

guide.o: guide.cc.o

.PHONY : guide.o

# target to build an object file
guide.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/guidepy.dir/build.make CMakeFiles/guidepy.dir/guide.cc.o
.PHONY : guide.cc.o

guide.i: guide.cc.i

.PHONY : guide.i

# target to preprocess a source file
guide.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/guidepy.dir/build.make CMakeFiles/guidepy.dir/guide.cc.i
.PHONY : guide.cc.i

guide.s: guide.cc.s

.PHONY : guide.s

# target to generate assembly for a file
guide.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/guidepy.dir/build.make CMakeFiles/guidepy.dir/guide.cc.s
.PHONY : guide.cc.s

guidepy.o: guidepy.cc.o

.PHONY : guidepy.o

# target to build an object file
guidepy.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/guidepy.dir/build.make CMakeFiles/guidepy.dir/guidepy.cc.o
.PHONY : guidepy.cc.o

guidepy.i: guidepy.cc.i

.PHONY : guidepy.i

# target to preprocess a source file
guidepy.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/guidepy.dir/build.make CMakeFiles/guidepy.dir/guidepy.cc.i
.PHONY : guidepy.cc.i

guidepy.s: guidepy.cc.s

.PHONY : guidepy.s

# target to generate assembly for a file
guidepy.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/guidepy.dir/build.make CMakeFiles/guidepy.dir/guidepy.cc.s
.PHONY : guidepy.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... package"
	@echo "... package_source"
	@echo "... rebuild_cache"
	@echo "... guidepy"
	@echo "... hiredis"
	@echo "... hiredis-test"
	@echo "... hiredis_static"
	@echo "... Astar.o"
	@echo "... Astar.i"
	@echo "... Astar.s"
	@echo "... guide.o"
	@echo "... guide.i"
	@echo "... guide.s"
	@echo "... guidepy.o"
	@echo "... guidepy.i"
	@echo "... guidepy.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

