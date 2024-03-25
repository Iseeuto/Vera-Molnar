#include<iostream>
#include "structures.hpp"

#ifndef T_D_SIMPLE_OBJ_HPP
#define T_D_SIMPLE_OBJ_HPP

void init_circle(Forme *C, Point centre, int rayon, string color);

void init_polygon(Forme *P, int nbPoints, string color);

Forme init_object(Figure type, int nbPoints, Point *tabPoints, string color, int rayon=0);

void afficher_forme(Forme F);

string simpleObject_to_svg(Forme F);

void copy_simple_object(Forme F, Forme* copie);

#endif