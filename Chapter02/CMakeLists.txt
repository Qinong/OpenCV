# set minimum required version for cmake
cmake_minimum_required(VERSION 2.8)
project(draw)

FIND_PACKAGE(OpenCV)
INCLUDE_DIRECTORIES(${OpenCV})
# add executable
add_executable( draw draw.cpp)

# link libraries
target_link_libraries( draw ${OpenCV_LIBS})

# copy required images to every directory with executable
SET (IMAGES ${CMAKE_SOURCE_DIR}/images/Audi_RS7.jpg ${CMAKE_SOURCE_DIR}/images/Audi_logo.jpeg)
FILE(COPY ${IMAGES} DESTINATION .)
FILE(COPY ${IMAGES} DESTINATION "Debug")
FILE(COPY ${IMAGES} DESTINATION "Release")
