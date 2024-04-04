#include<iostream>
#include "utils/canvas.hpp"
#include "utils/file.hpp"
#include "fstream"
#include "utils/test_draw_simple_object.hpp"
#include "utils/test_svg.hpp"
#include "utils/transformation.hpp"

using namespace std;

int main(){
    FormeComplexe FC;

    FC = file_to_composedObject("rectangle.txt");

    canvas_to_file_complex(800, 800, &FC, FC.nbFormes, "test.html");

    rotate_objectComplexe(&FC,45);

    canvas_to_file_complex(800, 800, &FC, FC.nbFormes, "test2.html");

    
    return 1;
}