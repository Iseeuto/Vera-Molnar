cmake_minimum_required(VERSION 3.15)

project(projet)

set(SRC     src/test_svg.cpp 
            src/test_draw_simple_object.cpp
            src/file.cpp
)

set(HEADER  src/utils/structures.hpp 
            src/utils/test_svg.hpp 
            src/utils/test_draw_simple_object.hpp
            src/utils/file.hpp
)

set(EXECUTABLE_OUTPUT_PATH ../)

add_executable(veramolnar ${SRC} ${HEADER})