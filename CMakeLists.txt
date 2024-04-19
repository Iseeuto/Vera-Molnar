cmake_minimum_required(VERSION 3.15)

project(projet)

set(VERA    src/svg.cpp
            src/file.cpp
            src/complex_object.cpp
            src/simple_object.cpp
            src/canvas.cpp
            src/transformation.cpp
            src/veramolnar.cpp
)

set(TEST_COMPLEX_OBJECT    src/svg.cpp
            src/file.cpp
            src/complex_object.cpp
            src/simple_object.cpp
            src/canvas.cpp
            src/transformation.cpp
            src/test_draw_complex_object.cpp
)

set(TEST_DRAW_MULTIPLE_OBJECT_FILE   src/svg.cpp
            src/file.cpp
            src/complex_object.cpp
            src/simple_object.cpp
            src/canvas.cpp
            src/transformation.cpp
            src/test_draw_multiple_object_from_file.cpp
)

set(TEST_DRAW_MULTIPLE_OBJECT    src/svg.cpp
            src/file.cpp
            src/complex_object.cpp
            src/simple_object.cpp
            src/canvas.cpp
            src/transformation.cpp
            src/test_draw_multiple_object.cpp
)

set(NONE_CANVAS    src/svg.cpp
            src/file.cpp
            src/complex_object.cpp
            src/simple_object.cpp
            src/canvas.cpp
            src/transformation.cpp
            src/test_draw_none_canvas.cpp
)

set(TEST_SIMPLE_OBJECT    src/svg.cpp
            src/file.cpp
            src/complex_object.cpp
            src/simple_object.cpp
            src/canvas.cpp
            src/transformation.cpp
            src/test_draw_simple_object.cpp
)

set(TEST_SIMPLE_OBJECT_HTML    src/svg.cpp
            src/file.cpp
            src/complex_object.cpp
            src/simple_object.cpp
            src/canvas.cpp
            src/transformation.cpp
            src/test_draw_simple_object_html.cpp
)

set(TRAIT_VERA    src/svg.cpp
            src/file.cpp
            src/complex_object.cpp
            src/simple_object.cpp
            src/canvas.cpp
            src/transformation.cpp
            src/test_draw_trait_Vera.cpp
)

set(FILE_TO_TRANSFORM    src/svg.cpp
            src/file.cpp
            src/complex_object.cpp
            src/simple_object.cpp
            src/canvas.cpp
            src/transformation.cpp
            src/test_file_to_transform.cpp
)

set(TEST_SVG    src/svg.cpp
            src/file.cpp
            src/complex_object.cpp
            src/simple_object.cpp
            src/canvas.cpp
            src/transformation.cpp
            src/test_svg.cpp
)

set(HEADER  src/utils/structures.hpp 
            src/utils/svg.hpp 
            src/utils/simple_object.hpp
            src/utils/file.hpp
            src/utils/complex_object.hpp
            src/utils/canvas.hpp
            src/utils/transformation.hpp
)

set(EXECUTABLE_OUTPUT_PATH ../)

add_executable(veramolnar ${VERA} ${HEADER})
add_executable(test_draw_complex_object ${TEST_COMPLEX_OBJECT} ${HEADER})
add_executable(test_draw_multiple_object_from_file ${TEST_DRAW_MULTIPLE_OBJECT_FILE} ${HEADER})
add_executable(test_draw_multiple_object ${TEST_DRAW_MULTIPLE_OBJECT} ${HEADER})
add_executable(test_draw_none_canvas ${NONE_CANVAS} ${HEADER})
add_executable(test_draw_simple_object ${TEST_SIMPLE_OBJECT} ${HEADER})
add_executable(test_draw_simple_object_html ${TEST_SIMPLE_OBJECT_HTML} ${HEADER})
add_executable(test_draw_trait_vera ${TRAIT_VERA} ${HEADER})
add_executable(test_file_to_transform ${FILE_TO_TRANSFORM} ${HEADER})
add_executable(test_svg ${TEST_SVG} ${HEADER})