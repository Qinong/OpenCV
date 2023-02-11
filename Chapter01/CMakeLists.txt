# your opencv/build directory should be in your system PATH
# set minimum required version for cmake
cmake_minimum_required(VERSION 2.8)
project(mat)

FIND_PACKAGE(OpenCV)
INCLUDE_DIRECTORIES(${OpenCV})

# add executable
add_executable( mat mat.cpp)

# link libraries
target_link_libraries( mat ${OpenCV_LIBS})

# copy required images to every directory with executable
SET (${CMAKE_SOURCE_DIR}/images/Audi_S7.jpg)
FILE(COPY ${IMAGES} DESTINATION .)
FILE(COPY ${IMAGES} DESTINATION "Debug")
FILE(COPY ${IMAGES} DESTINATION "Release")
