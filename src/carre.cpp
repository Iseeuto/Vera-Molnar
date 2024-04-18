#include<iostream>
#include "utils/transformation.hpp"
#include "utils/canvas.hpp"
#include "utils/test_svg.hpp"
#include "utils/file.hpp"
#include "utils/test_draw_complex_object.hpp"

using namespace std;

// A mettre dans test.txt
// Polygone 4 0.0 40.0 40.40 0.40 grey
// Polygone 4 5.5 35.5 35.35 5.35 black
// Polygone 4 10.10 30.10 30.30 10.30 white
// Polygone 4 15.15 25.15 25.25 15.25 blue

// int main(){

//     Canvas C;
//     C.width = 120; C.height = 80;
//     C.Rep_col = 3; C.Rep_lig = 2;
    
//     C.FC = file_to_composedObject("test.txt");

//     string colorList[6] = {"purple", "blue", "green", "red", "orange", "yellow"};

//     listTransformComposed LTC;
//     LTC.N = 4;
//     LTC.l = new listTransform[LTC.N];
//     LTC.l[3].t.color = "";


//     string final = "<svg width=\"" + to_string(C.width) + "\" height=\"" + to_string(C.height) + "\">";
//     int space_x = C.width/C.Rep_col, space_y = C.height/C.Rep_lig;

//     for(int y=0; y<C.Rep_lig; y++){
//         for(int x=0; x<C.Rep_col; x++){
//             LTC.l[3].t.color = colorList[y*3 + x];
//             FormeComplexe copie;
//             copy_complex_object(C.FC, &copie);
//             translate_composedObject(&copie, x*space_x, y*space_y);
//             for(int i=0; i<C.FC.nbFormes; i++){
//                 Forme temp;
//                 copy_simple_object(copie.formes[i], &temp);
//                 transform_simple_object(&temp, LTC.l[i].t, findCenterComplexObject(copie));
//                 final += simpleObject_to_svg(temp);
//             }
//         }
//     }
//     final += "</svg>";

//     svg_to_html("test.html", final);

//     return 1;
// }