#include<iostream>
#include "utils/canvas.hpp"
#include "utils/test_draw_complex_object.hpp"
#include "utils/test_svg.hpp"
#include "utils/transformation.hpp"

using namespace std;

void translate_object(Forme *F, int _x, int _y){
    if(F->type == Cercle){
        F->p[0].x += _x;
        F->p[0].y += _y;
    }
    else if(F->type == Polygone){
        for(int i=0; i<F->Nb_Pts; i++){
            F->p[i].x += _x;
            F->p[i].y += _y;
        }
    }
}

void translate_composedObject(FormeComplexe *FC, int _x, int _y){
    for(int i=0; i<FC->nbFormes; i++){
        translate_object(&(FC->formes[i]), _x, _y);
    }
}

string canvas_composed_to_svg(Canvas C){
    string final = "<svg width=\"" + to_string(C.width) + "\" height=\"" + to_string(C.height) + "\">";

    int space_x = C.width/C.Rep_col, space_y = C.height/C.Rep_lig;

    for(int y=0; y<C.Rep_lig; y++){
        for(int x=0; x<C.Rep_col; x++){
            FormeComplexe temp;
            copy_complex_object(C.FC, &temp);
            translate_composedObject(&temp, x*space_x, y*space_y);
            for(int i=0; i<temp.nbFormes; i++){
                if(temp.formes[i].type == Cercle){
                    final += circle_to_svg(temp.formes[i].p[0], temp.formes[i].rayon, temp.formes[i].color);
                } 
                else if(temp.formes[i].type == Polygone){
                    final += polygon_to_svg(temp.formes[i].Nb_Pts, temp.formes[i].p, temp.formes[i].color);
                }
            }
        }
    }
    final += "</svg>";
    return final;
}

string canvas_transform_composed_to_svg(Canvas C){
    string final = "<svg width=\"" + to_string(C.width) + "\" height=\"" + to_string(C.height) + "\">";

    int space_x = C.width/C.Rep_col, space_y = C.height/C.Rep_lig;

    for(int y=0; y<C.Rep_lig; y++){
        for(int x=0; x<C.Rep_col; x++){
            FormeComplexe temp;
            copy_complex_object(C.FC, &temp);
            translate_composedObject(&temp, x*space_x, y*space_y);

            rotate_objectComplexe(&temp, 2*(x+(C.Rep_col*y)));

            for(int i=0; i<temp.nbFormes; i++){
                if(temp.formes[i].type == Cercle){
                    final += circle_to_svg(temp.formes[i].p[0], temp.formes[i].rayon, temp.formes[i].color);
                } 
                else if(temp.formes[i].type == Polygone){
                    final += polygon_to_svg(temp.formes[i].Nb_Pts, temp.formes[i].p, temp.formes[i].color);
                }
            }
        }
    }
    final += "</svg>";
    return final;
}

