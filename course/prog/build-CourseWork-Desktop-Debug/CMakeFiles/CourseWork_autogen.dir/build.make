# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/max/c/bmstu_cg_course_project/bmstu_cg_course/course/prog/CourseWork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/max/c/bmstu_cg_course_project/bmstu_cg_course/course/prog/build-CourseWork-Desktop-Debug

# Utility rule file for CourseWork_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/CourseWork_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CourseWork_autogen.dir/progress.make

CMakeFiles/CourseWork_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/max/c/bmstu_cg_course_project/bmstu_cg_course/course/prog/build-CourseWork-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target CourseWork"
	/usr/bin/cmake -E cmake_autogen /home/max/c/bmstu_cg_course_project/bmstu_cg_course/course/prog/build-CourseWork-Desktop-Debug/CMakeFiles/CourseWork_autogen.dir/AutogenInfo.json Debug

CourseWork_autogen: CMakeFiles/CourseWork_autogen
CourseWork_autogen: CMakeFiles/CourseWork_autogen.dir/build.make
.PHONY : CourseWork_autogen

# Rule to build all files generated by this target.
CMakeFiles/CourseWork_autogen.dir/build: CourseWork_autogen
.PHONY : CMakeFiles/CourseWork_autogen.dir/build

CMakeFiles/CourseWork_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CourseWork_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CourseWork_autogen.dir/clean

CMakeFiles/CourseWork_autogen.dir/depend:
	cd /home/max/c/bmstu_cg_course_project/bmstu_cg_course/course/prog/build-CourseWork-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/max/c/bmstu_cg_course_project/bmstu_cg_course/course/prog/CourseWork /home/max/c/bmstu_cg_course_project/bmstu_cg_course/course/prog/CourseWork /home/max/c/bmstu_cg_course_project/bmstu_cg_course/course/prog/build-CourseWork-Desktop-Debug /home/max/c/bmstu_cg_course_project/bmstu_cg_course/course/prog/build-CourseWork-Desktop-Debug /home/max/c/bmstu_cg_course_project/bmstu_cg_course/course/prog/build-CourseWork-Desktop-Debug/CMakeFiles/CourseWork_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CourseWork_autogen.dir/depend

