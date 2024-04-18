#include<iostream>
#include "utils/transformation.hpp"
#include "utils/canvas.hpp"
#include "utils/test_svg.hpp"
#include "utils/file.hpp"
#include "utils/test_draw_complex_object.hpp"

using namespace std;

// A mettre dans test.txt
// Polygone 4 0.0 200.0 200.200 0.200 grey
// Polygone 4 40.40 160.40 160.160 40.160 black
// Polygone 4 80.80 120.80 120.120 80.120 white
// Polygone 4 120.120 80.120 80.80 120.80 blue

// int main(){

//     Canvas C;
//     C.width = 600; C.height = 400;
//     C.Rep_col = 3; C.Rep_lig = 2;
    
//     C.FC = file_to_composedObject("test.txt");

//     string colorList[6] = {"purple", "blue", "green", "red", "orange", "yellow"};

//     listTransformComposed LTC;
//     LTC.N = 4;
//     LTC.l = new listTransform[LTC.N];

//     string final = "<svg width=\"" + to_string(C.width) + "\" height=\"" + to_string(C.height) + "\">";
//     int space_x = C.width/C.Rep_col, space_y = C.height/C.Rep_lig;

//     for(int y=0; y<C.Rep_lig; y++){
//         for(int x=0; x<C.Rep_col; x++){
//             LTC.l[3].t.color = colorList[y*3 + x];
//             int rand = alea(0, C.FC.nbFormes-1);
//             LTC.l[rand].t.angle = 45;
//             LTC.l[rand].t.size = 0.9;
//             FormeComplexe copie;
//             copy_complex_object(C.FC, &copie);
//             translate_composedObject(&copie, x*space_x, y*space_y);
//             for(int i=0; i<C.FC.nbFormes; i++){
//                 Forme temp;
//                 copy_simple_object(copie.formes[i], &temp);
//                 transform_simple_object(&temp, LTC.l[i].t, findCenterComplexObject(copie));
//                 final += simpleObject_to_svg(temp);
//             }
//             for(int i=0; i<LTC.N; i++){
//                 LTC.l[i].t.angle = 0;
//                 LTC.l[i].t.size = 1;
//             }
//         }
//     }
//     final += "</svg>";

//     svg_to_html("test.html", final);

//     return 1;
// }