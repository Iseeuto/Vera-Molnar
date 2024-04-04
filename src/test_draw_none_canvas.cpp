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

    FC = file_to_composedObject("test.txt");

    canvas_to_file_complex(800, 800, &FC, FC.nbFormes, "test.html");

    Point P = findCenterComplexObject(FC);

    return 1;
}