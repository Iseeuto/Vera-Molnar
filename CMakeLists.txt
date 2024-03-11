cmake_minimum_required(VERSION 3.15)

project(projet)

set(SRC    src/main.cpp)
set(HEADER src/utils/structures.hpp)

add_executable(veramolnar ${SRC} ${HEADER})