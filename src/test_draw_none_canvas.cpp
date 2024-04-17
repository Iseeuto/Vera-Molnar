#include<iostream>
#include "utils/canvas.hpp"
#include "utils/file.hpp"
#include "fstream"
#include "utils/test_draw_simple_object.hpp"
#include "utils/test_svg.hpp"
#include "utils/transformation.hpp"

using namespace std;

// int main(){
//     Canvas C;
//     C.FC = file_to_composedObject("test.txt");
//     C.height = 745; C.width = 1300;
//     C.Rep_col = 17; C.Rep_lig = 10;

//     svg_to_html("test.html", canvas_transform_composed_to_svg(C));

//     return 1;
// }