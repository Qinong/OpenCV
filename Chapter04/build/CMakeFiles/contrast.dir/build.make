# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/qinlong/studydata/OpenCV3/src/Chapter04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qinlong/studydata/OpenCV3/src/Chapter04/build

# Include any dependencies generated for this target.
include CMakeFiles/contrast.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/contrast.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/contrast.dir/flags.make

CMakeFiles/contrast.dir/contrast.cpp.o: CMakeFiles/contrast.dir/flags.make
CMakeFiles/contrast.dir/contrast.cpp.o: ../contrast.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qinlong/studydata/OpenCV3/src/Chapter04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/contrast.dir/contrast.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/contrast.dir/contrast.cpp.o -c /home/qinlong/studydata/OpenCV3/src/Chapter04/contrast.cpp

CMakeFiles/contrast.dir/contrast.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/contrast.dir/contrast.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qinlong/studydata/OpenCV3/src/Chapter04/contrast.cpp > CMakeFiles/contrast.dir/contrast.cpp.i

CMakeFiles/contrast.dir/contrast.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/contrast.dir/contrast.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qinlong/studydata/OpenCV3/src/Chapter04/contrast.cpp -o CMakeFiles/contrast.dir/contrast.cpp.s

# Object files for target contrast
contrast_OBJECTS = \
"CMakeFiles/contrast.dir/contrast.cpp.o"

# External object files for target contrast
contrast_EXTERNAL_OBJECTS =

contrast: CMakeFiles/contrast.dir/contrast.cpp.o
contrast: CMakeFiles/contrast.dir/build.make
contrast: /usr/local/lib/libopencv_dnn.so.3.4.5
contrast: /usr/local/lib/libopencv_ml.so.3.4.5
contrast: /usr/local/lib/libopencv_objdetect.so.3.4.5
contrast: /usr/local/lib/libopencv_shape.so.3.4.5
contrast: /usr/local/lib/libopencv_stitching.so.3.4.5
contrast: /usr/local/lib/libopencv_superres.so.3.4.5
contrast: /usr/local/lib/libopencv_videostab.so.3.4.5
contrast: /usr/local/lib/libopencv_calib3d.so.3.4.5
contrast: /usr/local/lib/libopencv_features2d.so.3.4.5
contrast: /usr/local/lib/libopencv_flann.so.3.4.5
contrast: /usr/local/lib/libopencv_highgui.so.3.4.5
contrast: /usr/local/lib/libopencv_photo.so.3.4.5
contrast: /usr/local/lib/libopencv_video.so.3.4.5
contrast: /usr/local/lib/libopencv_videoio.so.3.4.5
contrast: /usr/local/lib/libopencv_imgcodecs.so.3.4.5
contrast: /usr/local/lib/libopencv_imgproc.so.3.4.5
contrast: /usr/local/lib/libopencv_core.so.3.4.5
contrast: CMakeFiles/contrast.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qinlong/studydata/OpenCV3/src/Chapter04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable contrast"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/contrast.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/contrast.dir/build: contrast

.PHONY : CMakeFiles/contrast.dir/build

CMakeFiles/contrast.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/contrast.dir/cmake_clean.cmake
.PHONY : CMakeFiles/contrast.dir/clean

CMakeFiles/contrast.dir/depend:
	cd /home/qinlong/studydata/OpenCV3/src/Chapter04/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qinlong/studydata/OpenCV3/src/Chapter04 /home/qinlong/studydata/OpenCV3/src/Chapter04 /home/qinlong/studydata/OpenCV3/src/Chapter04/build /home/qinlong/studydata/OpenCV3/src/Chapter04/build /home/qinlong/studydata/OpenCV3/src/Chapter04/build/CMakeFiles/contrast.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/contrast.dir/depend

