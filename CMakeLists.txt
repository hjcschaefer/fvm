CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(FINITE_ELEMENTS)

ENABLE_TESTING()
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src/main/cpp)
SET(CMAKE_BUILD_TYPE DEBUG)

ADD_SUBDIRECTORY(src/main/cpp/fvm)
ADD_SUBDIRECTORY(src/test/cpp/fvm)


