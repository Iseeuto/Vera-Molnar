cmake_minimum_required(VERSION 3.15)

project(projet)

set(SRC     src/test_svg.cpp 
            src/test_draw_simple_object.cpp
            src/file.cpp
            src/test_draw_complex_object.cpp
            src/test_draw_simple_object_html.cpp
            src/test_draw_multiple_object.cpp
            src/test_draw_multiple_object_from_file.cpp
            src/canvas.cpp
            src/test_draw_none_canvas.cpp
            src/transformation.cpp
)

set(HEADER  src/utils/structures.hpp 
            src/utils/test_svg.hpp 
            src/utils/test_draw_simple_object.hpp
            src/utils/file.hpp
            src/utils/test_draw_complex_object.hpp
            src/utils/canvas.hpp
            src/utils/transformation.hpp
)

set(EXECUTABLE_OUTPUT_PATH ../)

add_executable(veramolnar ${SRC} ${HEADER})