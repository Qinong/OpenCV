# cmake for OpenCV Cookbook 3rd edition chapter 02
# your opencv/build directory should be in your system PATH

# set minimum required version for cmake
cmake_minimum_required(VERSION 2.8)
project(noise)
project(scan)

FIND_PACKAGE(OpenCV)
INCLUDE_DIRECTORIES(${OpenCV})

# add executable
add_executable( noise noise.cpp)
add_executable( scan scan.cpp)

# link libraries
target_link_libraries( noise ${OpenCV_LIBS})
target_link_libraries( scan ${OpenCV_LIBS})

# copy required images to every directory with executable
SET (IMAGES ${CMAKE_SOURCE_DIR}/images/Audi_RS7.jpg ${CMAKE_SOURCE_DIR}/images/Audi_logo.jpeg ${CMAKE_SOURCE_DIR}/images/Ferrar_F8.png)
FILE(COPY ${IMAGES} DESTINATION .)
FILE(COPY ${IMAGES} DESTINATION "Debug")
FILE(COPY ${IMAGES} DESTINATION "Release")

