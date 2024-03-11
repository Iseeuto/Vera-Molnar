cmake_minimum_required(VERSION 3.0)

project(projet)

set(SRC main.cpp)
set(HEADER header.hpp)

add_executable(executable ${SRC} ${HEADER})