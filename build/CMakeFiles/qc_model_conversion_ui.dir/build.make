# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/inventec/Documents/Qualcomm/qc_model_conversion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/inventec/Documents/Qualcomm/qc_model_conversion/build

# Include any dependencies generated for this target.
include CMakeFiles/qc_model_conversion_ui.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/qc_model_conversion_ui.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/qc_model_conversion_ui.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/qc_model_conversion_ui.dir/flags.make

CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.o: CMakeFiles/qc_model_conversion_ui.dir/flags.make
CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.o: qc_model_conversion_ui_autogen/mocs_compilation.cpp
CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.o: CMakeFiles/qc_model_conversion_ui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/inventec/Documents/Qualcomm/qc_model_conversion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.o -MF CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.o -c /home/inventec/Documents/Qualcomm/qc_model_conversion/build/qc_model_conversion_ui_autogen/mocs_compilation.cpp

CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/inventec/Documents/Qualcomm/qc_model_conversion/build/qc_model_conversion_ui_autogen/mocs_compilation.cpp > CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.i

CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/inventec/Documents/Qualcomm/qc_model_conversion/build/qc_model_conversion_ui_autogen/mocs_compilation.cpp -o CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.s

CMakeFiles/qc_model_conversion_ui.dir/main.cpp.o: CMakeFiles/qc_model_conversion_ui.dir/flags.make
CMakeFiles/qc_model_conversion_ui.dir/main.cpp.o: ../main.cpp
CMakeFiles/qc_model_conversion_ui.dir/main.cpp.o: CMakeFiles/qc_model_conversion_ui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/inventec/Documents/Qualcomm/qc_model_conversion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/qc_model_conversion_ui.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qc_model_conversion_ui.dir/main.cpp.o -MF CMakeFiles/qc_model_conversion_ui.dir/main.cpp.o.d -o CMakeFiles/qc_model_conversion_ui.dir/main.cpp.o -c /home/inventec/Documents/Qualcomm/qc_model_conversion/main.cpp

CMakeFiles/qc_model_conversion_ui.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qc_model_conversion_ui.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/inventec/Documents/Qualcomm/qc_model_conversion/main.cpp > CMakeFiles/qc_model_conversion_ui.dir/main.cpp.i

CMakeFiles/qc_model_conversion_ui.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qc_model_conversion_ui.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/inventec/Documents/Qualcomm/qc_model_conversion/main.cpp -o CMakeFiles/qc_model_conversion_ui.dir/main.cpp.s

CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.o: CMakeFiles/qc_model_conversion_ui.dir/flags.make
CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.o: ../mainwindow.cpp
CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.o: CMakeFiles/qc_model_conversion_ui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/inventec/Documents/Qualcomm/qc_model_conversion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.o -MF CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.o.d -o CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.o -c /home/inventec/Documents/Qualcomm/qc_model_conversion/mainwindow.cpp

CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/inventec/Documents/Qualcomm/qc_model_conversion/mainwindow.cpp > CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.i

CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/inventec/Documents/Qualcomm/qc_model_conversion/mainwindow.cpp -o CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.s

# Object files for target qc_model_conversion_ui
qc_model_conversion_ui_OBJECTS = \
"CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/qc_model_conversion_ui.dir/main.cpp.o" \
"CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.o"

# External object files for target qc_model_conversion_ui
qc_model_conversion_ui_EXTERNAL_OBJECTS =

qc_model_conversion_ui: CMakeFiles/qc_model_conversion_ui.dir/qc_model_conversion_ui_autogen/mocs_compilation.cpp.o
qc_model_conversion_ui: CMakeFiles/qc_model_conversion_ui.dir/main.cpp.o
qc_model_conversion_ui: CMakeFiles/qc_model_conversion_ui.dir/mainwindow.cpp.o
qc_model_conversion_ui: CMakeFiles/qc_model_conversion_ui.dir/build.make
qc_model_conversion_ui: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
qc_model_conversion_ui: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
qc_model_conversion_ui: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
qc_model_conversion_ui: CMakeFiles/qc_model_conversion_ui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/inventec/Documents/Qualcomm/qc_model_conversion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable qc_model_conversion_ui"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qc_model_conversion_ui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/qc_model_conversion_ui.dir/build: qc_model_conversion_ui
.PHONY : CMakeFiles/qc_model_conversion_ui.dir/build

CMakeFiles/qc_model_conversion_ui.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/qc_model_conversion_ui.dir/cmake_clean.cmake
.PHONY : CMakeFiles/qc_model_conversion_ui.dir/clean

CMakeFiles/qc_model_conversion_ui.dir/depend:
	cd /home/inventec/Documents/Qualcomm/qc_model_conversion/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/inventec/Documents/Qualcomm/qc_model_conversion /home/inventec/Documents/Qualcomm/qc_model_conversion /home/inventec/Documents/Qualcomm/qc_model_conversion/build /home/inventec/Documents/Qualcomm/qc_model_conversion/build /home/inventec/Documents/Qualcomm/qc_model_conversion/build/CMakeFiles/qc_model_conversion_ui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/qc_model_conversion_ui.dir/depend

