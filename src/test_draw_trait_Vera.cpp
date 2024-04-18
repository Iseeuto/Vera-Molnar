#include<iostream>
#include "utils/structures.hpp"
#include "utils/canvas.hpp"
#include "utils/file.hpp"
#include "utils/test_svg.hpp"
#include "utils/test_draw_complex_object.hpp"

using namespace std;

// int main(){

//     Canvas C;
//     C.width = 800; C.height = 800;
//     C.Rep_col = 20; C.Rep_lig = 20;
    
//     C.FC = file_to_composedObject("test.txt");

//     string final = "<svg width=\"" + to_string(C.width) + "\" height=\"" + to_string(C.height) + "\">";
//     int space_x = C.width/C.Rep_col, space_y = C.height/C.Rep_lig;

//     for(int y=0; y<C.Rep_lig; y++){
//         for(int x=0; x<C.Rep_col; x++){
//             FormeComplexe copie;
//             copy_complex_object(C.FC, &copie);
//             translate_composedObject(&copie, x*space_x, y*space_y);
//             Forme temp;
//             copy_simple_object(copie.formes[0], &temp);
//             Transformations T[1] = {Rotate};
//             final += canvas_list_transform_simpleObject_to_svg(copie, temp, T, 1);


//         }
//     }
//     final += "</svg>";

//     svg_to_html("test.html", final);

//     return 1;
// }