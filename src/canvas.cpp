#include<iostream>
#include<random>
#include "utils/canvas.hpp"
#include "utils/complex_object.hpp"
#include "utils/svg.hpp"
#include "utils/transformation.hpp"


using namespace std;

int alea(int a, int b){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(a, b);

    return dist(rng);
}

void translate_object(Forme *F, int _x, int _y){
    for(int i=0; i<F->Nb_Pts; i++){
        F->p[i].x += _x;
        F->p[i].y += _y;
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

            rotate_objectComplexe(&(C.FC), 45);
            dilate_ComposedObject(&(C.FC), 1);

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

string canvas_list_transform_simpleObject_to_svg(FormeComplexe FC, Forme F, Transformations T[], int N){

    string colors[6] = {"purple", "blue", "red", "green", "yellow", "brown"};

    Forme copie;
    copy_simple_object(F, &copie);

    for(int i=0; i<N; i++){
        switch (T[i])
        {
        case Dilate:
            dilate_object(&copie, alea(0, 3), findCenterComplexObject(FC));
            break;
        
        case Rotate:
            rotate_object(&copie, alea(1,360), findCenterComplexObject(FC));
            break;

        case ChangeColor:
            colorChange_object(&copie, colors[alea(0,5)]);
            break;
        }
    }

    if(F.type == Cercle){
        return circle_to_svg(copie.p[0], copie.rayon, copie.color);
    }
    return polygon_to_svg(copie.Nb_Pts, copie.p, copie.color);
}

string canvas_to_svg_veramolnar(Canvas C, listTransformComposed LTC){
    string final = "<svg width=\"" + to_string(C.width) + "\" height=\"" + to_string(C.height) + "\">";

    int space_x = C.width/C.Rep_col, space_y = C.height/C.Rep_lig;

    for(int y=0; y<C.Rep_lig; y++){
        for(int x=0; x<C.Rep_col; x++){
            FormeComplexe temp;
            copy_complex_object(C.FC, &temp);
            translate_composedObject(&temp, x*space_x, y*space_y);
            for(int i=0; i<temp.nbFormes; i++){
                transform_complex_simple_object(&(temp.formes[i]), LTC.l[i], findCenterComplexObject(temp));
                if(temp.formes[i].type == Cercle){
                    final += circle_to_svg(temp.formes[i].p[0], temp.formes[i].rayon, temp.formes[i].color);
                }else{
                    final += polygon_to_svg(temp.formes[i].Nb_Pts, temp.formes[i].p, temp.formes[i].color);
                }
            }
        }
    }
    final += "</svg>";
    return final;
}
