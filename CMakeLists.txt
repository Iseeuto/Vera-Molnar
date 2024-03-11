cmake_minimum_required(VERSION 3.15)

project(projet)

set(SRC    src/test_svg.cpp)
set(HEADER src/utils/structures.hpp src/utils/test_svg.hpp)

set(EXECUTABLE_OUTPUT_PATH ../)

add_executable(veramolnar ${SRC} ${HEADER})