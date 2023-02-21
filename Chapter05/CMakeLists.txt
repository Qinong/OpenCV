# cmake for OpenCV Cookbook 3rd edition chapter 03
# your opencv/build directory should be in your system PATH

# set minimum required version for cmake
cmake_minimum_required(VERSION 2.8)
project(colorDetection)


FIND_PACKAGE(OpenCV)
INCLUDE_DIRECTORIES(${OpenCV})

# add executable
add_executable( colorDetection colorDetection.cpp colordetector.cpp)

# link libraries
target_link_libraries( colorDetection ${OpenCV_LIBS})

# copy required images to every directory with executable
SET (IMAGES ${CMAKE_SOURCE_DIR}/images/Audi_RS7.jpg ${CMAKE_SOURCE_DIR}/images/Audi_logo.jpeg ${CMAKE_SOURCE_DIR}/images/Ferrar_F8.png)
FILE(COPY ${IMAGES} DESTINATION .)
FILE(COPY ${IMAGES} DESTINATION "Debug")
FILE(COPY ${IMAGES} DESTINATION "Release")
