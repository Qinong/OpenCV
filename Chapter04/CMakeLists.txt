# cmake for OpenCV Cookbook 3rd edition chapter 02
# your opencv/build directory should be in your system PATH

# set minimum required version for cmake
cmake_minimum_required(VERSION 2.8)
project(addImages)
project(remapping)
project(setadd)

FIND_PACKAGE(OpenCV)
INCLUDE_DIRECTORIES(${OpenCV})

# add executable
add_executable( addImages addImages.cpp)
add_executable( remapping remapping.cpp)
add_executable( setadd setadd.cpp)


# link libraries
target_link_libraries( addImages ${OpenCV_LIBS})
target_link_libraries( remapping ${OpenCV_LIBS})
target_link_libraries( setadd ${OpenCV_LIBS})


# copy required images to every directory with executable
SET (IMAGES ${CMAKE_SOURCE_DIR}/images/AUdi_A8.jpg ${CMAKE_SOURCE_DIR}/images/huang.jpg)
FILE(COPY ${IMAGES} DESTINATION .)
FILE(COPY ${IMAGES} DESTINATION "Debug")
FILE(COPY ${IMAGES} DESTINATION "Release")

