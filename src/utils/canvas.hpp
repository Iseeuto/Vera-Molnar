#include<iostream>
#include "structures.hpp"
#include "transformation.hpp"

#ifndef CANVAS_HPP
#define CANVAS_HPP

int alea(int a, int b);

void translate_object(Forme *F, int _x, int _y);

void translate_composedObject(FormeComplexe *FC, int _x, int _y);

string canvas_composed_to_svg(Canvas C);

string canvas_transform_composed_to_svg(Canvas C);

string canvas_list_transform_simpleObject_to_svg(FormeComplexe FC, Forme F, Transformations T[], int N);

string canvas_to_svg_veramolnar(Canvas C, listTransformComposed LTC);

string canvas_to_svg_veramolnar_good(Canvas C, listTransformComposed LTC);

#endif