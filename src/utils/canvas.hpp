#include<iostream>
#include "structures.hpp"

#ifndef CANVAS_HPP
#define CANVAS_HPP

struct Canvas{
    int width, height;
    FormeComplexe FC;
    int Rep_col, Rep_lig;
};

void translate_object(Forme *F, int _x, int _y);

void translate_composedObject(FormeComplexe *FC, int _x, int _y);

string canvas_composed_to_svg(Canvas C);

#endif